#include<stdio.h>
#include<malloc.h>
typedef struct Pnode{
    int coef;
    int exp;
    struct Pnode* next;
}Polynode;

Polynode *R; // 暂存指针，在具体函数里才有意义，不能不赋值直接引用

void Plprint(Polynode *H){
    if(H==NULL){
        printf("空空如也！");
        return;
    }
    R=H;
    while(1){
        if(R->next!=NULL){
            printf("%d*X^%d+",R->coef,R->exp);
            R=R->next;
        }else{
            printf("%d*X^%d\n",R->coef,R->exp);
            break;
        }
    }
    return;
}
void Polclean(Polynode *a){
    R=a;
    Polynode *temp;
    while(R!=NULL){
        if(R->coef==0){
            if(R->next!=NULL){
                Polynode* del=R->next;
                R->coef=del->coef;
                R->exp=del->exp;
                R->next=del->next;
                free(del);
            }else{
                Polynode* del=R;
                free(del);
            }
        }
    }

}
void polcopy(Polynode * a,Polynode* b){
    a->coef=b->coef;
    a->exp=b->exp;
    R=b->next;
    for(;R!=NULL;R=R->next){
        Polynode* temp=(Polynode*)malloc(sizeof(Polynode));
        temp->coef=R->coef;
        temp->exp=R->exp;
        temp->next=NULL;
        R->next=temp;
        R=temp;
    }
}

int Plinit(Polynode *H){
    R=H;
    int coef,exp,flag;
    int sum=0;
    printf("输入扣非0继续输入:");
    scanf("%d",&flag);if(R->coef==0){
                    Polynode* del;
                    del=R->next;
                    R->coef=R->next->coef;
                    R->exp=R->next->exp;
                    R->next=R->next->next;
                    free(del);
                }
    while(flag){
        printf("请输入系数与指数：");
        scanf("%d %d",&coef,&exp);
        R->next=(Polynode*)malloc(sizeof(Polynode));
        R->next->coef=coef;
        R->next->exp=exp;
        R->next->next=NULL;
        R=R->next;
        sum++;
        printf("输入扣非0继续输入:");
        scanf("%d",&flag);
    }
    return sum;
}

Polynode* Polyplus(Polynode * a,Polynode* b){
    // 传入第一个元素，不是头指针！
    //返回也是一个数据第一元素，不是头指针！
    Polynode* result=(Polynode*)malloc(sizeof(Polynode));
    polcopy(result,a);
    R=result;
    Polynode* pr=result;
    Polynode* la=b;
    result->coef=a->coef;
    result->exp=a->exp;
    result->next=NULL;
    if(a==NULL || b==NULL){
        printf("那毫无意义！");
        return NULL;
    }
    for(;la!=NULL;la=la->next){
        pr=result;
        for(;pr!=NULL;pr=pr->next){
            if(la->exp<pr->exp){
                Polynode* temp=(Polynode*)malloc(sizeof(Polynode));
                temp->coef=pr->coef;
                temp->exp=pr->exp;
                temp->next=R->next;
                R->coef=la->coef;
                R->exp=la->exp;
                R->next=temp;
                continue;
            }else if(la->exp==pr->exp){
                R->coef=la->coef+pr->coef;
                continue;
            }else if(la->exp>pr->exp){
                if(pr->next==NULL){
                    Polynode* temp=(Polynode*)malloc(sizeof(Polynode));
                    temp->coef=la->coef;
                    temp->exp=la->exp;
                    temp->next=NULL;
                    R->next=temp;
                    R=temp;
                }
                continue;
            }
        }
    }
    return result;
}

int main(){
    Polynode *pre=(Polynode*)malloc(sizeof(Polynode));
    Polynode *la=(Polynode*)malloc(sizeof(Polynode));
    // pre->coef=0;
    // pre->exp=0;
    // pre->next=NULL;
    printf("请输入第一个多项式\n");
    Plinit(pre);
    printf("请输入第二个多项式\n");
    Plinit(la);
    Plprint(pre->next);
    Plprint(la->next);
    printf("合并计算中-----------\n");
    Plprint(Polyplus(pre->next,la->next));
    return 1;
}