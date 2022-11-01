#include <stdio.h>
#include <pthread.h>
static int run=1;
static int retvalue;
void *start_routine(void* arg){
    int *running =arg;
    printf("son thread intilized ,get in arg:%d\n",*running);
    while(*running){
        printf("song thread is running\n");
        usleep(1);
    }
    printf("son thread exit\n");
    retvalue=8;
    pthread_exit((void*)&retvalue);
}

int main(){
    pthread_t pt;
    int ret=-1;
    int times=3;
    int i=0;
    int *ret_join=NULL;
    ret=pthread_create(&pt,NULL,(void*)start_routine,&run);
    if(ret !=0){
        printf("create thread failture");
        return 1;
    }
    usleep(1);
    for(;i<times;i++){
        printf("main thread print\n");
        usleep(1);
    }
    run=0;
    pthread_join(pt,(void*) &ret_join);
    printf("thread return value is : %d\n",*ret_join);
    return 0;
}