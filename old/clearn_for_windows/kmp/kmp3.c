#include<stdio.h>
#include<string.h>
#include<malloc.h>

void nextstr(char *s,int *a,int l){
    int k=-1,j=0;  //k保存前后缀字符相等个数和前缀步进位置，可能要回溯    j是整个字符串的步进位置不回回溯，一直往后。
    a[0]=-1;  //-1符合前后缀判断语义又设计的极其巧妙   规定字符串第一个字母的前后缀最大长度为-1,因为第一个字母前面没有字母，没的比较
    a[1]=0;    //第二个字符前缀与后缀都是第一个字符，不算做长度，或者意为后缀为空，  注意，第n个保存的是前面字符第1到第n-1字符最大前后缀长度，不包括第n个
    while(j<l){
        if(k==-1 || s[k]==s[j] ){  //判断相等就两个步进都加，k=-1时则代表前缀长度为1（即第一个字符自己跟自己后面匹配开始的时候）而且已经判断过不相等，所以直接进行步进。       
            k++;
            j++;
            if(k==0)
                a[j]=k;
            else
                a[j]=k+1;   //根据定义，如果找到前后缀长度了，就把长度保存在数组后一个位置。
        }else{
            k=a[k];
            //全算法最秀语句，也是最难懂的
            //其实就是看作自己跟自己进行匹配，因为j和k的步进都指向匹配字符自己。
            //如果在向后寻找的过程中发现了一部分与前缀相同的子字符串，然后后续判断字符不相等的时候，就看K是要回溯多少，参照已经算好的a数组中的信息进行回溯。
            //一般是不需要回溯的，但如果在后缀子串中还有前缀存在，那么就需要回溯特定位数，以免向后继续算算漏了算少了。
        }
    }
    
}
//kmp算法主要思想在我看来就一个，处理特殊字符串，就是自己长得跟自己很像的字符串，匹配的时候需要准确步进，例如象abc这种”独特“的字符串，ab匹配c不匹配时，直接就步进三个了，无需a再跟b
//比较。直接拿a比较c后一个字符。
int kmp(char *s,char *ss){
    int k=-1,j=-1,ll=strlen(ss),l=strlen(s);
    int a[l];
    nextstr(s,a,l);
    while(k<l && j<ll){
        if(k==-1 || s[k]==ss[j]){            //成功匹配唯一条件，完成这个循环，让k等于匹配字符串长度。
            j++;k++;                        //其他其他情况，则根据匹配字符自己与自己的相似度进行快速准确步进，
        }else{
            k=a[k];
            if(k>0){
                j++;
            }                   //万一出现一个字符匹配不相同时，查询自身匹配的表，看看是否与要步进到与自身相似的部位。如果不需要k=0，就代表无需匹配字符前缀无匹配字符后缀对齐
        }                            //从主字符串j处，与匹配字符开头重新匹配。
    }
    if(k==l){
            printf("位置在%d\n",j-l+1);   //成功条件就是k把匹配字符取完了，并且都在主串找到了。
            return j-l+1;
        }else{
            printf("找不到\n");
            return -1;
        }
}


int strl(char *s){
    int len=0;
    while(s[len]!='\0') len++;  //一一遍历字符，遍历一个长度加一，到'\0'结束遍历。
    return len;
}

char *scapitals(char *s,int t){  //t为控制转化目标0为大写，1为小写
    int l=strl(s),i=0,k=l-1;
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    if(t==0){
        while(s[i]!='\0'){          
            if(s[i]>='a' && s[i]<='z'){   //遍历所有字符，小写字符ascll码全减32
                res[i]=s[i]-32;
            }
                i++;
            }
    }else if(t==1){
        while(s[i]!='\0'){
            if(s[i]>='A' && s[i]<='C'){     //遍历所有字符，大写字符ascll码全加32 
                res[i]=s[i]+32;
            }
                i++;
            }
    }else{
        return NULL;
    }
    return res;
}

char* streverse(char *s){
    int l=strl(s),i=0,k=l-1;
    char *res=malloc(sizeof(char)*(l+1));   //申请相同长度的一个字符串
    while(i<l){
        res[i]=s[k];       //倒着读原字符串，并初始化新字符串
        i++;
        k--;
    }
    res[l]='\0';
    return res;
}

char* substr(char *s,int a,int b){                 
    int l=b-a+2,i=0,j=a;
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(i=0;j<=b;i++,j++)
        res[i]=s[j];
    return res;
}

char *streplace(char *s,char a,char b){   //单个字符替换将字符串s中的a字符替换为b字符
    int l=strl(s);
    int i;
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(i=0;i<l;i++){
        if(s[i]==a)
            res[i]=b;
        else
            res[i]=s[i];
    }
    return res;
}

char *RNAtransform(char *s){   //RNA的转录根据A对U，C对G进行替换。
    int l=strl(s);
    int i;
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(i=0;i<l;i++){
        if(s[i]=='A'){
            res[i]='U';
            continue;
        }
        else if(s[i]=='U'){
            res[i]='A';
            continue;
        }
        else if(s[i]=='C'){
            res[i]='G';
            continue;
        }
        else if(s[i]=='G'){
            res[i]='C';
        }
    }
    return res;
}

void virusmach(){
    char *virus=malloc(sizeof(char)*100);
    char *rna=malloc(sizeof(char)*100);
    printf("请输入rna序列：");
    gets(rna);                 //键盘输入宿主RNA
    printf("请输入病毒rna序列：");
    gets(virus);                  //键盘输入病毒序列
    virus=scapitals(virus,0);      //将RNA序列转为大写 
    rna=scapitals(rna,0);
    printf("直接找寻中%s\n",virus);
    kmp(virus,rna);               //直接进行匹配
    virus=streverse(virus);       //将病毒RNA倒序
    printf("倒序找寻中%s\n",virus);
    kmp(virus,rna);         
    virus=RNAtransform(virus);      //将倒序的病毒RNA转录
    printf("转录倒序找寻中%s\n",virus);
    kmp(virus,rna);
    virus=streverse(virus);        //将倒序转录的病毒RNA变顺序转录
    printf("转录找寻中%s\n",virus);
    kmp(virus,rna);
}

int main(){
    virusmach();
    return 0;
}