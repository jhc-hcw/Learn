#include<stdio.h>
#include<malloc.h>
typedef struct node {  //二叉树的定义
    float probabilities;
    char cha;
    struct node* lchild, * rchild;
}Bitree;
typedef struct node1{   //链栈的定义
    void *data;       //Void*类型指针当泛型指针，实现栈的泛型功能
    struct node1* next;
}Stack;
Stack *Initst(){    //完成栈的初始化并返回一个栈。
    Stack *s=malloc(sizeof(Stack)); 
    s->data=NULL;
    s->next=NULL;
    return s;
}
int isEmpty(Stack *ls){    //栈的判空
    if(ls->next==NULL) return 1;
    else return 0;
}
void* pop(Stack *ls){     //出栈操作
   if(!isEmpty(ls)){
       Stack* t=ls->next;
       ls->next=t->next;
       return t->data;
   }else{
       return NULL;
   }
}
void* getTop(Stack *ls){    //取栈顶元素
    if(!isEmpty(ls)){
        return ls->next->data;
        }
    else
        return NULL;
}
void push(Stack *ls,void* x){   //入栈操作
    Stack* t=malloc(sizeof(Stack));
    t->data=x;
    t->next=ls->next;
    ls->next=t;
}
void printstack(Stack *sk){     //从栈底到栈顶打印栈的元素，用于打印保存在栈中的哈夫曼编码。
    Stack *p=Initst();
    Stack* t=sk->next;
    int* data;
    while(t){
        push(p,t->data);
        t=t->next;
    }
    t=p->next;
    while(t){
        data=t->data;
        printf("%d",*data);
        t=t->next;
    }
    free(p);
    printf("\t");
}
void sort(Bitree** t, int len) {    //用冒泡排序，对数据元素进行排序，用于构建哈夫曼树辅助作用，传入二叉树指针数组和长度
    for(int i=0;i<len-1;i++){
        for (int j = 0; j < len - 1 - i; j++) {
            if (t[j]->probabilities > t[j + 1]->probabilities) {
                Bitree* tt = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tt;
            }
        }
    }
}
Bitree* createht(Bitree** trees, int len) {  //构建哈夫曼树，传入一个二叉树指针数组，和数组长度。
    int i = 0;
    Bitree* t, * f, * p;
    sort(trees, len);  //对数组进行排序，新建一个节点，挑选最小的两个构成左右子树；
    while (i < len - 1) { //每次循环建立一个非叶子结点，根据哈夫曼树性质，共有n-1个非叶子结点。
        t = trees[i]; f = trees[i + 1];
        p = malloc(sizeof(Bitree));
        p->probabilities = t->probabilities + f->probabilities;
        p->cha = 'x';   //给非叶子结点的字符赋值为小写x，
        p->lchild = t;
        p->rchild = f;
        i++;
        trees[i] = p;
        sort(trees + i, len - i);  //每建立一个节点，将两个最小结点去除，加入新建结点，数组长度减一，重新对数组排序。
    }
    return trees[len - 1];
}
void visited(Bitree *t){  //访问结点元素对应的字符。
    printf("%c,",t->cha);
}
void hfcod(Bitree *t){  //给一个哈夫曼树进行哈夫曼编码，
    Stack *sc=Initst();  //建立一个存放哈夫曼编码的栈。
    int one=1,zero=0;   //哈夫曼编码两个数，
    Bitree *h=t,*c;     //h永远保存后续遍历过程成访问的上一个元素。c是遍历过程用的移动指针
    Stack *s=Initst();  //建立一个遍历辅助用栈
    printf("编码为：");
    if(h!=NULL){
        push(s,h);
        while(!isEmpty(s)){
            c=getTop(s);
            if(c->lchild!=NULL && h!=c->lchild && h!=c->rchild){ //如果上一次访问的节点不是c的左右孩子，意思这个节点是新访问的节点，且左孩子不为空
                push(s,c->lchild);       //直接将左孩子入栈，后续遍历总先访问一颗树的最左下的孩子，找到再说。
                push(sc,&zero);         //从左边路径访问树了，所以哈夫曼编码为0，进栈。
            }else if(c->rchild!=NULL && h!=c->rchild){   //如果c左孩子为空，而且右孩子没有访问过，直接将右孩子进栈，下次循环访问它。
                push(s,c->rchild);    
                push(sc,&one);    //从结点右边路径访问树了，所以哈夫曼编码为1，进展。
            }else {   //代表所有要保留观察的结点都入栈了，且需要访问栈顶结点
                Bitree *tt=pop(s);   //将栈顶出栈访问
                if(tt->cha!='x'){    //如果结点是叶子结点，就访问，并打印其对应的哈夫曼编码。
                    printf("%c:",tt->cha);
                    printstack(sc);
                }
                pop(sc);   //完成了一次访问指针要回溯，哈夫曼编码栈也得出栈。
                h=c;
            }
        }
    }
    printf("\n");
}
int main() {
    float probabilitie[] = { 0.4,0.3,0.15,0.005,0.004,0.003,0.003 };  //存放权值或字符出现概率。
    char chas[] = { 'A','B','C','D','E','F','G' };   //对应权值的字符。
    float probabilitie1[] = { 0.05,0.1,0.15,0.08,0.01,0.2,0.18,0.13,0.03,0.07 };
    char chas1[] = { 'A','B','C','D','E','F','G','H','I','J'};
    int len = sizeof(chas) / sizeof(char);   //计算需要编码的元素个数。
    Bitree** bitrees = malloc(sizeof(Bitree*) * len);   //定义一个二叉树的二重指针，存放所有叶子结点的地址
    for (int i = 0; i < len; i++) {   //将所有字符和权值构建成一个叶子结点。
        bitrees[i] = malloc(sizeof(Bitree));
        bitrees[i]->cha = chas[i];
        bitrees[i]->probabilities = probabilitie[i];
        bitrees[i]->lchild = NULL;
        bitrees[i]->rchild = NULL;
    }
    Bitree* htree = createht(bitrees, len);  //构建哈夫曼树
    int len1 = sizeof(chas1) / sizeof(char);   //计算需要编码的元素个数。
    Bitree** bitrees1 = malloc(sizeof(Bitree*) * len1);   //定义一个二叉树的二重指针，存放所有叶子结点的地址
    for (int i = 0; i < len1; i++) {   //将所有字符和权值构建成一个叶子结点。
        bitrees1[i] = malloc(sizeof(Bitree));
        bitrees1[i]->cha = chas1[i];
        bitrees1[i]->probabilities = probabilitie1[i];
        bitrees1[i]->lchild = NULL;
        bitrees1[i]->rchild = NULL;
    }
    Bitree* htree1 = createht(bitrees1, len1);  //构建哈夫曼树
    hfcod(htree);  //进行哈夫曼编码
    hfcod(htree1);  //进行哈夫曼编码
    return 0;
}