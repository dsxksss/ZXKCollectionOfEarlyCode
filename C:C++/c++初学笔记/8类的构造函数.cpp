#include<iostream>
using namespace std;

//1、类的构造函数与析构函数
class A {
	//构造函数和析构函数都会被以创建的对象自动调用；
	//是用来给类的变量做自动初始化的，特性和new&delete有一点相似；
private:
	int x;
public:
	void aabbcc();
	void set(int x) { this->x = x; }//这里的this是指的void set()参数里的变量值；
	A() { x = 0; cout << "A::A()" << endl; }//构造函数A
	~A() { cout << "A::~A(),x=" << x << endl; }//析构函数~A
};
//规则1、不要用delete去释放不是new出来的空间;
//规则2、不要用delete去两次释放同一块空间；
//规则3、如果用了方括号new，也得使用方括号delete；
//规则4、如果没带方括号new，那也不要用带方括号的delete；
//规则5、如果没有delete/new的空间，会引起内存泄漏！！！；
int main23()
{
	A* p = new A[10];
	for (int i = 0; i < 10; i++)p[i].set(i);
	delete[] p;
	//可以试试delete p；不带方括号，对比就知道结果了；
	return 0;
}

//2、初始化列表
//初始化列表的工作流程是早于构造函数的！！！
class B {
private:
	const float x, y;
	B(float xa = 0.0, float ya = 0.0)//类B的构造函数
		:x(xa), y(ya){}//初始化列表
};
//列1：student::student(string a)
//     :name(a){}//这里是在做初始化列表
//说明：这里只做了一步，就将a的值给了name变量里；

//列2：student::student(string a)
//     {name = a;}
//说明：这里做了两步，因为第一步做了初始化，但是不知道值是多少，第二步是赋值；

//上面两种方法都可以给name变量给予值a;但是最好还是使用初始化方法来；因为优化了程序的速度；
class C {
public:
	C(int a,float b):a(a),b(b){}//将自己的参数作为初始化列表的值；
	void print() { cout << a <<"\n"<< b << endl; }
private:
	int a;
	float b;
};
int main24() {
	C cc(13, 12.12f);
	cc.print();
	system("pause");
	return 0;
}