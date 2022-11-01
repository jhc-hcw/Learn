#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty()&&s2.empty()){
            return NULL;
        }else{
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int res=s2.top();
            s2.pop();
            return res;
        }
    }
    
    int peek() {
        if(s1.empty()&&s2.empty()){
            return NULL;
        }else{
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int res=s2.top();
            return res;
        }
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }else{
            return false;
        }
    }
};

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
        int res;
        int size=q1.size();
        --size;
        while(size--){
            q2.push(q1.front());
            q1.pop();
        }
        res=q1.front();
        q1.pop();
        q1=q2;
        while(!q2.empty())
            q2.pop();
        return res;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};
