//
// Created by jhc on 2022/5/14.
//

#ifndef TEMPLE_RATIONAL_H
#define TEMPLE_RATIONAL_H

class Rational{
public:
    Rational(int numerator=0,int denominator=1);
    int numerator()const;
    int denominator()const;
    //const Rational operator* (const Rational & rhs) const;
private:
    int numer,demo;
};

int Rational::denominator() const {
    return demo;
}

int Rational::numerator() const {
    return numer;
}
Rational::Rational(int numerator, int denominator) :numer(numerator),demo(denominator){

}

//const Rational Rational::operator*(const Rational &rhs) const {
//    return Rational(this->numerator()*rhs.numerator(),this->denominator()*rhs.denominator());
//}
//Rational operator*(int a,Rational& b){
//    return b.operator*(a);
//}
const Rational operator*(const Rational& a,const Rational& b){
    return Rational(a.numerator()*b.numerator(),a.denominator()*b.denominator());
}

void lamb(){
    auto puls10=[](int i){return i+10;};
    cout<<"+10:   " <<puls10(7)<<endl;
    auto aa=[](int p)->bool{return p>8 ? true:false;};
    cout<<aa(100);
}

#endif //TEMPLE_RATIONAL_H
