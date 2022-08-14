#include<iostream>
using namespace std;
template<typename T>  struct is_referencej {static constexpr bool value=false;};
template<typename T>  struct is_referencej<T&> {static constexpr bool value=true;};
template<typename T>  struct is_referencej<T&&> {static constexpr bool value=true;};

template<typename T> struct remove_referencej {using type=T;};
template<typename T> struct remove_referencej<T&> {using type = T;};
template<typename T> struct remove_referencej<T&&> {using type=T;};

template<typename T> decltype(auto) foo(typename remove_referencej<T>::type a_copy){a_copy+=1;return a_copy;};
void change(int &&value){
    value++;
}


int main(){
    std::cout<<is_referencej<int>::value<<std::endl;
    cout<<is_referencej<int&>::value<<endl;
    cout<<is_referencej<int&&>::value<<endl;
    int i=999;
    int &&rr=9999;
    cout<<foo<int&&>(rr)<<endl;
    change(move(rr));
    cout<<rr;
    return 0;
}