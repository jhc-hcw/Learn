#include<iostream>
#include<cmath>
using namespace std;
class triangle{
    double a,b,c;
    public:
        triangle(double a=0,double b=0,double c=0){
            if(a+b>c && a+c>b && b+c>a){
                this->a=a;this->b=b;this->c=c;}
            else {
                cout<<"麻烦输入正确的三角形！"<<endl;
                this->a=0;this->b=0;this->c=0;}
        }
        void setedge(double a,double b,double c);
        double getA();
        double getB();
        double getC();
        double area();
        double circumference();
        void show();
};
void triangle::setedge(double a,double b,double c){
    this->a=a;this->b=b;this->c=c;
}
double triangle::getA(){return this->a;}
double triangle::getB(){return this->b;}
double triangle::getC(){return this->c;}
double triangle::area(){
    double p=(this->a+this->b+this->c)/2;
    double s=sqrt (p*(p-this->a)*(p-this->b)*(p-this->c));
    return s;
}
double triangle::circumference(){
    return this->a+this->b+this->c;
}
void triangle::show(){
    cout<<"triangle:"<<" a="<<this->a<<" b="<<this->b<<" c="<<this->c<<" circumference="<<circumference()<<" area="<<area()<<endl;
}
int main(){
    triangle t(3,-4,5),t1(3,4,5),t2(5,6,7);
    t.show();
    t1.show();
    t2.show();
    return 0;
}