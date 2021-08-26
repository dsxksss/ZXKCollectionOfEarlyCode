#include<stdio.h>
#include<stdlib.h>
//自定义函数及部分规范
//像这样把sum（）函数写在上面，是因为c的编译器自上而下的顺序来分析你的代码，这样就是提前告诉编译器有这个函数；
//sum（）后面括号里写的是参数，每个参数需要有自己的类型，返回的什么类型，这样它才能检查你对sum函数的调用是否正确；
void sum(int a, int b);//这里把自定义函数的头提前声明了一下
//这里可以把函数头写到前面，提前声明一下有这个函数，然后也好让自己或别人理解代码；
int main58()
{
	sum(1, 10);
	sum(17, 16);

	system("pause");
	return 0;
}
void sum(int a, int b)//sun（）里面的东西是参数；
{
	int i;
	int sum = 0;
	sum = a + b;

	printf("%d到%d的和是%d\n", a, b, sum);
}



//解：每个函数都有自己的变量空间，参数也位于这个独立的空间中，和其他函数没有关系
//过去，对于函数参数表中的参数叫做“形式参数”，调用函数时给的值，叫做“实际参数”；
//但是那会让初学者误会，所以我们认为，他们的关系是参数和值的关系；
//他们中间发生的只有一件事，就是传值；
void swap(int a, int b);//函数的传值
int main59(void)
{
	int a = 5;
	int b = 6;
	swap(a, b);
	printf("a=%d,b=%d\n",a, b);

	system("pause");
	return 0;
}
void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}
