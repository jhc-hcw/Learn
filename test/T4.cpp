#include<iostream>
using namespace std;
template<bool b> 
struct bool_j{static constexpr bool balue=b;};

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

template <typename T> struct type_identityj {using type=T;};
template<typename T> struct remove_referencej:public type_identityj<T> {};
template<typename T> struct remove_referencej<T&>:public type_identityj<T> {};
template<typename T> struct remove_referencej<T&&>:public type_identityj<T> {};
template <typename T> struct is_referencej:public false_typej{};
template <typename T> struct is_referencej<T&>:public true_typej{};
template <typename T> struct is_referencej<T&&>:public true_typej{};
template <typename T> struct is_int_or_referencej:public is_referencej<T> {};
template <> struct is_int_or_referencej<int>:public true_typej {};
template<typename T> inline constexpr bool is_referencej_v=is_referencej<T>::value;
template<typename T> using remove_referencej_t = typename remove_referencej<T>::value;

template<typename T> decltype(auto) foo(typename remove_referencej<T>::type a_copy){a_copy+=1;return a_copy;};
void change(int &&value){
    value++;
}
int main(){
    cout<<is_int_or_referencej<int>::value<<endl;
    cout<<is_int_or_referencej<int>()<<endl;
    cout<<is_int_or_referencej<int>()()<<endl;
    cout<<is_referencej_v<int><<endl;
    remove_referencej<int&&>::type i=999; 
    cout<<i<<endl;
    return 0;
}