#include<iostream>
#include<string>
using namespace std;

struct hero{
    string name;
    int age;
    string sex;
};

void bubblesSort(hero *heros,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(heros[j].age>heros[j+1].age){
                hero temp=heros[j];
                heros[j]=heros[j+1];
                heros[j+1]=temp;
            }
        }
    }
}

void printHeros(hero *heros,int len){
    for(int i=0;i<len;i++){
        cout  << "姓名： " <<heros[i].name << " 性别： "<<heros[i].sex<<" 年龄： " <<heros[i].age << endl;
    }
}

int main(){
    struct hero heros[5] =
    {
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
    };
    bubblesSort(heros,5);
    printHeros(heros,5);
    return   0;
}
