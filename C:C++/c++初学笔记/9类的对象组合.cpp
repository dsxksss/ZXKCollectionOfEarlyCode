#include<iostream>
using namespace std;
//拿一个已有的对象拼装出一个新的对象
class Person {
public:
	Person(const char* name, const char* address) {};
		//:a(name), b(address) {};
	void print() {
		cout <<"name="<< endl;
		cout <<"address="<< endl;
	}
//private:
//	const char* a;
//	const char* b;
};
class Currency {
public:
	Currency(int balance, int cents) {};
		//:a(balance), b(cents){};
	void print() {
		cout <<"0="<< endl;
		cout <<"cents="<< endl;
	}
//private:
//	int a;
//	int b;
};

class SavingsAccount {
public:
	SavingsAccount(const char* name,const char* address, int cents);
	//~SavingsAccount();
	void print();
private:
	Person m_saver;
	Currency m_balance;
};
SavingsAccount::SavingsAccount(const char* name,const char* address, int cents)
	:m_saver(name, address), m_balance(0, cents) {};
//这里只用了以上两个类的构造函数
//并未动两个类的初始化列表
//我这一步相当于帮那两个类做了初始化列表的功能
void SavingsAccount::print()
{
	m_saver.print();
	m_balance.print();
}