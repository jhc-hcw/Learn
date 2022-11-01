#include<iostream>
using namespace std;
#include<memory>
class cc{
    int i;
    public:
    cc():i(1){};
    cc(const cc &s){
        i=1+s.i;
    };
    ~cc(){
        cout<<"cc我死了"<<endl;
    }
    int get_i(){
        return i;
    }
    cc& operator= (cc &c){
        i=1+c.i;
        return  *this;
    }
};

class A{
    public:
    cc c;

    
    A()=default;

    ~A(){
        cout<<"a我死了"<<endl;
    }
};

class BB{
    public:
    cc c;
    BB(){};
    ~BB(){};

};
#include<vector>
int main(){
    cc c;
    A a;
    BB b;
    a.c=c;
    weak_ptr<int> wr;
    return 0;
}