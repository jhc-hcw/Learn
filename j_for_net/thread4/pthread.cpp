#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

static int run =1;
static int *retvalue;

void *start_routine(void *arg){
    int *running =(int *)arg;
    cout<<"子线程初始化完毕，传入参数为："<<*running<<endl;
    while(*running){
        cout<<"子线程正在运行！"<<endl;
        usleep(1);
    }
    cout<<"子线程推出！"<<endl;
    *retvalue=8;
    pthread_exit((void*)retvalue);
}
int main(void){
    pthread_t pt;
    //void *pfun=(void *)start_routine;
    auto ret=pthread_create(&pt ,NULL,start_routine,&run);
    if(ret !=0){
        cout<<"error thread"<<endl;
        return -1;
    }
    usleep(1);

    for(int i=0;i<3;i++){
        cout<<"primary thread print"<<endl;
        usleep(1);
    }
    run=0;
    int *ret_join =nullptr;
    pthread_join(pt,(void **) &ret_join);
    //int *res=(int *)ret_join;
    cout<<"线程返回值为："<<endl;
    return 0;
}
