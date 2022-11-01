#include <stdio.h>
#include <iostream> 
#define MAXLEN 100
using namespace std;
typedef int DataType;
typedef struct {

	DataType data[MAXLEN];
	int length;

}SeqList;

//输入元素的函数 
void Input(SeqList& L) {

	do {
		cout << "请输入元素：";
		cin >> L.data[L.length];
		L.length++;
	} while (getchar() != '#');
}

//遍历元素的函数
void Output(SeqList& L) {

	for (int i = 1; i < L.length; i++) {

		cout << "第" << i << "个元素的值为：" << L.data[i - 1] << endl;
	}
}
int main()
{
	SeqList La;
	La.length = 0;
	cout << "---请输入数据后按回车键确认，若想结束输入请按 # --- " << endl;
	Input(La);
	cout << "******遍历顺序表中的元素******" << endl;
	Output(La);
	return 0;
}
