#include<iostream>
#include<set>
using namespace std;
class test{
    int a;
    int b;
    public:
    int geta(){
        return a;
    }
    void seta(int a){
        this->a=a;
    }
    void printfa(){
        std::cout <<"a="<<a<<endl;
    }
    void setall(int *aa){
        *aa=a;
    }
    int *returna(){
        return &a;
    }
};

int main(){
    set<int> set;
    test t;
    int* bb;
    int c;
    bb=t.returna();
    *bb=1000;
    t.setall(&c);
    t.printfa();
    std::cout <<"c=="<<c<<endl;
    std::cout<<"我复活"<<endl;
    return 0;
}