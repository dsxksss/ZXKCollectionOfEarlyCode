#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
//#pragma comment(linker,"/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//调用头文件<windows.h>头的#pragma comment来隐藏dos页面

int open()//利用for循环和if语句和switch来选择几段视频，可以关闭之后重新选择；
{
	//ShellExecuteA调用于头文件<windows.h>

	printf("输入数字1进入选择菜单\n");
	int num = 0;
	scanf("%d", &num);//接收一个整数数字
	if (num == 1)
	{
		printf("a是打开2号MP4\n");
		printf("b是打开3号MP4\n");
		printf("c是打开4号MP4\n");
		printf("d是打开5号MP4\n");
	}
	char SZ;//必须与switch里的选择类型匹配；

	scanf("%c", &SZ);
	switch (SZ)//选择1，2，3，4数字打开指定视频
	{
	case 'a':
		Sleep(2000);
		printf("你已打开2号视频\n");
		ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\2.mp4\"", 0, 0, 2);//打开第一个MP4文件
		break;
	case 'b':
		Sleep(2000);
		printf("你已打开3号视频\n");
		ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\3.mp4\"", 0, 0, 2);//打开第二个MP4文件
		break;
	case 'c':
		Sleep(2000);
		printf("你已打开4号视频\n");
		ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\4.mp4\"", 0, 0, 2);//打开第三个MP4文件
		break;
	case 'd':
		Sleep(2000);
		printf("你已打开5号视频\n");
		ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\5.mp4\"", 0, 0, 2);//打开第四个MP4文件
		break;
	}
}
int open1()//利用for循环和if语句和switch来选择几段视频，可以关闭之后重新选择；
{
	//ShellExecuteA调用于头文件<windows.h>
	for (int num = 0; num < 10; num++)
	{
		char SZ;
		scanf("%c", &SZ);
		switch (SZ)//选择1，2，3，4数字打开指定视频
		{
		case 'a':
			Sleep(2000);
			printf("你已打开2号视频\n");
			ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\2.mp4\"", 0, 0, 2);//打开第一个MP4文件
			break;
		case 'b':
			Sleep(2000);
			printf("你已打开3号视频\n");
			ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\3.mp4\"", 0, 0, 2);//打开第二个MP4文件
			break;
		case 'c':
			Sleep(2000);
			printf("你已打开4号视频\n");
			ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\4.mp4\"", 0, 0, 2);//打开第三个MP4文件
			break;
		case 'd':
			Sleep(2000);
			printf("你已打开5号视频\n");
			ShellExecuteA(0, "open", "\"E:\\迅雷下载\\Call of Duty  Modern Warfare 2019\\5.mp4\"", 0, 0, 2);//打开第四个MP4文件
			break;
		}
	}
}
int main35()//视频选择器
{
	open();
	open1();
	system("pause");
	return 0;
}
/*

int a()
{
	double a;
	double a1, a2, a4, a6, a10, aa;
	printf("你的净利润是：\n");
	scanf_s("%lf", &a);
	a1 = 100000 * 0.1;
	a2 = a1 * 200000 * 0.075;
	a4 = a2 + 200000 * 0.05;
	a6 = a4 + 200000 * 0.03;
	a10 = a6 + 400000 * 0.015;
	if (a <= 100000)
	{
		aa = a * 0.1;
	}
	else if (a <= 200000)
	{
		aa = a1 + (a - 100000) * 0.075;
	}
	else if (a <= 400000)
	{
		aa = a2 + (a - 200000) * 0.05;
	}
	else if (a <= 600000)
	{
		aa = a4 + (a - 400000) * 0.03;
	}
	else if (a <= 1000000)
	{
		aa = a6 + (a - 600000) * 0.015;
	}
	else if (a > 1000000)
	{
		aa = a10 + (a - 1000000) * 0.01;
	}
	printf("提成为：aa=%lf", aa);
	printf("\n");

}
int a1()
{
	for (int i = 0; i < 100; i++)
	{
		double a;
		double a1, a2, a4, a6, a10, aa;
		scanf_s("%lf", &a);
		a1 = 100000 * 0.1;
		a2 = a1 * 200000 * 0.075;
		a4 = a2 + 200000 * 0.05;
		a6 = a4 + 200000 * 0.03;
		a10 = a6 + 400000 * 0.015;
		if (a <= 100000)
		{
			aa = a * 0.1;
		}
		else if (a <= 200000)
		{
			aa = a1 + (a - 100000) * 0.075;
		}
		else if (a <= 400000)
		{
			aa = a2 + (a - 200000) * 0.05;
		}
		else if (a <= 600000)
		{
			aa = a4 + (a - 400000) * 0.03;
		}
		else if (a <= 1000000)
		{
			aa = a6 + (a - 600000) * 0.015;
		}
		else if (a > 1000000)
		{
			aa = a10 + (a - 1000000) * 0.01;
		}
		printf("提成为：aa=%lf", aa);
		printf("\n");
	}
}
int main37()//简单小算法2
{
	a();
	a1();
	system("pause");
	return 0;
}
int aa()
{
	int* a = 20;
	return a;
}
int main38(void)
{
	int b = 50;
	b = aa();
	printf("%d", b);

	system("pause");
	return 0;
}
*/
int main()//简单小算法  
{
	for (int a = 1; a < 7; a++)
	{
		for (int b = 1; b < 7; b++)
		{
			for (int c = 1; c < 7; c++)
			{
				for (int d = 1; d < 7; d++)
				{
					if (a != b && b != c && c != d && b != d && a != c && a != d)
					{
						if ((a != 3) && (a != 5) && (b != 3) && (b != 5) && (c != 3) && (c != 5) && (d != 3) && (d != 5))
						{
							printf("%d，%d，%d,%d\n", a, b, c, d);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
typedef struct{
	char a[10];
	int b;
	int c;
}CF;
int kb()
{
	CF* pa = (CF*)malloc(sizeof(CF));
	if (pa == NULL) {
		return -1;
	}
	char a[10];
	printf("请输入你的姓名:\n");
	scanf("%s",&a);
	strcpy(pa->a,a);
	int xb = 0;
A:	printf("输入你的性别\n男(1),女(2),其他(3)\n");
	scanf("%d", &xb);
	pa->b = xb;
	int nl = 0;
B:	printf("输入你年龄:");
	scanf("%d", &nl);
	pa->c = nl;
	printf("\n以下是结果:\n\n");
	printf("你的名字是:%s\n", pa->a);
	if (pa->b == 1) {
		printf("你的性别是:男\n");
	}
	else if (pa->b == 2) {
		printf("你的性别是:女\n");
	}
	else if (pa->b == 3) {
		printf("你的性别是:人妖\n");
	}
	if ((pa->b!=1)&&(pa->b!=2)&&(pa->b!=3)){
		printf("我也不知道你是啥性别，可能是外星人吧！请重新输入！！！\n");
		pa->b = 0;
		goto A;
	}
	printf("你的年龄是:%d\n\n\n", pa->c);
	if (pa != NULL) {
		free(pa);
		pa = NULL;
	}
}
int main67(void)//简单的学生姓名、性别、年龄接收程序；
{
	for (int i = 0; i < 5; i++) {
		kb();
	}

	system("pause");
	return 0;
}