#include <iostream>
#include"sort_J.h"
using namespace std;
#include<set>
//int main() {
//    int a[]={0,9,8,7,6,5,4,3,2,1};
//    algrithm_J::heap_sort<int>(a,9);
//    for(int i=1;i<10;i++){
//        std::cout<<a[i]<<" ";
//    }
//    return 0;
//}
//
//int main(){
//    cout<<"starting func1() in background"<<"and func2() in foreground:"<<endl;
//    future<int> result1(async(func1));
//    int result2=func2();
//    int result=result1.get()+result2;
//    cout<<"\nresult of func1()+func2(): "<<result<<endl;
//}
class B{
public:
    int a;
    ~B(){
        cout<<"B析构函数调用"<<endl;
    }
    B(B &b){
        a=b.a;
    }
    B(B &&b){
        a=b.a;
        b.a=0;
    }
    B():a(99){

    }
    B& operator= (const B &b){
        a=b.a;
        cout<<"调用拷贝等于"<<endl;
        return *this;
    };
};
void fun1(B &&b){
    cout<<"这是右值引用"<<endl;
}
void fun2(B &b){
    cout<<"这是左值值引用"<<endl;
}
//
//int main(){
//   thread t([](){
//       for(int i=0;i<1000;i++) {
//          // this_thread::sleep_for(chrono::milliseconds(10));
//           cout << "iii" << endl;
//       }
//   });
//    thread tt([]() {
//        for(int i=0;i<1000;i++) {
//           // this_thread::sleep_for(chrono::milliseconds(10));
//            cout << "kkk" << endl;
//        }
//    });
//    tuple<int ,string,double> t1(2,"aaaa",2.3);
//    cout<<get<0>(t1);
//    int i;
//    cin>>i;
//}
#include<algorithm>
 int main(){
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int a1[]={99,5,69,33,56,13,22,55,77,48,12,88,2,69,99};
    shell_sort2(a1,15);
//    vector<int> vec={12,2,16,30,28,10,16,20,6,18,-88};
//     std::sort(vec.begin(), vec.end());
//     for(auto i:vec){
//         cout<<i<<endl;
//     }
    for(int i=0;i<15;i++){
        cout<<a1[i]<<" ";
    }
}