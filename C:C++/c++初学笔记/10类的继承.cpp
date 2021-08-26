#include<iostream>
using namespace std;
//列1、
class A {
public:
	A():i(0){ cout << "A::A" << endl; }
	~A() { cout << "A::~A" << endl; }
	void print() { cout << "A::print()=" << i << endl; }
	void set(int ii) { i = ii; }
private:
	int i;
};
class B :public A {
public:
	void f() {
		set(20);
		print();
		//i=30/这种写法是错误的，子类虽然有了父类的内容，但是父类私有的东西还是不能修改的；
	}
};
int main25() {
	B b;
	b.set(10);
	b.print();

	system("pause");
	return 0;
}

//列2、
class AA {
public:
	AA(int hh) :i(hh) { cout << "AA::AA(int hh)" << endl; }
	~AA() { cout << "AA::~AA()" << endl; }
	void print() { cout << "A::print()=" << i << endl; }
	void set(int ii) { i = ii; }
private:
	int i;
};
class BB:public AA {
public:
	BB() :AA(15) { cout << "BB::BB()" << endl; }
	~BB() { cout << "BB::~BB()" << endl; }
};
int main26() {
	BB bb;

	system("pause");
	return 0;
}