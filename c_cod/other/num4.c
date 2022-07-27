#include<stdio.h>

int main(){
    int a[]={16,15,14,13,12,11,10,9,2,1,2,1};
    int i=0;
    int k=0;        //表示该大于或等于
    if(a[0]>a[1]){  //改变K状态，正确进入判断条件！！
        k=1;
    }
    printf("(");
    while(i<11){
        if(a[i]<a[i+1]&&k==0){  //这是常态，直接打印i本身即可
            printf("%d,",a[i]);
        }else if(a[i]<a[i+1]&&k==1){    //这是非常态，是从升阶转换而来
            k=0;
            printf("%d),",a[i]);
            printf("(%d,",a[i]);
        }
        
        if(a[i]>a[i+1]&&k==1){
            printf("%d,",a[i]);
        }else if(a[i]>a[i+1]&&k==0){
            k=1;
            printf("%d),",a[i]);
            printf("(%d,",a[i]);
        }
        i++;
        if(i==11){
            printf("%d)\n",a[i]);
        }
    }
    return 0;
}