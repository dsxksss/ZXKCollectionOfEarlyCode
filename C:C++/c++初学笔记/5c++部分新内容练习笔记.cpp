#include<iostream>
using namespace std;

//函数重载
void ab(int a, int b)//1
{
	cout << a << " " << b << endl;
}
void ab(int a, int b,int c)//2
{
	cout << a << " " << b << c << endl;
}
void ab(int a, char b)//3
{
	cout << a << " " << b << endl;
}
void ab(int a, float b)//4
{
	cout << a << " " << b << endl;
}
int main18()
{
	//与上方函数对应顺序
	ab(1, 2);//第一个
	ab(1, 2, 3);//第二个
	ab(2, 'b');//第三个
	ab(2, 2.14f);//第四个
	//系统会根据函数参数和个数自动识别对应的函数；
	system("pause");
	return 0;
}