#include <stdio.h>
#include <malloc.h>
typedef struct{
    char id[20];
    char name[20];
    int score;
}student;

typedef struct{
    student *stu;
    int length;
}seqlist;

int maxnum;
seqlist studentlist;

void insert(int index){
    if(studentlist.length==maxnum){
        printf("数组已经满了\n");
        return;
    }
    printf("请输入学生学号:");
    setbuf(stdin,NULL);
    fgets(&studentlist.stu[index].id[0],20,stdin);
    printf("请输入学生名称：");
    fgets(&studentlist.stu[index].name[0],20,stdin);
    printf("请输入学生成绩：");
    scanf("%d",&studentlist.stu[index].score);
    studentlist.length++;
}

int delect(){
    int index;
    printf("请输入你要删除的同学位置：");
    scanf("%d",&index);
    if(index>studentlist.length-1||index<=0){
        printf("删除位置错误！\n");
        return 0;
    }
    for(int i=index-1;i<studentlist.length-1;i++){
        studentlist.stu[i]=studentlist.stu[i+1];
    }
    studentlist.length--;
    return 1;
}


void sprint(){
    for(int i=0;i<studentlist.length;i++){
        printf("-第%d个学生信息-\n",i+1);
        printf("学号：%s",studentlist.stu[i].id);
        printf("姓名：%s",studentlist.stu[i].name);
        printf("成绩：%d\n",studentlist.stu[i].score);
        printf("---------------------------\n");
    }
}

void init(){
    int will;
    printf("请输入你希望创建的人数大小：");
    scanf("%d",&maxnum);
    student *student1=(student*)malloc(maxnum*(sizeof(student)));
    seqlist seq={student1,0};
    studentlist=seq;
    printf("--请录入学生信息--\n");
    for(int i=0;i<maxnum;i++){
        printf("确认继续吗？”1“继续 ”2“不录了:");
        scanf("%d",&will);
        if(will==1)
            insert(i);
        else
            return;
    }
}
int main(){
    int flag;
    printf("系统正在启动>>>>>>>>>>>>\n");
    init();
    while(1){
        printf("你要干啥呢？1：插入数据   2：删除数据   3：打印数据   4：退出 。\n");
        printf("请输入操作数：");
        scanf("%d",&flag);
        switch(flag)
        {
            case 1:
                insert(studentlist.length);
                break;
            case 2:
                delect();
                break;
            case 3:
                sprint();
                break;
            case 4:
                return 0;
            default:
                return 0;
        }
    }
    return 1;
}