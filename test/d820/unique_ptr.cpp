#include<iostream>

template<typename T>
class pointer_wrapper{
    T* ptr_;
    public:
    explicit pointer_wrapper(T *ptr=nullptr):ptr_(ptr){}
    ~pointer_wrapper(){
        delete ptr_;
    }
    T * get()const{
        return ptr_;
    }
    T & operator*()const{
        return *ptr_;
    }
    T * operator->()const{
        return ptr_;
    }
    operator bool()const{
        return ptr_;
    }
    operator int()const{
        return 99;
    }
    // pointer_wrapper(pointer_wrapper &other){
    //     ptr_=other.release();
    // }
    pointer_wrapper(pointer_wrapper &&other){
        ptr_=other.release();
    }
    pointer_wrapper & operator=(pointer_wrapper rhs){
        rhs.swap(*this);
        return *this;
    }
    T *release(){
        auto p=ptr_;
        ptr_=nullptr;
        return p;
    }
    void swap(pointer_wrapper & rhs){
        std::swap(ptr_,rhs.ptr_);
    }
};

int main(){
    int a=33;
    pointer_wrapper<int> p(&a);
    pointer_wrapper<int> pp;
    pp=std::move(p);
    if(p.get()==nullptr){
        std::cout<<"yes!!!"<<std::endl;
    }
    using namespace std;
    cout<<sizeof(pp)<<endl;
    return 9;

}