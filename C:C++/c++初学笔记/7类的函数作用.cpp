#include<iostream>
using namespace std;

//构造函数：作用自动调用，用于初始化方便；
class gzhs {
public:
	int num = 0;
	void gzhs1() {//这里的内容会被自动调用到函数里面；
		int num = 10;
	}
};
int main21()
{
	gzhs L1;
	cout << L1.num << endl;//不需要调用函数实现初始化定义；
	system("pause");
	return 0;
}
//带参数的构造函数：
class gzhs2 {
public:
	int num;
	float f;
	 gzhs2(int a,float b){
		num = a;
		f = b;
	}
	//gzhs2(int a = 12, float b = 12.13f) {//默认参数值使用方法；
	//	num = a;
	//	f = b;
	//}
};
int main22()
{
	gzhs2 L2(12,12.13f);
	cout << L2.num << endl;
	cout << L2.f << endl;
	//gzhs2 L3();//调用默认值函数可以不传参数值，带值的话则覆盖；
	system("pause");
	return 0;
}