#include<stdlib.h>
#include<stdio.h>

void main56()
{
	char a = 'a';//字符类型是单引号    //窄字符
	printf("%d,%d", sizeof(a), sizeof('a'));//'a'为了兼容性
	wchar_t b = '汉字';//宽字符
	//a是变量   'a'字符常量 字符变量和字符常量长不一样
	//矿泉水500ml=a，1000ml水='a'
	printf("%d", sizeof("A"));//双引号  因为是字符串类，'\0'字符串至少会有一个字节也就是'\0'
	//*字符变量     字符串常量     字符常量

	//一个汉字占2个字节（扩展知识）


	system("pause");
}
void main57()//小程序
{

	system("color 5f");
	system("title fuck");

	system("pause");
}