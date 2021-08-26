#include<iostream>
using namespace std;

//类和对象的声明
class abc {
public://访问修饰符
	int age;
	void Test() {
		cout << age << endl;
	}
};
int main19()
{
	abc a;//栈区;
	a.age = 12;//对类里面的变量a赋值;
	a.Test();//调用了类里面的函数Test;
	abc* a1 = new abc;//堆区;
	a1->age = 24;
	a1->Test();

	//Test();//类的成员必须通过对象来使用、调用；

	system("pause");
	return 0;
}

//类的访问修饰符；
//1、public：类外可见；公共
class abcd {
public:
	abc a1;//在另外的类里面声明了一个原有类里面的对象a1
	void Test1() {
		a1.Test();//可以在类里面利用类(对象)调用其他类里面的东西；
	}
};
void a() {
	abc a;
	a.Test();
}
//2、private：不对外可见，是私有的；类内可见
//默认的类的访问修饰符；（没有public的话就是这个）

//3、protected:任何主函数/自建函数/别的类/结构体都不可见；只支持
//本类的继承类：子类可见；
class a1 {
	int a;
protected://创建了一个类
	void ab(){
		cout << a << endl;
	}
};
class ZL :public a1 {//创建了一个子类现在（仅供参考）；
	a1 op;
public://对外可见；
	void abc() {
		ab();
	}
};
int main20()
{
	ZL a;
	a.abc();//利用了子类的特性间接的使用了父类的功能；
		//a.ab();这种是错误的，直接访问了父类的东西；
	return 0;
}

//友元函数作用、指定了特定的函数可以使用私有的类功能；
//不管是不是私有公有的都可以使用；
class yy {
private:
	int cc;
	void fun() {
		cout << cc << endl;
	}
	friend void fun1();//声明了一个友元函数；
};
void fun1() {//创建并使用了类里的友元函数
	yy a;
	a.cc = 10; 
	a.fun();
}

//友元类；
//先声明一个基础类：在基础父类里面声明一下友元类
class abc1 {
private:
	int a;
	int fun2() {
		cout << a << endl;
	}
	friend class abcde;//声明了友元类；
};
//在创建友元类：
class abcde {
public:
	abc1 pp;
	void b(){
	pp.fun2();
	}
};
