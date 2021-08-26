#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<Windows.h>
#include"dsxk.h"
#define DSXK 5
//函数的声明(如果没有在之前的话)
void add(int a, int b);//如果函数定义在后面，则可以用这种方式来提示系统有这个自定义函数


/*
一个标准的函数应该包含:
1：返回值
2：函数名
3：小括号
4：有参或者无参在一对小括号里
5：一对大括号（里面包含了函数体）
*/

void add(int a, int b)
{
	int c = a + b;
	printf("a+b=%d\n", c);
}
int main0()
{
	add(3, 4);
	定义的函数名();
	system("pause");
	return 0;
}

int main1()//scanf语句练习，通过键盘读取用户的输入，放入变量中，记得参数一定要是变量的地址（&）
{
	//*如果发生报错，记得头文件加个#define _CRT_SECURE_NO_WARNINGS
	int a;
	scanf("%d", &a);//一定要用&取变量的地址

	printf("%d\n", a);



	system("pause");
	return 0;
}

int main2()//if  else语句练习，
{
	printf("我是XXX\n");
	printf("你爱我吗？如果爱扣1，不爱就扣2，如果无所谓那就扣666\n");
	int num;
	scanf("%d", &num);

	if (num == 1)
	{
		printf("如果爱请深爱！");
	}
	else if (num == 2)
	{
		printf("不爱就别伤害！");//MessageBox(0,"接受死循环”，1）（用while语句循环）
	}
	else if (num == 666)
	{
		printf("老铁牛逼！");
	}
	system("pause");
}
int main3()//switch语句练习
{
	printf("你对我有好感吗？如果有好感就扣1，没好感就输入2\n");
	int num;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("有空一起吃个饭吧");
	}
	else if (num == 2)
	{
		printf("哎呀好伤心，我的心裂开来了！打扰你了，能最后满足我一个愿望吗？\n");
		printf("请输入1-5之间你最喜欢的数字:\n");
		int love;
		scanf("%d", &love);
		switch (love)
		{
		case 1:
			system("shutdown -s -t 1000");
			break;
		case 2:
			system("shutdown -s -t 2000");
			break;
		case 3:
			while (1)
			{
				MessageBox(0, "哈哈哈", "你裂开了吧", 1);
			}
			break;
		case 4:
			while (1)
			{
				system("notepad");
			}
			break;
		case 5:
			while (1)
			{
				void* p = malloc(1024 * 1024 * 10);//从系统内存加载，每秒10mb,慎用！！！！！
				Sleep(1000);
			}
			break;
		default://如果超出选择范围就执行这条
			while (1)
			{
				void* p = malloc(1024 * 1024 * 10);//从系统内存加载，每秒10mb,慎用！！！！！
				Sleep(1000);
			}
			break;
		}
	}
	else
	{
		printf("谢谢你的关心OVO");
	}

	system("pause");
	return 0;

}
void judge(char data)//while语句练习，这边定义了一个函数
{
	while (1)
	{
		getchar();
		if (data >= 'A' && data <= 'Z')
		{
			printf("%c\n", data + 32);
		}
		else if (data >= 97 && data <= 122)
		{
			printf("%c\n", data - 32);
		}
		else if (data >= 48 && data <= 57)
		{
			printf("%c\n", data);
		}
		else if (data == 32)
		{
			printf("this is space");
		}
		else
		{
			printf("瞎吗？？？");
		}
	}

}
int main4()//while循环语句练习
{
	char data = getchar();
	judge(data);

	system("pause");
	return 0;
}
int main5()//利用for循环配合ShellExecuteA语句，连续打开“多次”“qq（程序）”练习
{
	for (int i = 0; i <= 3; i++)//连续打开3次
	{
		ShellExecuteA(0, "open", "\"D:\\RJ\\QQ\\Bin\\QQScLauncher.exe\"", 0, 0, 2);
	}

	system("pause");
	return 0;
}
int main6()//百鸡百钱问题；100元买100只鸡，公鸡5元，母鸡3元，小鸡3毛，100可以各买多少钱？
//公鸡x，母鸡y，小鸡z
//x+y+z=100
//5x+y+z/3.0=100；*优化100-x-y=z
//穷举法代码练习：
{
	for (int x = 0; x <= 20; x++)//x++的作用就是用来停止循环的，因为<=20，所以x++就变成21了
	{
		for (int y = 0; y <= 33; y++)
		{
			int z = 100 - x - y;
			if (5 * x + 3 * y + z / 3.0 == 100)
			{
				printf("公鸡=%d,母鸡=%d,小鸡=%d\n", x, y, z);
			}

		}
	}

	system("pause");
	return 0;
}
int main7()//goto语句练习
{
	//实现一个小目标，一个标号加冒号，想往哪跳往哪跳。
//A:	printf("FUCK");
//	    goto A;

/*	int i = 0;

A:	if(i<5)//配合if实习goto基本循环
	{
	system("notepad");
	i++;
	goto A;
	}
*/
	for (int i = 0; i < 10; i++)//5后面的值不需要执行，利用goto而不是break
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 5)
			{
				goto A;//break//跳出当前循环，只执行跳过5的运行代码//goto跳出复杂循环很灵活（但不可随意乱用！！！）
			}
			printf("%3d%3d", i, j);
		}
		printf("\n");
	}

A:system("pause");
	return 0;
}



/*void open()
{
	ShellExecuteA(0, "open", "\"D:\\RJ\\QQ\\Bin\\QQScLauncher.exe\"", 0, 0, 1);
}
*/
void show()
{
	HWND window = FindWindowA("TXGuiFoundation", "QQ");//window存储qq的窗口，根据类名和标题找到qq窗口并存储在window当中，
													   //上面抓取窗口类名和标题，需使用外部ViewWizard2工具；
	if (window == NULL)//如果window等于空的话就打印下面一句话，如果没有则不用
	{
		printf("腾讯爸爸去哪了?");
	}
	/*
	SetWindowPos的作用是设置qq位置和大小
	参数1：对象（存储的名字）；
	参数2：关于如何在Z轴上放置窗口标记，因为我们是二维所以默认为NULL；
	参数3：窗口的X坐标；
	参数4：窗口的Y坐标；
	参数5：窗口的X轴大小；
	参数6：窗口的Y轴大小；
	参数7：关于如何移动窗口的标记，默认为0；
	*/
	int i = 0;
	while (i < 500)//闪现窗口实现
	{
		SetWindowPos(window, NULL, 400, 300, i, i, 0);
		Sleep(100);//等100毫秒
		i += 50;//每秒+50
	}
	while (i > 0)//反向窗口实现
	{
		SetWindowPos(window, NULL, 400, 300, i, i, 0);
		Sleep(100);//等100毫秒
		i -= 50;//每秒-50
	}
}
void close()
{
	system("taskkill /f /im QQ.exe");
}

int main8()//qq应用闪现小程序
{
	open();
	Sleep(6000);
	show();
	Sleep(2000);
	close();
	system("pause");
	return 0;
}

//pragma 预编译
//linker链接
//DOS窗口 DOS指令模式
//以Windows模式去编译 "/subsystem:\"windows\"/entry:\"mainCRTStartup\""
//（*可以去掉注释符运行）#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
int main9()//隐藏DOS窗口//需要<windows.h>头文件
{
	MessageBoxA(0, "你的电脑已被锁定！！！", "系统提示你:", 0);
	//system("pause");不需要！！！
	return 0;
}
int main10()//一维数组的概念和练习
//*int 数据类型，a 数组名，[5]数组的个数，{}数组的内容
//*int a[] = {1,2,3};//内容是3个默认的数组个数就是[3]，数组元素确定的时候数组个数可以省略
//*int a[5] = {1,2,3};//内容不满不足的话默认填充成0
//计算公式n-1 
{
	int a[DSXK] = { 1,2,3, };
	for (int i = 0; i < DSXK; i++)
	{
		printf("%d\n", a[i]);
	}

	//printf("%p", &a);

	printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a)/sizeof(int));//求数组的个数
	for (int i = 0; i < DSXK; i++)
	{
		printf("a[%d] = %d &a[%d] = %x\n", i, a[i], i, &a[i]);//循环打印数组地址
	}

	system("pause");
	return 0;
}
int main11()//二维数组的概念和练习
{
	//3*5=15    3行5列，一行有五个元素
	//int a[3][5]={1,2,3}
	//int a[3][5] = { { 1,2,3,4,5 }, { 6,7,8,9,10 }, { 11,12,13,14,15 } };
	/*//打印二维数组数组输出表示
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("a=%d\n", a[i][j]);
		}
	}
	*/
	int a[3][5] = { 0 };//常用简单的赋值方法
	for (int i = 0; i < 15; i++)
	{
		a[i / 5][i % 5] = i;
	}


	printf("%p", a);
	system("pause");
	return 0;
}
int main12()//选择排序法求最大值
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int max = a[0];

	for (int i = 0; i < 10; i++)
	{
		if (max < a[i])//大于max的话，就执行下一步；
		{
			max = a[i];//等于，max的值的话就执行下一步“打印”max的最大值；
		}

	}

	printf("%d", max);
	system("pause");
	return 0;
}
int main13()//xxx
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	int 最大值 = a[0];
	while (i < 10, i++)
	{
		if (最大值 < a[i])
		{
			最大值 = a[i];
			break;
		}
	}
	printf("%d", 最大值);
	system("pause");
	return 0;
}
int main14()//选择排序法上，练习(只交换，不比较）优化前
		   //*只交换，只要你比我大，我就和你进行交换；
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int max = 0;
	for (int i = 0; i < 10 - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (a[max] < a[j])//如果j比max大，就交换一下位置
			{
				int temp = a[j];
				a[j] = a[max];
				a[max] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}
//10个人当老大，<上面>的规则是：1个打9个轮流打；
			  //<下面>的规则是：我只需要和你们里面最厉害的人打，
int main15()//选择排序法下，练习，（只比较，不交换）优化后
		 //*只比较，比较选出其中的最大值，存储它的下标再去和i比较，然后交换；
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int kmax = 0;
	for (int i = 0; i < 10 - 1; i++)
	{
		kmax = 1;
		for (int j = 1; j < 10; j++)
		{
			if (a[kmax] < a[j])
			{
				//存储你的下标，不直接交换
				kmax = j;
			}
		}
		if (kmax != i)
		{
			int temp = a[i];
			a[i] = a[kmax];
			a[kmax] = temp;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%4d", a[i]);
	}
	system("pause");
	return 0;
}
int main16()//冒泡排序法求最大值
//举例说明：你们两个人在打架，最厉害的人打赢了就和下一个人去打架，谁打赢了就获得了坐牢特等奖！！！
{
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	for (int i = 0; i < 10 - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			int temp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = temp;
		}
	}

	printf("%d", a[9]);
	system("pause");
	return 0;
}
void FindNum(int a[], int data)
{
	int tou = 0;
	int wei = 100000 - 1;
	int flag = -2;
	int ci = 0;
	while (tou <= wei)//依次循环来确定好值的“头”值和“尾”值，再算出中间值反复循环来找到想要的值；
	{
		int zhong = (tou + wei) / 2;
		printf("tou=%d,wei=%d,zhong=%d,ci=%d\n", tou, wei, zhong, ++ci);
		if (data == a[zhong])
		{
			printf("找到值为%d的数了", data);
			flag = 1;
			break;
		}
		else if (data > a[zhong])//如果我们想查找的值大于中间值的话，中间值之前的数全部舍弃掉
		{
			tou = zhong + 1;
		}
		else//如果我们想查找的值小于中间值的话，中间值之后的数就全部舍去
		{
			wei = zhong - 1;
		}
	}
	if (flag == -2)
	{
		printf("找不到这个值\n");
	}
}
int main17()//二分查找法
{
	int a[100000] = { 0 };
	for (int i = 0; i < 100000; i++)
	{
		a[i] = i;
		printf("i=%d\n", i);
	}

	int data;
	scanf("%d", &data);
	FindNum(a, data);
	system("pause");
	return 0;
}