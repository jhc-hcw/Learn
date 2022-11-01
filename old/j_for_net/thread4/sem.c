#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

void *producter_f(void *arg);
void *comsumer_f(void *arg);
sem_t sem;
unsigned short running =1;
int main(){
    pthread_t consumer_t,producter_t;
    sem_init(&sem,0,16);

    pthread_create(&producter_t,NULL,(void*)producter_f,NULL);
    pthread_create(&consumer_t,NULL,(void*)comsumer_f,NULL);
    sleep(1);
    running =0;
    pthread_join(consumer_t,NULL);
    pthread_join(producter_t,NULL);
    sem_destroy(&sem);
    return 0;
}
void *producter_f(void *arg){
    int semval=0;
    while(running){
        usleep(1);
        sem_post(&sem);
        sem_getvalue(&sem,&semval);
        printf("生产，总数量：%d\n",semval);
    }
}

void *comsumer_f(void *arg){
    int semval=0;
    while(running){
        usleep(1);
        sem_wait(&sem);
        sem_getvalue(&sem,&semval);
        printf("消费，总数量：%d\n",semval);
    }
}