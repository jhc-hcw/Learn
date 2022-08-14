#include<iostream>
using namespace std;

void qsort(int *data,int len,int s=0){
	auto par=[data](int low,int high)->int {
		int res=data[low];
		while(low<high){
			while(data[high]>res){
				high--;
			}
			if(low<high){
				data[low]=data[high];
				low++;
			}
			while(data[low]<res){
				low++;
			}
			if(low<high){
				data[high]=data[low];
				high--;
			}
		}
		data[low]=res;
		return low;
	}
}
