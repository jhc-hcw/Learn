#include<iostream>
#include<string>
#include<vector>
//vector使用方法：https://blog.csdn.net/duan19920101/article/details/50617190?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164150472916780271956293%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164150472916780271956293&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-50617190.first_rank_v2_pc_rank_v29&utm_term=vector&spm=1018.2226.3001.4187
#include<fstream>
using namespace std;

//每门课分数结构体
typedef struct
{
    short DataStructure;    //数据结构
    short Elglish;  //英语
    short DiscreteMathematics;  //离散数学  
    short Database; //数据库
    short ComputerNetwork;  //计算机网络
    short CppPrograme;  //C++程序设计
    short MathematicalLogic;    //数字逻辑
    float AverageScore; //平均成绩
}Score;

//七门科目
static const string curriculums[7]=
{
    "数据结构",
    "英语",
    "离散数学",
    "数据库",
    "计网",
    "C++",
    "数字逻辑"
};

//学生类包含姓名、分数和取出分数函数
class Student
{
    Score score;    //定义一个分数结点
    public:
    Student(string &n,Score &s) //构造函数Student,学生姓名n，分数s。
    {
        //为姓名、分数赋值
        name = n;
        score = s;
        //求七门课平均分的函数
        score.AverageScore=((score.ComputerNetwork+score.CppPrograme+score.Database+score.DataStructure+
        score.DiscreteMathematics+score.Elglish+score.MathematicalLogic)/7);
    }
    string name;    //学生姓名
    Score &getScore()   //取出分数的函数
    {
        return score;   
    }
};

void readScore(vector<Student> &v);     //读取出学生姓名和成绩
void printALL(vector<Student> &v);      //打印出文件中的的信息(姓名+各科分数)
void storageALL(vector<Student> &v);    //将数据从迭代器中存入student.txt文件中
void insertStudent(vector<Student> &v);     //插入学生成绩信息
void deleteStudent(vector<Student> &v);     //删除学生成绩信息
void findStudent(vector<Student> &v);       //查找学生成绩信息
void printDetails(Student &s);              //判断学生哪门课挂科
void alterStudent(vector<Student> &v);      //修改输入错误的学生成绩
void sortStudent(vector<Student> &v);       //按平均分进行排序
void menu();                                //菜单

vector<Student> v;  //建立一个vector，Student为数组元素的数据类型，v为动态数组名
/*
简单的使用方法如下：
vector<int>test;//建立一个vector
test.push_back(1);
test.push_back(2);//把1和2压入vector，这样test[0]就是1,test[1]就是2
*/

int main()
{
    readScore(v);
    // sortStudent(v);
    menu();
    return 0;
}

//按平均分进行排序
void sortStudent(vector<Student> &v){
    vector<Student>::iterator j;
    vector<Student>::iterator i;
    vector<Student> v1;
    while(!v.empty()){
        j=v.begin();
        for(i=v.begin();i!=v.end();i++){
            if(j->getScore().AverageScore<=i->getScore().AverageScore){
                j=i;
            }
        }
        v1.push_back(*j);
        v.erase(j);
    }
    v=v1;
    printALL(v);
}

//读取出学生姓名和成绩
void readScore(vector<Student> &v)
{
    fstream fin;
    //读取文件student.txt中的内容 
    //ios::in(读取)|ios::out(写入)
    //打开文件，既可读取其内容，也可向其写入数据。
    //ios::trunc如果文件本来就存在，则打开时清除原来的内容；如果文件不存在，则新建该文件。
    if(!fstream("student.txt"))
    {
        fin.open("student.txt",ios::in|ios::out|ios::trunc);
    }
    else
    {
        fin.open("student.txt",ios::in);
    }
    //eof（）这个函数来判断文件是否为空或者是否读到文件结尾
    while(!fin.eof())   //若文件不为空或没有读到末尾
    {
        Score s;    //Score结构的结点s
        string name;    //课程名称
        fin>>name;  //读取课程名称
        //empty()作为判断容器是否为空的函数
        if(!name.empty())   //若学生姓名非空
        {
            //读取姓名和成绩
            fin>>s.DataStructure;
            fin>>s.Elglish;
            fin>>s.DiscreteMathematics;
            fin>>s.Database;
            fin>>s.ComputerNetwork; 
            fin>>s.CppPrograme;
            fin>>s.MathematicalLogic;

        Student st(name,s); //定义一个Student类名为st的对象可以传入姓名和成绩。
        v.push_back(st);    //将st姓名和成绩压入vector v。
        }
    }
    fin.close();    //关闭文件
}

void printALL(vector<Student> &v)   //打印出文件中的的信息(姓名+各科分数)
{
    cout<<"----------啊哈 😁,啊哈哈哈 😀 成绩来喽 ！---------------"<<endl;
    cout<<"姓名\t数据结构\t英语\t离散数学\t数据库\t计网\tC++\t数字逻辑\t平均成绩"<<endl;
    //使用迭代器访问元素. vector<int>::iterator it;
    //什么是迭代器：https://blog.csdn.net/CSDN_564174144/article/details/76231626?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164154702516780264024631%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164154702516780264024631&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-76231626.first_rank_v2_pc_rank_v29&utm_term=迭代器&spm=1018.2226.3001.4187
    //建立一个迭代器，Student为数组元素的数据类型，i为变量的名字
    //c.begin();           返回指向容器最开始位置数据的指针
    //c.end();             返回指向容器最后一个数据单元+1的指针
    //如果我们要输出最后一个  元素的值应该是 *（--c.end()）;
    for(vector<Student>::iterator i=v.begin();i!=v.end();i++)
    {
        Score &s=i->getScore(); //读取学生分数
        cout<<i->name+"\t"<<s.DataStructure<<"\t\t"<<s.Elglish<<"\t"<<s.DiscreteMathematics<<"\t\t"<<s.Database<<"\t"<<s.ComputerNetwork<<"\t"<<s.CppPrograme<<"\t"<<s.MathematicalLogic<<"\t\t"<<s.AverageScore<<endl;
    }
}

//将数据从迭代器中存入student.txt文件中
void storageALL(vector<Student> &v)     
{
    fstream fout;
    fout.open("student.txt",ios::trunc|ios::out);
    for(vector<Student>::iterator it=v.begin();it!=v.end();it++){
        Score &s=it->getScore();
        fout<<it->name+"\t"<<s.DataStructure<<"\t"<<s.Elglish<<"\t"<<s.DiscreteMathematics<<"\t"<<s.Database<<"\t"<<s.ComputerNetwork<<"\t"<<s.CppPrograme<<"\t"<<s.MathematicalLogic<<endl;
    }
    fout.close();  
}

/**
 * @brief insert student
 * 
 * @param v 
 */

//插入学生成绩信息
void insertStudent(vector<Student> &v)
{
    Score s;
    string name;
    cout<<"请输入信息（学生姓名+7门课的分数）：";
    cin>>name>>s.ComputerNetwork>>s.CppPrograme>>s.Database>>s.DataStructure>>s.DiscreteMathematics>>s.Elglish>>s.MathematicalLogic;
    Student stu(name,s);
    v.push_back(stu);
}
/**
 * @brief delete Student
 * 
 * @param v 
 */

//删除学生成绩信息
void deleteStudent(vector<Student> &v)
{
    cout<<"请输入删除的姓名：";
    string name;
    cin>>name;
    bool success=false;
    for(vector<Student>::iterator i=v.begin();i!=v.end();i++)
    {
        if(i->name==name)
        {
            //c.erase(p)：从c中删除迭代器p指定的元素，p必须指向c中的一个真实元素，不能等于c.end()
            //c.erase(b,e)：从c中删除迭代器对b和e所表示的范围中的元素，返回e
            v.erase(i);
            cout<<"删除成功❌"<<endl;
            success=true;
            break;
        }
    }
    if(!success){
        cout<<"找不到捏 😅！"<<endl;
    }
}

/**
 * @brief find studentInfo
 * 
 * @param v 
 */

//查找学生成绩信息
void findStudent(vector<Student> &v)
{
    string name;
    cout<<"请输入查找的姓名：";
    cin>>name;
    bool success=false;
    for(vector<Student>::iterator i=v.begin();i!=v.end();i++){
        if(i->name==name){
            vector<Student> vec;
            vec.push_back(*i);
            printALL(vec);
            success=true;
            printDetails(*i);
            break;
        }
    }
    if(!success)
    {
        cout<<"找不到你要咋地 😥！"<<endl;
    }
}

//判断学生哪门课挂科
void printDetails(Student &s)
{
    Score &score=s.getScore();
    short *st=(short *)&score;
    int count=0;
    for(int i=0;i<7;i++)
    {
        if(*(st+i)<60)
        {
            cout<<" 💊 同学你 💊 "<<curriculums[i]<<"挂了 💣！"<<endl;
            count++;
        }
    }
    if(count==0)
    {
        cout<<"一门没挂，全靠老师捞 😎"<<endl;
    }
    else if(count==7)
    {
        cout<<"七门皆挂，召唤摆烂神龙 🌪！！"<<endl;
    }
}

//菜单
void menu()
{
    cout<<"✈ 欢迎来到学生成绩管理系统 🪂！！"<<endl;
    while(true)
    {
        storageALL(v);
        cout<<"🚄🚩⚡❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ❄ ⚡🚩🌌"<<endl;
        cout<<"你到底想干点啥呢 🙄 ？"<<endl;
        cout<<"0->🔎 查询所有学生成绩."<<endl;
        cout<<"1->✒  添加一条学生成绩"<<endl;
        cout<<"2->🗑  删除一个学生信息"<<endl;
        cout<<"3->👀 查找一位学生信息"<<endl;
        cout<<"4->⚙  修改一个学生成绩"<<endl;
        cout<<"5->💻 查看学生成绩名次"<<endl;
        cout<<"6->溜了溜了～🐌🐌🐌"<<endl;
        cout<<" 🗿 你选择：";
        char choose;
        int c;
        cin>>choose;
        if('0'<=choose && choose<='9'){
            c=choose-'0';
        }else{
            cout<<"别为难我胖虎 🌝"<<endl;
            continue;
        }
        fflush(stdin);
        switch(c)
        {
            case 0:
                printALL(v);break;
            case 1:
                insertStudent(v);break;
            case 2:
                deleteStudent(v);break;
            case 3:
                findStudent(v);break;
            case 4:
                alterStudent(v);break;
            case 5:
                sortStudent(v);break;
            case 6:
                storageALL(v);std::exit(0);
            default:
                cout<<"麻烦输入正确选项，你这样我很难办 😏！"<<endl;break;
        }
        fflush(stdin);
    }
}

//修改输入错误的学生成绩
void alterStudent(vector<Student> &v)
{
    string name;
    cout<<"请输入要修改的姓名：";
    cin>>name;
    bool success=false;
    for(vector<Student>::iterator i=v.begin();i!=v.end();i++)
    {
        if(i->name==name)
        {
            vector<Student> vec;
            vec.push_back(*i);
            printALL(vec);
            v.erase(i);
            Score s;
            cout<<"请输入要修改的成绩:";
            cin>>s.ComputerNetwork>>s.CppPrograme>>s.Database>>s.DataStructure>>s.DiscreteMathematics>>s.Elglish>>s.MathematicalLogic;
            Student stu(name,s);
            v.push_back(stu);
            success=true;
            break;
        }
    }
    if(!success)
    {
        cout<<"找不到你要咋地 👻！"<<endl;
    }
}