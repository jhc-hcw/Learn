//
// Created by jhc on 2022/5/20.
//
#ifndef EXCISE_J_SORT_J_H
#define EXCISE_J_SORT_J_H
#include<algorithm>
namespace algrithm_J{
    template<typename  T>
    void sift(T* data ,int k,int len){
        int i=k,j=2*k;
        while(j<=len){
            if(j<len && data[j]<data[j+1]){
                j++;
            }
            if(data[i]<data[j]){
                std::swap(data[i],data[j]);
                i=j;j=i*2;
            }else break;
        }
    }

    template<typename T>
    void heap_sort(T* data ,int len){
        for(int i=len/2;i>=1;--i){
            sift(data,i,len);
        }
        for(int i=len;i>1;--i){
            std::swap(data[1],data[i]);
            sift(data,1,i-1);
        }
    }

}

#include<future>
#include<thread>
#include<chrono>
#include<random>
#include<iostream>
#include<exception>
using namespace std;


int doSomething(char c){
    default_random_engine  dre(c);
    uniform_int_distribution<int>  id(10,1000);
    for(int i=0;i<10;i++){
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }
    return c;
}
int func1() {
    return doSomething('-');
}
int func2(){
    return doSomething('+');
}


#include<vector>
template<typename T>
void bubble_sort(T *v,int len){
    bool flag=true;
    for(int i=0;i<len-1;i++){
        flag=true;
        for(int j=0;j<len-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag=false;
            }
            if(flag){
                return ;
            }
        }

    }
}
template<typename T>
void select_sort(T *a,int len){
    int min;
    for(int i=0;i<len;i++){
        min=i;
        for(int j=i;j<len;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(a[i],a[min]);
        }
    }
}
#include<list>
template <typename T>
class LinkNode {
public:
    // LinkNode are self-referential as default.
    LinkNode() : previous_(this), next_(this) {}

    LinkNode(LinkNode<T>* previous, LinkNode<T>* next)
            : previous_(previous), next_(next) {}

    LinkNode(const LinkNode&) = delete;
    LinkNode& operator=(const LinkNode&) = delete;

    // Insert |this| into the linked list, before |e|.
    void InsertBefore(LinkNode<T>* e) {
        this->next_ = e;
        this->previous_ = e->previous_;
        e->previous_->next_ = this;
        e->previous_ = this;
    }

    // Insert |this| as a circular linked list into the linked list, before |e|.
    void InsertBeforeAsList(LinkNode<T>* e) {
        LinkNode<T>* prev = this->previous_;
        prev->next_ = e;
        this->previous_ = e->previous_;
        e->previous_->next_ = this;
        e->previous_ = prev;
    }

    // Insert |this| into the linked list, after |e|.
    void InsertAfter(LinkNode<T>* e) {
        this->next_ = e->next_;
        this->previous_ = e;
        e->next_->previous_ = this;
        e->next_ = this;
    }

    // Insert |this| as a circular list into the linked list, after |e|.
    void InsertAfterAsList(LinkNode<T>* e) {
        LinkNode<T>* prev = this->previous_;
        prev->next_ = e->next_;
        this->previous_ = e;
        e->next_->previous_ = prev;
        e->next_ = this;
    }

    // Remove |this| from the linked list.
    void RemoveFromList() {
        this->previous_->next_ = this->next_;
        this->next_->previous_ = this->previous_;
        // Next() and Previous() return non-NULL if and only this node is not in any
        // list.
        this->next_ = this;
        this->previous_ = this;
    }

    LinkNode<T>* Previous() const { return previous_; }

    LinkNode<T>* Next() const { return next_; }

    // Cast from the node-type to the value type.
    const T* Value() const { return static_cast<const T*>(this); }

    T* Value() { return static_cast<T*>(this); }

private:
    LinkNode<T>* previous_;
    LinkNode<T>* next_;
};

template <typename T>
class LinkedList {
public:
    // The "root" node is self-referential, and forms the basis of a circular
    // list (root_.Next() will point back to the start of the list,
    // and root_->Previous() wraps around to the end of the list).
    LinkedList() {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(LinkedList&) = delete;

    // Appends |e| to the end of the linked list.
    void Append(LinkNode<T>* e) { e->InsertBefore(&root_); }

    LinkNode<T>* Head() const { return root_.Next(); }

    LinkNode<T>* Tail() const { return root_.Previous(); }

    const LinkNode<T>* End() const { return &root_; }

    bool Empty() const { return Head() == End(); }

private:
    LinkNode<T> root_;
};


void shell_sort(int* data,int len){
    for(int d=len/2;d>0;d/=2){
        for(int i=0;;i++){
            int j=i;
            while(j+d<len){
                if(data[j]>data[j+d]){
                    int temp=data[j];
                    data[j]=data[j+d];
                    data[j+d]=temp;
                }
                j+=d;
            }
            if(j==len-1){
                break;
            }
        }
    }
}

void shell_sort2(int* data,int len){
    for(int d=len/2;d>0;d/=2){
        for(int i=d;i<len;i++){
            for(int j=i-d;j>=0;j-=d){
                if(data[j]>data[j+d]){
                    int temp=data[j];
                    data[j]=data[j+d];
                    data[j+d]=temp;
                }
            }
        }
    }
}


#endif //EXCISE_J_SORT_J_H
