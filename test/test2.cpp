#include<iostream>
class bb{
    private:
    const int i=3;
    public:
    void bark(){
        std::cout<<i;
    };
};

typedef struct node{
    int a;
}a,*b;
int main(){
    bb  aa;
    b bv;
    bv->a;
    int ee(44);
    aa.bark();
}