#include<stdio.h>
#include<stdlib.h>
void main39()//加减乘除
{
	/*
	别在乎谁和谁加减乘除，需要注意的是接受的那一方
	*/
	int a = 10;
	int b = 5;
	double c = a + b;
	printf("%f", c);

	system("pause");
	/*
		 10/2
	结果：5   2   1   0
	余数：0   1   0   1
	*/

}
int main40()//a++，++a
{
	int a = 5;
	//++a++;//无论是前加加还是后加加，结果都是这个变量自增1
	printf("%d", ++a);//在运算之前变量自身加1，带着加1后的值去参与运算
	printf("%d", a++);//
	system("pause");

	return 0;

}
int main41()//难题
{
	int a = 10;
	int b = (a++) + (++a) * 3 + (--a) + (a++);//????
	printf("b=%d,\na=%d", b, a);//b=60,a=12


	system("pause");

	return 0;
}
int main42()//符合赋值运算符+=，-=，*=，/=，%=
{
	//int a = 5;
	//a += 10;//a=a+10,等于是赋值

	int a = 3;
	int b = a += a -= a * a;//a*a=9
	/*
	a+=a-=9//第一步
	a-=9   a=a-9a=3-9  a=-6//第二步
	a+=-6  a=a+(-6)  a=-12//第三步
	b=-12,a=-12
	*/
	printf("%d", b);

	system("pause");

	return 0;
}
int main43()//关系运算符>,<,>=,<=,==,!=//用来描述两个事物之间的关系
//c语言中非0表真，0表假。
{
	int GJM = 140;
	int YM = 230;
	while (GJM > YM)//如果确实是gjm身高大于ym，则执行
	{
		printf("对的！");//为真执行“对的！”，不为真则不执行
	}

	system("pause");
	return 0;
}
int main44()//&&逻辑与，&&两边的表达式结果都为true，则这个逻辑表达式为true，如果两边有一个为false，则这个逻辑表达式为false
{
	//列子1，《理想中的女朋友》条件身材大于80分，颜值大于80才为true
	int body = 90;
	int face = 70;

	if (body > 80 && face > 80)//两边都成立的时候才输出，不成立才执行else，
	{
		printf("理想中的女朋友");
	}
	else
	{
		printf("醒醒吧少年！");
	}
	system("pause");
	return 0;
}
int main45()//||逻辑或，两边的表达式结果只要有一边为true，整个逻辑或表达式的结果就为true，两边的结果都为false，逻辑或表达式才为false
{
	//列子2，放低标准，满足一个即可
	int body = 90;
	int face = 70;

	if (body > 80 || face > 80)//两边都成立的时候才输出，不成立才执行else，
	{
		printf("理想中的女朋友");
	}
	else
	{
		printf("醒醒吧少年！");
	}

	system("pause");
	return 0;
}
int main46()//！逻辑非，真的变假，假的变真
{
	//列子3，再放低标准！是个女的，或者是个人就行了
	while(!0);//假的都可以变真的！！！
	{
		printf("好饥渴！！！");
	}

	system("pause");
	return 0;
}