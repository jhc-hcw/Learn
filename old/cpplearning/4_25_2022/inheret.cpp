#include<iostream>
using namespace std;
class bease{
    public :
    virtual void purvirfunc()=0;
};
class A:public bease{
    protected:
    int p;
    void prote(){};
    private:
    int pri;
    void prif(){};
    public:
    int pub;
    void pobf(){};
    virtual void vvfunc(){
        cout<<"A virtual"<<endl;
    }
    void purvirfunc(){
        cout<<"pur func"<<endl;
    }
};
class B: public A{
    void privf(){
        cout<<"private B";
    };
    void vvfunc(){
        cout<<"B virtual"<<endl;
    }
    void purvirfunc(){
        ::A::purvirfunc();
        cout<<"pur func for B"<<endl;
    }
};


int main(){
    A *a=new B();
    a->vvfunc();
    a->purvirfunc();
}