#include <stdio.h>

int main(){
    int a[] = {20,21,22,23,8,7,6,5,4,1,54,2};
    int j=0,k;
    
    while(j<12){
        printf("(");
        while(a[j]<a[j+1]){ //升序
            printf("%d,",a[j]);
            if(a[j+1]>a[j+2]){
                printf("%d",a[j+1]);
                j++;
            }
            else{
                j++;
                continue;
            }
            printf(")");
        }

            printf(",");
            printf("(");
        while(a[j]>a[j+1]){ //降序
            printf("%d,",a[j]);
            if(a[j+1]<a[j+2]){
                printf("%d",a[j+1]);
                j++;
            }
            else{
                j++;
                continue;
            }
            printf(")");
        }    
        if(j==11){
            break;
        } 
    }
}