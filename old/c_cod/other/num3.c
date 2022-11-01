#include<stdio.h>
int main(){
    int a,b,c,d
    ;
    for(int i=0;i<10000;i++){
        a=i%10;//个位
        b=(i/10)%10;     //十位
        c=(i/100)%10;   //百位
        d=(i/1000)%10;  //千位
        if(a>b){
            if(b>c){
                if(c==0&&d==0){
                    printf(" %d,",i);
                    continue;
                }
                if(c>d){
                    printf(" %d,",i);
                }
            }
        }
    }
    return 0;
}