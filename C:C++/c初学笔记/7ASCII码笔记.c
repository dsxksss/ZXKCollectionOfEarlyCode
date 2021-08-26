#include<stdlib.h>
#include<stdio.h>

void main52()
{
	//ASCII码相当于一套规定，我们输入的任意字符都会和ASCII码互相转换让计算机听得懂
	int a = 1;
	char b = '1';
	printf("%d,%d\n", sizeof(a), sizeof(b));//内存空间不一样  
	putchar(105);//ASCII码“i love you”小程序
	putchar(108);
	putchar(111);
	putchar(118);
	putchar(101);
	putchar(121);
	putchar(111);
	putchar(117);


	system("pause");
}

void main53()//简单加密小程序
{
	char ch = getchar();
	if (ch <= 'F') //区间，我们定了一个区间，ch如果大于等于F，所以减去17
	{
		ch = ch - 17;//转化成数值的-17 ASCII码
	}
	putchar(ch);

}

void main54()//复杂加密小程序
{
	char ch[10] = { 'c','a','l','c' };
	system(ch);
	for (int i = 0; i < 4; i++)
	{
		ch[i] = ch[i] - 32;
	}
	printf("%s", ch);

	system("pause");
}

int main55()
{
	int a = 10;
	printf("%d", a);

	system("pause");
}