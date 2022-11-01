#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<time.h>
#include<sys/msg.h>
using namespace std;

void msg_show_attr(int msg_id, struct msqid_ds &msg_info)																	/*打印消息属性的函数*/
{
	int ret = -1;
	sleep(1);
	ret = msgctl(msg_id, IPC_STAT, &msg_info);		/*获取消息*/
	if( -1 == ret)
	{
		printf("获得消息信息失败\n");					/*获取消息失败，返回*/
		return ;		
	}
	
	printf("\n");									/*以下打印消息的信息*/
	printf("现在队列中的字节数：%ld\n",msg_info.msg_cbytes);																	/*消息队列中的字节数*/
	printf("队列中消息数：%d\n",(int)msg_info.msg_qnum);	/*消息队列中的消息数*/
	printf("队列中最大字节数：%d\n",(int)msg_info.msg_qbytes);																	/*消息队列中的最大字节数*/
	printf("最后发送消息的进程pid：%d\n",msg_info.msg_lspid);																/*最后发送消息的进程*/
	printf("最后接收消息的进程pid：%d\n",msg_info.msg_lrpid);																/*最后接收消息的进程*/
	printf("最后发送消息的时间：%s",ctime(&(msg_info.msg_stime)));														/*最后发送消息的时间*/
	printf("最后接收消息的时间：%s",ctime(&(msg_info.msg_rtime)));														/*最后接收消息的时间*/
	printf("最后变化时间：%s",ctime(&(msg_info.msg_ctime)));																/*消息的最后变化时间*/
	printf("消息UID是：%d\n",msg_info.msg_perm.uid);	/*消息的UID*/
	printf("消息GID是：%d\n",msg_info.msg_perm.gid);	/*消息的GID*/
}

int main(){
    int ret=-1;
    int msg_flag,msg_id;
    key_t key;
    struct msgmbuf{
        int mtype;
        char metext[10];
    };
    msqid_ds msg_info;
    msgmbuf msg_buf;

    int msg_sflags,msg_rflags;
    char *msgpath="/ipc/msg/";
    key=ftok(msgpath,'b');
    if(key != -1)								/*产生key成功*/
	{
		printf("成功建立KEY\n");		
	}
	else										/*产生key失败*/
	{
		printf("建立KEY失败\n");		
	}

    msg_flag=IPC_CREAT|IPC_EXCL;
    msg_id=msgget(key,msg_flag|0x0666);
    if( -1 == msg_id)
	{
		printf("消息建立失败\n");
		return 0;		
	}	
    msg_show_attr(msg_id,msg_info);
    msg_sflags=IPC_NOWAIT;
    msg_buf.mtype=10;
    const static string mst_t="test message!";
    memcpy(msg_buf.metext,mst_t.c_str(),mst_t.length());
    ret=msgsnd(msg_id,&msg_buf,mst_t.length(),msg_rflags);
    if( -1 == ret)
	{
		printf("发送消息失败\n");		
	}
    msg_show_attr(msg_id,msg_info);
    msg_rflags=IPC_NOWAIT|MSG_NOERROR;
    ret=msgrcv(msg_id,&msg_buf,10,10,msg_rflags);
    if( -1 == ret)
	{
		printf("接收消息失败\n");		
	}
	else
	{
		printf("接收消息成功，长度：%d\n",ret);		
	}
    msg_show_attr(msg_id,msg_info);
    msg_info.msg_perm.uid=8;
    msg_info.msg_perm.gid=8;
    msg_info.msg_qbytes=12345;
    ret=msgctl(msg_id,IPC_SET,&msg_info);
    if( -1 == ret)
	{
		printf("设置消息属性失败\n");
		return 0;		
	}
    msg_show_attr(msg_id,msg_info);
    ret=msgctl(msg_id,IPC_RMID,NULL);
    if(-1==ret){
        cout<<"信息删除失败！"<<endl;
        return 0;
    }
    return 0;

}