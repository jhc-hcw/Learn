#include<stdio.h>
typedef union{
	unsigned short int value;
	unsigned char byte[2];
}to;

int main(){
	to typeorder;
	typeorder.value=0xabcd;
	printf("byte[1]:%x  byte[2]:%x \n",typeorder.byte[0],typeorder.byte[1]);
	printf("%ld",sizeof(short int));
	return 0;
}	
