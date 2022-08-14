#include<iostream>
#include<functional>
using namespace std;

template<typename T>  T a;
template <int... args> struct variadicTemplate1{};

template <int,typename... args> struct variadicTemplate2{};

template <template<typename T> typename ... Args> struct VariadicTemplate3{};

template <typename T> void foo(T t) {cout<<t<<endl;}
template <typename T,typename V,typename S> void foo1(T t,V v){cout<<"part3"<<endl;};
template <typename T,typename V> void foo1(T t ,V v){cout<<"part1"<<endl;};
template <typename T> void foo1(T t,int v){cout<<"part2"<<endl;};

template<int N> struct binary{static constexpr int value=binary<N/10>::value<<1 | N%10;};
template<> struct binary<0>{static constexpr int value=0;};
int main(){
    function<void(int)>  func= &foo<int>;
    foo1(9,9);
    auto f=foo1<int,float>;
    func(88);
    func(99);
    foo1<float,float,float>(2.2,2.2);
    foo1(1.2,1.2);
    cout<<binary<1110110111>::value<<endl;
    return 9;
}
