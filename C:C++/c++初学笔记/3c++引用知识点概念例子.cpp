#include<iostream>
using namespace std;

//基本数据类型的引用方法：
int main9()
{
	int a = 12;
	int& b = a;//声明变量a的一个引用c,c是变量a的一个别名;
	//int&c;这种是错误的，引用声明的时候必须初始化；
	int& c = b;
	c = 13;
	int i = 14;
	c = i;//这种不是给引用重指向，而是把i的值赋值给了a(因为a被c引用了)；
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	//他们三的地址都是一样的
	//因为其实他们都指向了a的地址方向，所以才一样的；
	system("pause");
	return 0;
}

//常量的引用方法：
int main10()
{
	//int &a=12;这种方法引用一个常量是不行的；
	const int& a = 12;
	//利用const修饰符的不可写性来定义一个常量；
	cout << a << endl;
	system("pause");
	return 0;
}

//复合数据类型的引用
//1、数组类型的引用方法：(方法与c++指针数组的赋值方法一样)
int main11()
{
	int a[10];
	int(&b)[10] = a;
	b[2] = 12;
	cout << a[2] << endl;
	system("pause");
	return 0;
}
//2、结构体类型的引用方法:(类型 &名字 = 结构体实例)
struct dsxk {
	int a;
	char b;
};
int main12()
{
	dsxk a;
	int& b = a.a;
	b = 16;
	cout << a.a << endl;
	a.a = 15;
	char& c = a.b;
	c = 'a';
	cout << b << endl;
	cout << c << endl;
	system("pause");
	return 0;
}

//指针的引用方法：
int main13()
{
	int a = 13;
	int* b = &a;
	cout << a << endl;
	//记得类型匹配
	int* (&c) = b;
	//赋值的使用方法和基本类型赋值方法大致一样；
	*c = 42;
	cout << a << endl;
	system("pause");
	return 0;
}

//引用做参数
void fun(int& a)
{
	a = 13;
	//声明了一个引用a，但是还没告诉他目标是谁；
	cout << a << endl;
}
void fun1(int a)
{
	a = 14;
	cout << "fun1:" << a << endl;
}
void fun2(int*a)//在c语言修改函数外部值的方法；
{
	*a = 15;
}
int main14() 
{
	int b = 12;
	fun(b);
	//上面定义了一个b；然后用b作为了引用a的目标；
	//下面用来对比
	fun1(b);//13

	fun2(&b);//利用c语言的指针实现的修改；b=15;
	cout << b << endl;

	system("pause");
	return 0;
}

//交换两个数的值
void tap(int &a1,int &b1){
	int tap = a1;
	a1 = b1;        //使用引用功能做参数；
	b1 = tap;
}
void tap1(int* a1, int* b1) {
	int tap = * a1;
	* a1 = * b1;    //如果使用指针功能；
	* b1 = tap;
}
int main15()
{
	int a = 10;
	int b = 20;
	//先定义好了两个要交换的值；
	//查看先值；
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	//tap1(a,b);//指针的方法；
	tap(a, b);
	//创建了一个利用了引用做参数来交换a,b值的函数；

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	//查看后值；
	system("pause");
	return 0;
}

//引用作为返回值；
//int &abc(){
//	int a = 12;
//	//return a;//记得变量得与类型匹配；
//	return 0;
//}
int main16()
{
	//int& b = abc();
	//cout << b << endl;//不能这样使用，因为函数内部的值会释放掉，
	//现在你相当与输出了一块非法空间的内存，这种操作是未知有风险的；
	return 0;
}