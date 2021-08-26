#include<iostream>
using namespace std;

//结构体部分的不同：
//1、可以不用struct关键字来声民结构体变量名；
struct dsxk1 {
	int a;
};
int main5()
{
	dsxk1 a1;
	return 0;
}
//2、结构体里可以放函数的成员；
//c语言里不可以放一个整体函数，都是可以引用函数或者放函数地址；
struct dsxk2 {
	int a;
	void dsxk(){
		cout << "dsxk" << endl;	
	}
};
int main6()
{
	dsxk2 a;
	a.dsxk();
	return 0;
}


//指针部分的不同
//1、堆区内存空间申请与释放
int main7()//申请单个空间的用法；
{
	//int* p = (int*)malloc(sizeof (int));//c的申请方法
	int* p1 = new int;//new+type 类型匹配一样；

	//基本的赋值读写应用；
	*p1 = 123;
	cout << *p1 << endl;

	//单个空间释放
	delete p1;//delete (指针)；
	return 0;
}
int main8()//数组内存空间的用法；
{
	int* p = new int[10];//会自动返回数组的首地址；和c一样；
	//int *p1=malloc(5*4);//c的申请方法

	//数组的基本赋值（可循环）
	p[0] = 12;
	p[1] = 24;
	cout << p[0] << " " << p[1] << endl;

	//一个数组内存空间初始化的小方法；
	//利用自带的memset函数来实现
	//memset(p, 0, 5 * 4);

	//释放数组空间
	delete[] p;//在delete后面加方括号来表示要释放一个数组类型的空间；
	//delete[]  
	return 0;
}

