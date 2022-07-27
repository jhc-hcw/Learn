#include<stdio.h>
#include<malloc.h>
void merg(int *r,int *rs,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(r[i]<=r[j]){
            rs[k]=r[i];
            i++;
        }else{
            rs[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<=mid) rs[k++]=r[i++];
    while(j<=high) rs[k++]=r[j++];
}
void merg_pass(int *r,int *rs,int len,int l){
    int i,j;
    i=0;
    while(i+len*2<l){
        merg(r,rs,i,i+len-1,i+len*2-1);
        i=i+len*2;
    }
    if(i+len-1<l-1) merg(r,rs,i,i+len-1,l-1);
    else for(j=i;j<l;j++) rs[j]=r[j];   
}

void merg_sort(int *r,int l){
    int *rs=malloc(sizeof(int)*l);
    int i=1;
    while(i<=l/2+1){
        merg_pass(r,rs,i,l);
        i=i*2;
        merg_pass(rs,r,i,l);
        i=i*2;
    }
    free(rs);
}
int main(){
    int data[]={38,65,97,76,13,27,49};
    int l=sizeof(data)/sizeof(int);
    merg_sort(data,l);
    for(int i=0;i<l;i++){
        printf("%d,",data[i]);
    }
    return 0;
}