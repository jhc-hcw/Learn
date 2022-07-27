#include<stdio.h>

int main(){
    int a[]={1,3,2,56,22,34,66,23,99,43,12,44,50};
    int *p[13];
    long **p1[13];
    int i,j,change;
    for(i=0;i<13;i++){
        p[i]=&a[i];
    }
    for(i=0;i<13;i++){
        p1[i]=&p[i];
    }
    for(i=0;i<13;i++){
        printf("%d,",*p[i]);
    }
    printf("\n");
    for(i=0;i<13;i++){
        printf("%d,",**p1[i]);
    }
    for(i=0;i<13 && change;i++){
        change=0;
        for(j=0;j<12;j++){
            if(**p1[j]>**p1[j+1]){
                long temp=p1[j];
                p1[j]=p1[j+1];
                p1[j+1]=temp;
                change=1;
            }
        }
    }
    printf("\n");
    for(i=0;i<13;i++){
        printf("%d,",**p1[i]);
    }
    return 1;
}