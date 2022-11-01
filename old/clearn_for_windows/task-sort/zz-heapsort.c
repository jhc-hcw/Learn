#include<stdio.h>


void sift1(int *data,int k,int l){
    int j=k*2,i=k,t;
    while(j<=l){
        if(j<l && data[j]<data[j+1]){
            j++;
        }
        if(data[i]<data[j]){
            t=data[i];
            data[i]=data[j];
            data[j]=t;
            i=j;j=j*2;
        }else break;
    }
}


void heap_sort(int *data,int l){
    for(int i=l/2;i>=1;i--){
        sift1(data,i,l);
    }
    for(int i=l;i>1;i--){
        int t=data[i];
        data[i]=data[1];
        data[1]=t;
        sift1(data,1,i-1);
    }
}




























void sift(int *data,int k,int l){
    int i=k,j=k*2,t;
    while(j<=l){
        if(j<l && data[j]<data[j+1]){
            j++;
        }
        if(data[k]<data[j]){
            t=data[k];
            data[k]=data[j];
            data[k]=t;
            i=j;j=j*2;
        }else break;
    }
}

void heap_sort(int *data,int l){
    for(int i=l/2;i>=1;i--){
        sift(data,i,l);
    }
    for(int i=l;i>1;i--){
        int t;
        t=data[1];
        data[1]=data[i];
        data[i]=t;
        sift(data,1,i-1);
    }
}



int main(){
    return 0;
}