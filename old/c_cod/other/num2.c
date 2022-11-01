#include<stdio.h>
#define MAX_SIZE 10

void sort(int **L[],int len){
    int i,j,change;
    for(i=0;i<len && change;i++){
        change=0;
        for(j=0;j<len-1;j++){
            if(**L[j]>**L[j+1]){
                int** temp=L[j];
                L[j]=L[j+1];
                L[j+1]=temp;
                change=1;
            }
        }
    }
}

int main(){
    int a[MAX_SIZE];
    int len=0;
    int i;
    printf("请输入一组整数：");
    for(i=0;i<MAX_SIZE;i++){
        scanf("%d",&a[i]);
        len++;
    }
    int *p[len];
    int **p1[len];
    for(i=0;i<len;i++){
        p[i]=&a[i];
    }
    for(i=0;i<len;i++){
        p1[i]=&p[i];
    }
    sort(p1,len);
    for(i=0;i<len;i++){
        printf("%d,",**p1[i]);
    }
    return 1;
}