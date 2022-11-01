#include <signal.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// using sighandler=void (*)(int);

static void sig_handle(int signo)
{
    if (SIGSTOP == signo)
    {
        cout << "接受到信号SIGSTOP" << endl;
    }
    else if (SIGKILL == signo)
    {
        cout << "接收到信号SIGKILL" << endl;
    }
    else
    {
        cout << "接受到信号：" << signo << endl;
    }
    return;
}

int main()
{
    // auto sighandler ret;

    // auto aa=[](int a){
    //     cout<<"a="<<a<<endl;
    // };
    // void (*pp)(int);
    // pp=[](int a){
    //     cout<<"a="<<a<<endl;
    // };
    // using p1=pp;
    // p1=[](int a){
    //     cout<<"a="<<a<<endl;
    // };
    // aa(999);
    for (;;)
    {
        auto ret = signal(SIGSTOP, sig_handle);
        if (SIG_ERR == ret)
        {
            //cout << "为SIGSTOP挂接信号处理函数失败！" << endl;
            //return -1; 
        }

        ret = signal(SIGKILL, sig_handle);

        if (SIG_ERR == sig_handle);
        if (SIG_ERR == ret)
        {
            //cout << "为SIGKILL挂接信号处理函数失败！" << endl;
            //return -1;
        }
    }
}
