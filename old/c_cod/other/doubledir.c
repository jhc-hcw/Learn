#include<stdio.h>

int BinSrch(int *L,int l,int k){
    int low=0,high=l,i=0;
    int mid = (high+low) /2;
    while(low<high){
        mid = (high+low) /2;
        if(k==L[mid]){
            i=mid;
            break;
        }else if(k<L[mid]){
            high=mid-1;
        }else if(k>L[mid]){
            low=mid+1;
        }
    }
    return i;
}
int main(){
    int a[]={1,3,6,7,9,11,23,34,45,56,67,89,94};
    printf("%d",BinSrch(a,sizeof(a)/sizeof(int),94));
    return 0;
}