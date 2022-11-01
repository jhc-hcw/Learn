#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<iostream>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
using namespace std;

union semun{
    int val;
    semid_ds  *buf;
    unsigned short  *array;
};
using sem_t=int;
sem_t CreateSem(key_t key,int value){
    semun sem;
    sem_t semid;
    sem.val =value;

    semid = semget(key,0,IPC_CREAT| 0666);
    if(-1== semid){
        cout<<"create error!"<<endl;
        return -1;
    }
    semctl(semid,0,SETVAL,sem);
    return semid;

}

int Sem_p(sem_t semid){
    sembuf  sops={0,-1,IPC_NOWAIT};
    return (semop(semid,&sops,1));

}

int Sem_V(sem_t semid)							/*减小信号量值*/
{
	sembuf sops={0,-1,IPC_NOWAIT};		/*建立信号量结构值*/
	
	return (semop(semid,&sops,1));				/*发送信号量操作方法*/
}
void SetvalueSem(sem_t semid, int value)			/*设置信号量的值*/
{
	semun sem;								/*信号量操作的结构*/
	sem.val = value;								/*值初始化*/
		
	semctl(semid,0,SETVAL,sem);						/*设置信号量的值*/
}
int GetvalueSem(sem_t semid)						/*获得信号量的值*/
{
	semun sem;								/*信号量操作的结构*/
	return semctl(semid,0,GETVAL,sem);				/*获得信号量的值*/
}
void DestroySem(sem_t semid)							/*销毁信号量*/
{
	semun sem;									/*信号量操作的结构*/
	sem.val = 0;										/*信号量值的初始化*/
	
	semctl(semid,0,IPC_RMID,sem);						/*设置信号量*/
}


static const string msg="你好，共享内存 !";
int main(){
    key_t key;
    int semid,shmid;
    char i,*shms,*shmc;
    semid_ds buf;
    int value =0;
    char buffer[80];
    pid_t p;

    key= ftok("/ipc.sem",'a');
    shmid=semget(key,1024,IPC_CREAT|0604);
    semid=CreateSem(key,0);
    p=fork();
    if(p>0){
        shms=(char *)shmat(shmid,0,0);

        memcpy(shms,msg.c_str(),msg.length()+1);
        sleep(10);
        Sem_p(semid);
        shmdt(shms);
        DestroySem(semid);

    }else if(p==0){
        shmc=(char *)shmat(shmid,0,0);
        Sem_V(semid);
        cout<<"共享内存值为："<<shmc<<endl;
        shmdt(shmc);

    }
    return 0;

}