#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main69()
{
	FILE* p = fopen("C:\\Users\\dsxk6\\Desktop\\zxk.zxk", "w");
	char* str = "3dsxk3";
	char str1 = '\n';
	char* str2 = "4dsxk4";
	fwrite(str, sizeof(char), strlen(str)+1, p);/*
	//<string.h>包含strlen函数；
	//参数1：要写入文件的首地址(可以字符串、数组、结构体等等)；
	//参数2和3：相乘==写入的字节数，一般参2：sizeof(类型),参3：几个类型的数据；
	//参数4：文件指针；
	*/fwrite(&str1, sizeof(char), 1, p);//写入一个为‘\n’的字节；记得给&因为是实值；
	fwrite(str2, sizeof(char), strlen(str2)+1, p);//strlen是计数器, 数到\0为止
	fclose(p);//关闭文件并保存，和fopen是配套关系；
	system("pause");
	return 0;
}