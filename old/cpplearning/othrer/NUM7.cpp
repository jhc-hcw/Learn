//创建一个有10个节点的单向链表，依次为每个节点赋值0,1,2,3,4,5,6,7,8,9

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}LinkList;

LinkList* Create_LinkList()
{
    LinkList *p, *q;
    LinkList* L = new LinkList;   //为L动态分配一个结点
    L -> data = 0;
    L -> next = NULL;
    q = L;  //另q等于头结点
    int n;
    cout << "请输入元素个数：" << endl;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        p = new LinkList;
        cout << "请输入第" << i << "个元素" << endl;
        cin >> p -> data;
        q -> next = p;
        p -> next = NULL;
        q = p; 
    }
    return L;
}

void Print(LinkList *L)
{
    LinkList *p;
    p = L -> next;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main()
{
    LinkList *L=Create_LinkList();;
    Print(L);
    return 0;
}
