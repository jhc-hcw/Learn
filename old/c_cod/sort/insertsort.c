#include <stdio.h>



void insertsort(int *L,int l){
    int t;
    int i,j;
    for(i=1;i<l;i++){
        t=L[i];
        j=i-1;
        while(t<L[j]){
            L[j+1]=L[j];
            j--;
        }
        L[j+1]=t;
    }
}
int main(){
    int a[]={500,600,700,344,100,1,3,6,7,9,11,23,34,45,56,67,89,94};
    long l=sizeof(a)/sizeof(int);
    insertsort(a,l);
    for(int i=0;i<l;i++){
        printf("%d,",a[i]);
    }
    return 0;
}