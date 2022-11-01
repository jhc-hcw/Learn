#include <iostream>

    using namespace std;

    template<typename T>
    class stack {
        struct node {
            T data;
            struct node *next;
        };
        struct node *D;
    public:
        stack() {
            D = NULL;
        }

        bool isEmpty() {
            if (this->D == NULL) {
                return true;
            } else {
                return false;
            }
        }

        T get_top() {
            if (!this->isEmpty()) {
                return D->data;
            } else {
                return NULL;
            }
        }

        void push(T x) {
            node *p = new node();
            p->data = x;
            p->next = D;
            D = p;
        }

        void pop() {
            if (!this->isEmpty()) {
                node *p = D;
                D = D->next;
                delete (p);
            } else {
                return;
            }
        }
    };
    template<typename T>
    class queue{
        struct node {
            T data;
            struct node *next;
            node(T x=0):data(x),next(0){}
            ~node(){
                delete(next);
            }
        };
        node *head;
        node *rear;
    public:
        queue(){
            head=new node();
            head->data=0;
            head->next=0;
            rear=head;
        }
        void add(T x){
            rear->next=new node(x);
            rear=rear->next;
        };
        void del(){
            if(!is_null()){
                node* temp=head->next;
                head->next=temp->next;
                temp->next=NULL;
                if(temp==rear){
                    rear=head;
                }
                delete(temp);
            }
        };
        T get_rear(){
            if(!is_null()){
                return rear->data;
            }else{
                return NULL;
            }
        };
        T get_head(){
            if(!is_null()){
                return head->next->data;
            }else{
                return NULL;
            }
        };
        bool is_null(){
          if(!head->next){
              return true;
          } else{
              return false;
          }
        };
    };
    template<typename T>
    void swap(T a,T b){
        T temp=a;
        a=b;
        b=temp;
    }
template<typename T>
    struct tree_node {
        T data;
        struct tree_node *lchild, *rchild;

        tree_node(T x=0) : data(x), lchild(0), rchild(0) {

        }

        ~tree_node() {
            delete (lchild);
            delete (rchild);
        }
    };

    template<typename T> using Bitree = tree_node<T> *;

    template<typename T>
    Bitree<T> creat_new_tree(){
        queue<Bitree<T>> q;
        char data;
        int count=0;
        Bitree<T> tree=0,temp_tree=0;
        cout<<"请逐层输入结点,空:'@',结束：'#'：";
        cin>>data;
        while(data!='#'){
            if('@'!=data){
                temp_tree=new tree_node<T>(data);
            }else{
                temp_tree= 0;
            }
            ++count;
            q.add(temp_tree);
            if(count==1){
                tree=temp_tree;
            }else{
                if(temp_tree && q.get_head()){
                    if(count%2==0){
                        q.get_head()->lchild=temp_tree;
                    }else{
                        q.get_head()->rchild=temp_tree;
                    }
                }
                if(count%2==1){
                    q.del();
                }
            }
            cin>>data;
        }
        return tree;
    }
    template<typename T>
    void pre_ord(Bitree<T> x){
        if(x){
            cout<<x->data;
            pre_ord(x->lchild);
            pre_ord(x->rchild);
        }
    }



    template<typename T> void iput_r(Bitree<T>);
    template<typename  T>
    void iput_l(Bitree<T> p){
        T data;
        if(p){
            cin>>data;
            if(data!='#'){
                Bitree<T> t=new tree_node<T>(data);
                p->lchild=t;
                iput_l(t);
                iput_r(p);
            }else{
                iput_r(p);
            }
        }
    }
    template<typename  T>
    void iput_r(Bitree<T> p){
        T data;
        if(p){
            cin>>data;
            if(data!='#'){
                Bitree<T> t=new tree_node<T>(data);
                p->rchild=t;
                iput_l(t);
            }
        }
    }
    template<typename T>
    Bitree<T> stack_create_tree(){
        Bitree<T> temp_t=0,root=0;
        T data;
        cout<<"输入二叉树：";
        cin>>data;
        root=new tree_node<T>(data);
        iput_l(root);
        return root;
    }

    template<typename T>
    void mid_order(Bitree<T> root){
        stack<Bitree<T>> s;
        Bitree<T> p=root;
        while(p || !s.isEmpty()){
            if(p){
                s.push(p);
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                cout<<p->data;
                p=p->rchild;
            }
        }
    }
    template<typename T>
    void pre_order(Bitree<T> root){
        stack<Bitree<T>> s;
        Bitree<T> p=root;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                cout<<p->data;
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
    }
    template<typename T>
    void end_order(Bitree<T> root){
        stack<Bitree<T>> s;
        Bitree<T> head=root,temp=0;
        if(head){
            s.push(root);
            while(!s.isEmpty()){
                temp=s.get_top();
                if(temp->lchild && head!=temp->lchild && head!=temp->rchild){
                    s.push(temp->lchild);
                }else if (temp->rchild && head!=temp->rchild){
                    s.push(temp->rchild);
                }else{
                    cout<<temp->data;
                    s.pop();
                    head=temp;
                }
            }
        }
    }
    template<typename T>
    int layer_order(Bitree<T> root){
        stack<Bitree<T> > *s1,*s2;
        s1=new stack<Bitree<T>>();
        s2=new stack<Bitree<T>>();
        Bitree<T> p=root;
        s1->push(p);
        int count=0;
        while(!s1->isEmpty()) {
            while (!s1->isEmpty()) {
                if (s1->get_top()->lchild) {
                    s2->push(s1->get_top()->lchild);
                }
                if (s1->get_top()->rchild) {
                    s2->push(s1->get_top()->rchild);
                }
                s1->pop();
            }
            stack<Bitree<T>> *t=s1;
            s1=s2;
            s2=t;
            count++;
        }
        return count;
    }
    template<typename T>
    void fouth_m(Bitree<T> root){
        stack<Bitree<T> > s;
        Bitree<T> p=root;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                if(!p->rchild && !p->lchild){
                    cout<<p->data;
                }
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
    }
    template<typename T>
    int fifth_m(Bitree<T> root){
        stack<Bitree<T> > s;
        Bitree<T> p=root;
        int count=0;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                if(!p->rchild && !p->lchild){
                    count++;
                }
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
        return count;
    }
    template<typename T>
    void sixth_m(Bitree<T> root){
        stack<Bitree<T> > s;
        Bitree<T> head=root,temp;
        if(head){
            s.push(root);
            while(!s.isEmpty()){
                temp=s.get_top();
                if(temp->lchild && head!=temp->lchild && head!=temp->rchild){
                    s.push(temp->lchild);
                }else if (temp->rchild && head!=temp->rchild){
                    s.push(temp->rchild);
                }else{
                    if(temp->lchild && temp->rchild){
                        cout<<temp->data;
                    }
                    s.pop();
                    head=temp;
                }
            }
        }
    }
    void meanu(){
        Bitree<char> bitree=stack_create_tree<char>();
        cout<<""<<endl;
        cout<<"----------------二叉树------------"<<endl;
        cout<<"                菜单                       "<<endl;
        cout<<""<<endl;
        cout<<"1.先序遍历         2.中序遍历"<<endl;
        cout<<"3.后序遍历         4.先序输出叶子"<<endl;
        cout<<"5.叶子个数         6后序二度结点"<<endl;
        cout<<"7.输出深度         8.退出"<<endl;
        cout<<"----------------------------------"<<endl;
        int choose=0;
        while(1){
            cout<<"输入选择：";
            cin>>choose;
            switch(choose){
                case 1:
                    pre_ord(bitree);cout<<endl;break;
                case 2:
                    mid_order(bitree);cout<<endl;break;
                case 3:
                    end_order(bitree);cout<<endl;break;
                case 4:
                    fouth_m(bitree);cout<<endl;break;
                case 5:
                    cout<<fifth_m(bitree)<<endl;break;
                case 6:
                    sixth_m(bitree);cout<<endl;break;
                case 7:
                    cout<<layer_order(bitree)<<endl;break;
                case 8:
                    return ;
                default:continue;
            }
        }
    }
int main(){
    //Bitree<char> bitree=creat_new_tree<char>();
    meanu();
    //Bitree<char> bitree=stack_create_tree<char>();
    //end_order(bitree);
    //cout<<layer_order(bitree);
    return 0;
}