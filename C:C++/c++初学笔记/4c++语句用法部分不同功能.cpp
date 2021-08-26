#include<iostream>
using namespace std;


//for循环语句
int main17()
{
	//老编译器c语言写法
	int i = 0;
	for (i < 2; i++;)cout << "ccccc\n";

	//不管编译器c++写法
	for (int i = 0; i < 2; i++)cout << "c++c++c++\n";

	system("pause");
	return 0;
}