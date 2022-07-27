#include<stdio.h>
#define SIZE 5

struct student{
    long num;
    char name[10];
    float score[3];
}stu[SIZE];
struct stu_arg_score{
    int index;
    float arg_score;
}stu_arg[SIZE];
struct student stu2[SIZE];
void save(){
    FILE *fp;
    int i;
    if((fp=fopen("stu.txt","w+"))==NULL){
        printf("can not open file\n");
        return;
    }
    for(i=0;i<SIZE;i++){
        if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1){
            printf("file write error\n");
        }
    }
    fclose(fp);
}
void read(){
    FILE *fp;
    int i,j,change,temp;
    float f_temp;
    if((fp=fopen("stu.txt","rb"))==NULL){
        printf("con not open file\n");
        return;
    }
    if(fread(&stu2[0],sizeof(struct student),5,fp)==0){
        printf("file read eror\n");
        return;
    }
    for(i=0;i<SIZE;i++){
        printf("%ld %s %f %f %f\n",stu2[i].num,stu2[i].name,stu2[i].score[0],stu2[i].score[1],stu2[i].score[2]);
    }
    fclose(fp);
    for(i=0;i<SIZE;i++){
        stu_arg[i].index=i;
        stu_arg[i].arg_score=(stu2[i].score[0]+stu2[i].score[1]+stu2[i].score[2])/3.0;
    }
    for(i=0;i<SIZE && change;i++){
        change=1;
        for(j=0;j<SIZE-1;j++){
            if(stu_arg[j].arg_score<stu_arg[j+1].arg_score){
                temp=stu_arg[j].index;
                f_temp=stu_arg[j].arg_score;
                stu_arg[j].arg_score=stu_arg[j+1].arg_score;
                stu_arg[j+1].arg_score=f_temp;
                stu_arg[j].index=stu_arg[j+1].index;
                stu_arg[j+1].index=temp;
                change=1;
            }
            change=1;
        }
    }
    // printf("排序如下：\n");
    // for(i=0;i<SIZE;i++){
    //     printf("%ld %s %f %f %f\n",stu2[stu_arg[i].index].num,stu2[stu_arg[i].index].name,stu2[stu_arg[i].index].score[0],stu2[stu_arg[i].index].score[1],stu2[stu_arg[i].index].score[2]);
    // }
}
void save_avg(){
    FILE *fp;
    int i;
    if((fp=fopen("stu_sort.txt","w+"))==NULL){
        printf("can not open file\n");
        return;
    }
    for(i=0;i<SIZE;i++){
        if(fwrite(&stu2[stu_arg[i].index],sizeof(struct student),1,fp)!=1){
            printf("file write error\n");
        }
    }
    printf("保存成功\n");
    fclose(fp);
}
void print_avg(){
    FILE *fp;
    int i;
    struct student stu3[SIZE];
    if((fp=fopen("stu_sort.txt","rb"))==NULL){
        printf("con not open file\n");
        return;
    }
    if(fread(&stu3[0],sizeof(struct student),5,fp)==0){
        printf("file read eror\n");
        return;
    }
    for(i=0;i<SIZE;i++){
        printf("%ld %s %f %f %f\n",stu3[i].num,stu3[i].name,stu3[i].score[0],stu3[i].score[1],stu3[i].score[2]);
    }
    fclose(fp);
}
int main(){
    int i;
    for(i=0;i<SIZE;i++){
        printf("insert:");
        scanf("%ld %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
    }
    save();
    read();
    save_avg();
    print_avg();
}