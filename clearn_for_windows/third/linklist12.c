#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int data,index;
    struct node *pre,*next;
};

// typedef struct node1{
//     int a,b,c,d;
//     struct node1 *pre,*next;
// }

// void init(){

// }


int main(){
    char *s="dkfslkdfjklsdfksldfjdfsf";
    int i=0;
    while(s[i]!='\0'){
        printf("%c",s[i]);
        i++;
    }
    return 0;
}