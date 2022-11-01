#include<stdio.h>
#include<malloc.h>

void merge(int *R,int R1,int low,int mid ,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(R[i]<R[j]){
            R1[k]=R[i];
            i++; 
        }else{
            R1[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        R1[k]=R[i];
        k++;i++;
    }
    while(j<=high){
        R1[k]=R[j];
        k++;j++;
    }
}
void merge_pass(int *R,int *R1,int len,int l){
    int i=0,j;
    while(i+len*2<l){
        merge(R,R1,i,i+len-1,i+len*2-1);
        i=i+len*2;
    }
    if(i+len<l-1) merge(R,R1,i,i+len-1,l);
    else for(j=i;j<l;j++) R1[j]=R[j];
}
void merge_sort(int *R,int l){
    int len=1;
    int *R1=malloc(sizeof(int)*l);
    while(len<l/2+1){
        merge_pass(R,R1,len,l);
        len=len*2;
        merge_pass(R1,R,len,l);
        len=len*2;
    }
    free(R1);
}



















void merge1(int *data1,int *data2,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(data1[i]<=data1[j]){
            data2[k]=data1[i];
            i++;
        }else{
            data2[k]=data1[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        data2[k]=data[i];
        k++;
        i++;
    }
    while(j<=high){
        data2[k]=data[j];
        j++;
        i++;
    }
}
void mergepass1(int *data1,int *data2,int len,int l){
    int j,i=0;
    while(i+len<l){
        merge1(data1,data2,i,i+len-1,i+len*2-1);
        i=i+len*2;
    }
    if(i+len-1<l-1) merge1(data1,data2,i,i+len-1,l-1);
    else for(j=i;j<l;j++) data2[j]=data1[j];
}
void merge_sort1(int *data,int l){
    int len=1;
    int *data2=malloc(sizeof(int)*l);
    while(len<=l/2+1){
        mergepass1(data,data2,len);
        len=2*len;
        mergepass1(data2,data,len);
        len=2*len;
    }
    free(data2);
}
int main(){
    return 0;
}