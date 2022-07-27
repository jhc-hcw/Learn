#include<stdio.h>
int main(){
    int a,b,c,e,d
    ;
    for(int i=11;i<10000;i++){
        a=i%10;//个位
        b=(i/10)%10;     //十位
        c=(i/100)%10;   //百位
        e=(i/1000)%10;  //万位
        if(a>b){
            if(b>c){
                if(c==0&&e==0){
                    printf(" %d,",i);
                    continue;
                }
                if(c>e){
                    printf(" %d,",i);
                }
            }
        }
    }
    return 0;
}