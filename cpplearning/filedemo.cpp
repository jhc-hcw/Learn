#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class student{
    string name;
    string id;
    public :
        student(string n,string i){
            name=n;
            id=i;
        }
        string getname(){
            return name;
        }
};

int main(){
    vector<student> v;
    vector<int> itv;
    for(int i=0;i<100;i++){
        itv.push_back(i);
    }
    for(vector<int>::iterator it=itv.begin();it!=itv.end()-1;it++){
        cout<<*it<<" ";
    }
    student s("jin","122");
    if(v.empty()){
        printf("是空的！");
    }
    v.push_back(s);
    if(!v.empty()){
        student s1=v.at(0);
        cout<<s1.getname()<<endl;
        cout<<v.size()<<endl;
    }
    // fstream f,f1;
    // string name,sex;
    // int age;
    // f.open("data.txt",ios::app|ios::in);
    // f1.open("data2.txt",ios::trunc|ios::out);
    // // f.open("data.txt",ios::);
    // // f<<"你好哇"<<endl;
    // while(!f.eof()){
    //     f>>name>>age>>sex;
    //     cout<<name<<sex<<age<<endl;
    //     f1<<name+" "<<sex+" "<<age<<endl;
    // }
    // f.close();
    return 0;
}