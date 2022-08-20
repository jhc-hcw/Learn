#include<iostream>
//类似已经被标准库删除的auto_ptr
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
    pointer_wrapper(pointer_wrapper &other){
        ptr_=other.release();
    }
    pointer_wrapper & operator=(pointer_wrapper &rhs){
        pointer_wrapper(rhs).swap(*this);
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