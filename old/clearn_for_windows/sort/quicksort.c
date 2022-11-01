#include<stdio.h>


int partition(int *data,int left,int right){
    int low,high,x;
    x=data[left];
    low = left;
    high = right;
    while(low<high){
        while(data[high]>x){
            high--;
        }
        if(low<high){
            data[low]=data[high];
            low++;
        }
        while(data[low]<x && low<high){
            low++;
        }
        if(low<high){
            data[high]=data[low];
            high--;
        }
    }
    data[low]=x;
    return low;
}
void quicksort(int *data,int low,int high){
    int mid;
    if(low<high){
        mid=partition(data,low,high);
        quicksort(data,low,mid-1);
        quicksort(data,mid+1,high);
    }
}

int main(){
    int a[]={5,4,3,2,1};
    long l=sizeof(a)/sizeof(int);
    quicksort(a,0,l-1);
    for(int i=0;i<l;i++){
        printf("%d,",a[i]);
    }
    return 0;
}