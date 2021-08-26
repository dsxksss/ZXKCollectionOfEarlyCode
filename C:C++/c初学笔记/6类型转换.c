#include<stdio.h>
#include<stdlib.h>

void main47()//隐式类型转换
{
	int a = 1;//int=4个字节
	double b = 0.5;//double=8个字节  8个字节的环境下相加的，1.000+0.5
	printf("%f", a + b);//因为double比int大，在隐式类型转换中是以谁最大然后来转成大类型输出，输出的类型所以是double类型的

	system("pause");

}

void main48()//第一种强制类型转换（实际过程用的不多，但是表达明白)
{

	double a = 3.14;
	//printf不会执行自动类型转换！！！如果%d，不是3!!!!
	printf("%d", (int)a);


	system("pause");
}

void main49()//第二种强制类型转换
{

	double a = 3.1415;
	int b = a;

	printf("%d", b);

	system("pause");

}

void main50()//字符类型强制转换（跨物种转换哈哈哈）

{

	char a = 'a';
	int b = a;
	printf("%d", b);

	system("pause");


}

void main51()//布置的习题(计算3.14+5.18*2.15的值以整数形式输出）

{
	double a = 3.14;
	double b = 5.18;
	double c = 2.15;
	int e = a + b * c;
	printf("%d", e);

	system("pause");
}
