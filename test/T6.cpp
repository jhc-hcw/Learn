#include<iostream>
#include<vector>
#include<list>
#include<type_traits>
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

template<bool B> using bool_constantj = integral_constantj<bool, B>;
using true_typej = bool_constantj<true>;
using false_typej=bool_constantj<false>;

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

template <typename T,typename U>
struct is_samej:false_typej {};

template <typename T>
struct is_samej<T,T>:true_typej {};
template<typename T,typename U>
inline constexpr bool is_samej_v = is_samej<T,U>::value;


template <typename T,typename U,typename... Rest>
struct is_one_ofj :bool_constantj<is_one_ofj<T,U>::value || is_one_ofj<T,Rest...>::value>{};

template <typename T,typename U>
struct is_one_ofj<T,U> :is_samej<T,U>{};

template<typename Inst,template <typename...> typename Tmpl>
struct is_instantiation_ofj : false_typej{};

template<template <typename...> typename Tmpl,typename... Args>
struct is_instantiation_ofj<Tmpl<Args...>,Tmpl>:true_typej{};

template<bool B,typename T,typename F>
struct conditionalj:type_identityj<T> {};

template<typename T,typename F>
struct conditionalj<false,T,F> :type_identityj<F> {};

template<bool B,typename T,typename F> 
using conditionalj_t=typename conditionalj<B,T,F>::type;
//????????????
template <typename T,typename U,typename... Rest>
struct is_one_ofc:conditionalj_t<is_samej_v<T,U>,true_typej,is_one_ofc<T,Rest...>> {};

template <typename T,typename U>
struct is_one_ofc<T,U> :conditionalj_t< is_samej_v<T,U>,true_typej,false_typej>{};
int main(){
    cout<<is_one_ofc<int,int,int>::value;
}