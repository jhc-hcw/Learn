#include<stdio.h>
int main(){
    struct test{
        int a;
        int b[6];
    };
    struct test t={2,{3,3,3,3,3,3,3,3,3,3}};
    printf("daxiao:%ld",sizeof(t));

    return 0;
}

