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


template <typename T,typename U,typename... Rest>
struct is_one_ofj :bool_constantj<is_one_ofj<T,U>::value || is_one_ofj<T,Rest...>::value>{};

template <typename T,typename U>
struct is_one_ofj<T,U> :is_samej<T,U>{};

template<typename Inst,template <typename...> typename Tmpl>
struct is_instantiation_ofj : false_typej{};

template<template <typename...> typename Tmpl,typename... Args>
struct is_instantiation_ofj<Tmpl<Args...>,Tmpl>:true_typej{};

int main(){
    list<int> li;
    vector<int> vec;
    vector<float> vecf;
    cout<<is_instantiation_ofj<decltype(vec),vector>::value<<endl; 
    cout<<is_instantiation_ofj<decltype(vecf),vector>::value<<endl; 
    cout<<is_instantiation_ofj<decltype(li),vector>::value<<endl; 
    cout<<is_instantiation_ofj<decltype(li),list>::value<<endl; 

    cout<<is_one_ofj<int, float, short,char,double>::value<<endl;
    cout<<is_one_ofj<int, float, short,char,double,int>::value<<endl;
}