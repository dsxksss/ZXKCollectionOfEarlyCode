#include<iostream>
using namespace std;

//this指针语法
class A {
public:
	int a;
	A(int a){
		this->a = a;
	}
	void show(){
		cout << a << endl;
	}
};
int main27() {
	A aa(12);
	aa.show();
	system("pause");
	return 0;
}

//常函数及常对象知识
class B {
public:
	void print() const{
		cout << "I am print" << endl;
	}
};
int main28() {
	B bb;
	//const B bb这是常对象，只能调用常函数；
	bb.print();
	system("pause");
	return 0;
}

//静态成员的使用方法
class C {
public:
	static int a;//静态变量成员
	static void F() {
		cout << "I am 静态函数" << endl;
		a = 18;//只有静态函数才可以调用静态变量使用；
	}
};
int C::a = 12;//静态成员得到类外初始化，初始化列表是没有用的；//可以不加static
int main29() {
	cout << C::a << endl;//调用方法一、类的作用域调用
	C::F();//调用静态函数成员,方法一样；

	C c;
	cout << c.a << endl;//调用方法二、利用类的对象调用 
	c.F();//调用静态函数成员,方法一样；

	C* p;
	cout << p->a << endl;//调用方法三、利用类的对象指针来调用；
	p->F();////调用静态函数成员,方法一样;
	return 0;
}