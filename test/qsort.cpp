#include<iostream>
using namespace std;

int q_par(int *data,int h,int r){
	int res=data[h];
	while(r>h){
		while(data[r]>res){
			r--;
		}
		if(r>h){
			data[h]=data[r];
			h++;
		}
		while(data[h]<res){
			h++;
		}
		if(r>h){
			data[r]=data[h];
			r--;
		}
	}	
	data[h]=res;
	return h;
}
void qsort(int *data,int len,int s=0){
	int mid;
	if(len>s){
		mid=q_par(data,s,len);
		qsort(data,mid-1,s);
		qsort(data,len,mid+1);
	}
}
int main(){
	int data[]={9,7,6,45,2,2,1,3,45,-43,33,4};
	int len=sizeof(data)/4;
	qsort(data,len-1);
	for(int i=0;i<len;i++)
		cout<<data[i]<<" ";
	cout<<endl;
	
	return 9;
}
