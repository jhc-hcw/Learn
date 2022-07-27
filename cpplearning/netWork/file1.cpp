#include<dlfcn.h>
#include<iostream>
using namespace std;
int main(){
    char src[]="Hello Dymatic";
    int (*pStrLenFun)(char *str);
    void *phandle=nullptr;
    char *perr=nullptr;
    phandle=dlopen("./libstr.so",RTLD_LAZY);
    if(!phandle){
        cout<<"Faild load library!"<<endl;
    }
    perr=dlerror();
    if(perr!=NULL){
        cout<<perr<<endl;
        return 0;
    }
    pStrLenFun=(int (*)(char *))dlsym(phandle,"StrLen");
    perr=dlerror();
    if(perr!=NULL){
        cout<<perr<<endl;
        return 0;
    }
    cout<<"the string length is:"<<pStrLenFun(src);
    dlclose(phandle);
    return 0;
}