#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef struct {
    int data[Maxsize];
    int Top;
}SeqStack;

int StackEmpty(SeqStack* s) {
    if (s->Top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
void InitStack(SeqStack* s) {
    s->Top = -1;
}
void Push(SeqStack* s, int x) {
    if (s->Top < Maxsize - 1) {
        s->Top++;
        s->data[s->Top] = x;
    }
    else {
        printf("满了");
    }
}

int GetTop(SeqStack* s) {
    if (s->Top == -1) {
        printf("栈空！");
        return 0;
    }
    return s->data[s->Top];
}
void Pop(SeqStack* s) {
    if (s->Top == -1) {
        printf("栈空！");
        return;
    }
    s->Top--;
}
void cc(long num, int i) {
    SeqStack s;
    InitStack(&s);
    while (num) {
        int k = num % i;
        Push(&s, k);
        num = num / i;
    }
    while (!StackEmpty(&s)) {
        int x = GetTop(&s);
        if (x < 10)
            printf("%d", x);
        else {
            switch (x) {
            case 10:printf("A"); break;
            case 11:printf("B"); break;
            case 12:printf("C"); break;
            case 13:printf("D"); break;
            case 14:printf("E"); break;
            case 15:printf("F"); break;
            }
        }
        Pop(&s);
    }
    printf("\n");
}

int main() {
    int d, i;
    printf("请输入你要转化的数和进制：");
    scanf("%d %d", &d, &i);
    printf("\n转化结果为：");
    cc(d, i);
    return 0;
}