#include<iostream>
using namespace std;

template<typename T>
struct spare_matrix{
    int row,column;
    T data;
    spare_matrix(int r=0,int col=0,T x=0):row(r),column(col),data(x){
    }
    void set_info(int r=0,int col=0,T x=0){
        row=r;
        column=col;
        data=x;
    }
    void transpose(){
        int t=row;
        row=column;
        column=t;
    };
};
int maxt(){
    int rows,columns,num;
    cout<<"输入矩阵大小和非零个数";
    cin>>rows>>columns>>num;
    spare_matrix<int> martrix[num];
    for(int i=0;i<num;i++){
        int row,col,x;
        cout<<"输入：";
        cin>>row>>col>>x;
        row--;
        col--;
        martrix[i].set_info(row,col,x);
    }
    cout<<"构造好的矩阵如下"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            int flag=0;
            for(int k=0;k<num;k++){
                if(martrix[k].row==i && martrix[k].column==j){
                    cout<<martrix[k].data<<" ";
                    flag=1;
                    continue;
                }
            }
            if(flag==0){
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"转置后三元表为"<<endl;
    for(int i=0;i<num;i++){
        martrix[i].transpose();
        cout<<martrix[i].row+1<<" "<<martrix[i].column+1<<" "<<martrix[i].data<<endl;
    }
    cout<<"转置后矩阵为"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            int flag=0;
            for(int k=0;k<num;k++){
                if(martrix[k].row==i && martrix[k].column==j){
                    cout<<martrix[k].data<<" ";
                    flag=1;
                    continue;
                }
            }
            if(flag==0){
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
int main(){
    maxt();
    return 0;
}