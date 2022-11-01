#include<stdio.h>
#define SIZE 5

struct student{
    long num;
    char name[10];
    float score[3];
}stu[SIZE];
struct student stu2[SIZE];
struct student* p[SIZE];
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
    int i;
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
}
void sort_data(){
    int i,j,change,temp;
    for(i=0;i<SIZE;i++){
       p[i]=&stu2[i];
    }
    for(i=0;i<SIZE;i++){
        change=0;
        for(j=0;j<SIZE-1;j++){
            float arg1=(p[j]->score[0]+p[j]->score[1]+p[j]->score[2])/3.0;
            float arg2=(p[j+1]->score[0]+p[j+1]->score[1]+p[j+1]->score[2])/3.0;
            if(arg1<arg2){
                long temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                change=1;
            }
        }
    }
}
void save_avg(){
    FILE *fp;
    int i;
    if((fp=fopen("stu_sort.txt","w+"))==NULL){
        printf("can not open file\n");
        return;
    }
    for(i=0;i<SIZE;i++){
        if(fwrite(p[i],sizeof(struct student),1,fp)!=1){
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
    sort_data();
    save_avg();
    print_avg();
}