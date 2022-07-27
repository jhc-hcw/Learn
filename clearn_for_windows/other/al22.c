#include <stdio.h>

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int j=0,k;
    
    while(j<11){
        if(a[j]<a[j+1]){
            printf("(");
            while((a[j]<a[j+1] )&& j<11){
                printf("%d,",a[j]);
                j++;
            }
            if(a[j]>a[j+1]||j==11){
                if(j==11){
                    printf("%d)",a[j]);
                    break;
                }else{
                    printf("%d),",a[j]);
                }
            }
        }
        if(a[j]>a[j+1] ){
            printf("(");
            while((a[j]>a[j+1] )&& j<11){
                printf("%d,",a[j]);
                j++;
            }
            if(a[j]<a[j+1]||j==11){
                if(j==11){
                    printf("%d)",a[j]);
                    break;
                }else{
                    printf("%d),",a[j]);
                }
            }
        }
    }
}