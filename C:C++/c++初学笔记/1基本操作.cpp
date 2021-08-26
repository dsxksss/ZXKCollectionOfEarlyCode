#include<iostream>
using namespace std;

//一个简单的c++输出程序
int main1()
{
	cout<< "fuck you" << endl;//cout来输出，用endl;来结尾

	system("pause");//这里可以用c里面的system("pause");来暂停;
	return 0;
}

//c++的基本常量与变量的输出
int main2()//c++的基本输出内容详解；
{
	//常量的输出：
	cout << "dsxk" << " " << 'a' << endl;//cout可以在一行里连续输出常量与变量；
	cout << 123 << " " << 12.3 << endl;//<<" "这里输出了一个空格方便区别；
	//变量的输出：//具有c没有的自动识别类型，更加智能了；
	int a = 13;
	char b = 'a';
	double c = 13.333;
	cout << a << endl;//也可以cout<<a
	                  //<<b
	                  //<<c;      这种形式也是可以识别的，按自己方式来就行；
	cout << b << endl;
	cout << c << endl;
	//endl 的作用是换行，(并且清空刷新缓冲区)；当然和c语言里的\n换行符还是有区别的；
	//当然cout<<"dsxk"<<"\n";c++里面也可以用c的那些格式符号，\n被视为一个字符；
	system("pause");
	return 0;
}

int main3()//c++的基本输入内容详解：
{
	char a;
	int b;
	double c;

	//cin也是和cout一样的，都是智能识别类型的，更加智能了；
	cin >> a;//输入的箭头和输出的箭头是相反的！！！；
	cout << a<<"\n";//这边输出a的值；
	cin >> b;
	cout << b << "\n";
	cin >> c;
	cout << c << "\n";
	//也可以想cout一样在同一行连续接收多个类型的数值；
	system("pause");
	return 0;
}

//命名空间小概念练习；
namespace str 
{
	void a() 
	{
		cout << "dsxk" << endl;
	}
}
int main4()
{
	using namespace str;
	str::a();
	//::这个是作用域运算符；
	system("pause");
	return 0;
}

