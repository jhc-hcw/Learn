#include <cstring>
#include<iostream>
#include<string>
using namespace std;

class trans{
    int age;
    string name;
    string data;
    public:
    trans(int ager=0,string namer="aaa",string datar="bbb"):age(ager),name(namer),data(datar){

    }
    operator char*()const{
        string res("name:"+name+"age:"+to_string(age)+"data:"+data);
        char *buffer=new char[res.length()+1];
        strcpy(buffer, res.c_str());
        return buffer;
    }
};

int main(){
    trans p(88,"jhc","hhhhhh");
    char *s=p;
    cout<<s<<endl;
    delete [] s;
    return 0;
}