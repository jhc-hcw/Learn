#include<iostream>
using namespace std;
static const int maxlen=500;
template<typename T>
struct queue{
    int front;
    int rear;
    int length;
    T data[maxlen];
    queue():front(0),rear(0),length(0){
    }
    bool isEmpty(){
        if(front==rear){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if((rear+1)%maxlen==front){
            return true;
        }else{
            return false;
        }
    }
    void add(T x){
        if(!isFull()){
            rear=(rear+1)%maxlen;
            data[rear]=x;
            length++;
        }else{
            cout<<"满了"<<endl;
        }
    }
    void Delete(){
        if(isEmpty()){
            cout<<"删除失败"<<endl;
            length--;
        }else{
            front=(front+1)%maxlen;
        }
    }
};
void countyh(int f){
    queue<int> q;
    int ff=1;
    while(ff<=f){
        int a=1;
        int count=q.length-ff+2;
        while(a<=ff){
            if(a==1||a==ff){
                q.add(1);
            }else{
                int x=q.data[count]+q.data[count+1];
                q.add(x);
                count++;
            }
            a++;
        }
        ff++;
    }
    int p=1;
    int t=f-1;
    int k=q.front+1;
    while(p<=f){
        for(int i=0;i<t;i++){
            cout<<"\t";
        }
        for(int i=1;i<=p;i++){
            cout<<q.data[k]<<"\t\t";
            k++;
        }
        cout<<endl;
        p++;
        t--;
    }
}

int main(){
    int a;
    cout<<"请输入要打印的行数：";
    cin>>a;
    countyh(a);
    return 0;
}
