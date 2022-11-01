#include<stdio.h>
#define SIZE 5

struct student{
    long num;
    char name[10];
    float score[3];
}stu[SIZE];

void initstu(){
    for(int i=0;i<=SIZE-1;i++){
        printf("请输入学生学号：");
        scanf("%ld",&stu[i].num);
        printf("请输入学生姓名：");
        scanf("%s",stu[i].name);
        for (int j = 0;j<=2; j++)
        {
            printf("请输入第%d个成绩：",j+1);
            scanf("%f",&stu[i].score[j]);
        }
    }
}

void printstu(){
    for(int i=0;i<=SIZE-1;i++){
        printf("-------------\n");
        printf("学生姓号:%ld\n",stu[i].num);
        printf("学生姓名：%s\n",stu[i].name);
        for (int j = 0; j<=2; j++)
        {
            printf("第%d个成绩：%f\n",j+1,stu[i].score[j]);
        }
    }
    printf("\n");
}

void stusave(){
    FILE *fp=fopen("stu.txt","w+");
    int i;
    if(fp==NULL){
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<SIZE-1;i++){
        fprintf(fp,"学号：%ld\n",stu[i].num);
        fprintf(fp,"姓名：%s\n",stu[i].name);
        fprintf(fp,"成绩1：%f\n",stu[i].score[0]);
        fprintf(fp,"成绩2：%f\n",stu[i].score[1]);
        fprintf(fp,"成绩3：%f\n",stu[i].score[2]);
    }
    fclose(fp);
}
int main(){
    initstu();
    printstu();
    stusave();
    return 1;
}