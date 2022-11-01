#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<iostream>
using namespace std;

using sem_t=int;

union semun{
    int val;
    semid_ds  *buf;
    unsigned short  *array;
};


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


int main(){
    key_t key;
    int semid;
    int value=0;
    key=ftok("/ipc/sem",'a');
    semid=CreateSem(key,100);
    for(int i=0;i<=3;i++){
        Sem_p(semid);
        Sem_V(semid);
    }
    value=GetvalueSem(semid);
    cout<<"信号量为:"<<value<<endl;
    DestroySem(semid);
    return 0;
}