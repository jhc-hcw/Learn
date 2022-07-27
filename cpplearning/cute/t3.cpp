#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
class stack{
    struct node{
        T data;
        struct node *next;
    };
    struct node* D;
    public:
    stack(){
        D=NULL;
    }
    bool isEmpty(){
        if(this->D==NULL){
            return true;
        }else{
            return false;
        }
    }
    T get_top(){
        if(!this->isEmpty()){
            return D->data;
        }else{
            return NULL;
        }
    }
    void push(T x){
        node *p=new node();
        p->data=x;
        p->next=D;
        D=p;
    }
    void pop(){
        if(!this->isEmpty()){
            node* p=D;
            D=D->next;
            delete(p);
        }else{
            return ;
        }
    }

};

static const int maxlen = 500;
template<typename T>
struct queue {
    int front;
    int rear;
    int length;
    T data[maxlen];
    queue() :front(0), rear(0), length(0) {
    }
    bool isEmpty() {
        if (front == rear) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull() {
        if ((rear + 1) % maxlen == front) {
            return true;
        }
        else {
            return false;
        }
    }
    void add(T x) {
        if (!isFull()) {
            rear = (rear + 1) % maxlen;
            data[rear] = x;
            length++;
        }
        else {
            cout << "满了" << endl;
        }
    }
    void Delete() {
        if (isEmpty()) {
            cout << "空空如也" << endl;
            length--;
        }
        else {
            front = (front + 1) % maxlen;
        }
    }
};


int main(){
    ifstream f;
    f.open("english.txt");
    string s;
    cout<<"有以下回文：";
    while(!f.eof()){
        f>>s;
        string::iterator iter=s.end();
        iter--;
        if( !((*(iter)>='A' && *(iter)<='Z') || (*(iter)>='a' && *(iter)<='z')) ){
            s.erase(iter);
        }
        string t(s);
        string p = "";
        stack<char> st;
        int leng = s.length();
        for (int i = 0; i < leng / 2; i++)
        {
            st.push(s.at(0));
            s.erase(s.begin());
        }
        if (leng % 2 == 0)
        {
            for (int i = 0; i < leng / 2; i++)
            {
                p.push_back(st.get_top());
                st.pop();
            }
            if (s == p)
            {
                cout << t<<" ";
            }
        }
        else
        {
            s.erase(s.begin());
            for (int i = 0; i < leng / 2; i++)
            {
                p.push_back(st.get_top());
                st.pop();
            }
            if (s == p)
            {
                cout << t<<" ";
            }
        }
        
    }
    f.close();
    return 0;
}