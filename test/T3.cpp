
#include<iostream>
using namespace std;
template<bool b> 
struct bool_j{static constexpr bool balue=b;};
template<typename T>  struct is_referencej {using type=bool_j<false>;};
template<typename T>  struct is_referencej<T&> {using type=bool_j<true>;};
template<typename T>  struct is_referencej<T&&> {using type=bool_j<true>;};

template<typename T,T v>
struct integral_constantj{
    static constexpr T value=v;
    using value_type=T;
    using type=integral_constantj;
    constexpr operator value_type() const noexcept{return value;};
    constexpr value_type operator()()const noexcept{return value;};
};

template<bool B> using boo_constantj = integral_constantj<bool, B>;
using true_typej = boo_constantj<true>;
using false_typej=boo_constantj<false>;

template<typename T> struct remove_referencej {using type=false_typej;};
template<typename T> struct remove_referencej<T&> {using type =true_typej;};
template<typename T> struct remove_referencej<T&&> {using type=true_typej;};

template<typename T> decltype(auto) foo(typename remove_referencej<T>::type a_copy){a_copy+=1;return a_copy;};
void change(int &&value){
    value++;
}
int main(){
    integral_constantj<int, 88> s;
    int i=integral_constantj<int, 88>(); 
    cout<<i<<endl;
    cout<<s()<<endl;
    cout<<s<<endl;
    return 0;
}