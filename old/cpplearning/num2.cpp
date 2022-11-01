#include<iostream>
using namespace std;

class A{
    float x,y;
    public:
        float &getx(){
            return x;
        }
        void set(float a,float b){
            x=a;y=b;
        }
        void print(){
            cout<<x<<"\t"<<y<<endl;
        }
};

void swit(int *a,int *b){
    int *t;
    t=a;
    a=b;
    b=t;
    cout<<*a<<"  "<<*b;
}

int main(){
    int x=12;int y=49;
    cout<<x<<y;
    swit(&x,&y);
    cout<<x<<"  "<<y;
    // int weak=1;
    // switch(weak){
    //     case 1:cout<<"sdkfj1"<<endl;
    //     case 2:cout<<"sdkfj2"<<endl;
    //     case 3:cout<<"sdkfj3"<<endl;
    //     case 4:cout<<"sdkfj4"<<endl;
    //     case 5:cout<<"sdkfj5"<<endl;
    //     case 6:cout<<"sdkfj6"<<endl;
    //     case 7:cout<<"sdkfj7"<<endl;
    // }
    return 0;
}