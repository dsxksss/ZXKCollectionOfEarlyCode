#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>

int main18()//指针的基础概念
{
	int NC = 12;
	printf("%d\n", NC);
	int* a = &NC;//声明赋值二合一
	*a = 120;
	printf("%d\n", NC);

	int* b = NULL;//*指针声明必须初始化，如果没有初始化值的话就初始化为NULL(一般就用这种形式）
	b = &NC;
	*b = 250;//*作用就是通过你的ID（内存名字）找内存并且修改；
    //指针变量是一种变量，它可以储存任意类型的地址，地址就相当于身份证号，我不光能存一个，我可以任意存储；
	//int 存的是整数，那指针变量就是存的地址；
	//指针永远是4个字节；
	printf("%d\n", NC);

	system("pause");
	return 0;
}
int main19()//指针练习
{
	char a = 'A';
	int* b = &a;
	*b = 'B';

	printf("%d\n", a);
	printf("%p\n", &a);
	printf("%p\n", b);//还是取a的地址；
	printf("%p\n", &b);//这里是取存了a地址的“地址”；
	//指针变量也会有地址产生，上面的a的地址就是用b的地址存储的，所以可以调用也可以查看；
	//列：黑客盗了我的号，别人盗了黑客的号，能不能通过黑客的号找到我的号(可以的）
	//列：能不能通过黑客的ID修改我的号的值呢？（需要通过用二级指针可以实现，指针级数越高，权限就越高）；


	system("pause");
	return 0;
}
int main20()//指针和数组
{
	//int a[3] = { 1,2,3 };//每一个格子的数组都有一个独立的地址，虽然是连着的。
	char bai[3] = { 'z','l','j' };
	//白素贞是一个角色，赵雅芝，某人，某人都演过这个角色；
	//赵雅芝好比是这个角色的代表，也就是数组的首地址；
	//*数组首元素地址和数组的地址是一致的；
	//*数组名是表示数组首地址的地址常量；
	//*数组地址和元素地址虽然看似是一样的，但是不同点在于它们的“类型”不一样，
	//类型不一样导致步长也不一样，步长不一样会导致+1的结果也不一样；
    printf("cheng=%p,c=%p\n\n\n",&bai,bai[0] );//*数组首元素地址和数组的地址是一致的。
	//练习1：
	int a = 10;//在内存当中分配的4个字节。
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };//告诉了编译器分配了40个字节的内存。
	//array内存地址=&array内存地址，但是array+1内存地址≠&array+1内存地址；
	//array+1就是加了4个字节，&array+1是加了40个字节；
	//因为array是数组的首元素，是int类型，它好比赵雅芝，加上1等于加了一个int型变量；
	//因为&array是数组类型的，好比白素贞，它加上1等于加了一个数组，所以它们俩不一样；
	//虽然他们的地址相同，但是加1后的数值不一样，也因为类型不一样，一个是首元素，一个是数组；
	printf("array=%p\narray+1=%p\n&array=%p\n&array+1=%p\n", array, array + 1, &array, &array + 1);

	system("pause");
	return 0;
}
int main21()//数据类型大小练习，涉及到指针
{
	int a = 10;//以a这个变量名所对应的内存空间里放了个10；
	int b[9];//int 类型的数组
	printf("%d\n", b);
	printf("sizeof(a)=%d\n", sizeof(a));//4个字节；
	printf("sizeof(int*)=%d\n", sizeof(int *));//*指针类型在32位环境下是4个字节，在64位环境下是8个字节；
	printf("sizeof(b)=%d\n", sizeof(b));//36个字节，因为它是数组类型,有9个int（4个字节）类型的值相加得到的36个字节；
	printf("sizeof(b[10])=%d\n", sizeof(b[0]));//4个字节，因为他数组里面的值都是int类型的所以是4个字节；
	printf("sizeof(*b)=%d\n\n", sizeof(*b));//4个字节；上面就说过了指针类型的32位环境下是4个字节，
	                                        //64位环境下是8个字节，别管是啥类型（int，double，char类型）都是固定好的；
	system("pause");
	return 0;
}
int main22()//修改变量的两种方式
{
	//方法1，直接修改法：
	int a = 10;
	a = 1;
	printf("a=%d", a);
	//int a=10;//变量名其实就可以看作内存地址的别名，内存名长且不好记，所以产生了他的别名“变量名”，
	//也就是往变量名所代表的内存里存储东西。
	//a = 1;//直接用变量名修改了值，因为变量名代表了内存地址的别名嘛，实际上也是在往内存里存储东西。

	//方法2，间接修改发：
	int* p = &a;
	printf("*p=%p,&a=%p", p, &a);//用p存储了a的地址，所以不需要加&（格式列：&p）
	*p = 100;//间接的用内存地址来修改a的值；
	printf("a=%d", a);//输出现在a的值；

	system("pause");
	return 0;
}
char* pmem1()//全局区（详解）
{
	//问：这个字符串是怎么存在指针里的呢？  指针变量在32位环境下都是4个字节
	//答：仅仅只存储了一个地址，实际的值是在全局区里；
	char* p1 = "dsxk1";
	return p1;//转出去了变量
	//栈区上的变量执行完，变量就销毁掉了；
}
//函数调用完毕，内存就销毁了；
char* pmem2()
{
	//问：两个不同的函数定义了一个相同的字符串，地址会一样吗？
	//答：地址会一样，因为存在全局区里，同样的内容，没必要多开辟一个空间来存放一样的内容，如果是不一样内容，则地址也不一样；
	    //全局区相同字符串常量合并，不相同则不合并；
	char* p2 = "dsxk1";
	return p2;
}
int main23(void)
{
	char* p1 = NULL;
	char* p2 = NULL;
	p1 = pmem1();
	p2 = pmem2();

	printf("p1=%s,p1=%p\n", p1,p1);
	printf("p2=%s,p2=%p\n", p2,p2);
	printf("\n");
	system("pause");
	return 0;
}

char* p_str()//栈区（详解）
{
	char str[100] = "dsxk";//指针是4个字节，4个字节是不能存一个字符串的，这个数组是一百个字节；

	return str;
}
int main24(void)
{
	char* p = NULL;
	p = p_str();//接收完毕之后栈区就销毁了

	//问：p打印这个地址所对应的内存空间的内容是不是dsxk；
	//答：不能，因为栈区100字节的内容是全局区复制过来的，所以已经和全局区无关了，然后释放掉了内存，所以打印才会出现乱码；
	printf("p=%s\n", p);//p存的是数组的首地址，%s是打印地址所指向内存空间的数据；
	//注意返回值放回的不是数组及存放的内容，返回的而是一个4字节的地址；
	//我调用完之后那个函数在栈区里被释放掉了，我存储的内容也会被释放掉，
	//因为不在全局区里，而是从全局区里复制到栈区的，所以栈区的内容成了个体；

	printf("\n");
	system("pause");
	return 0;
}

char* phead()//堆区（详解)
{
	char* tmp = (char*)malloc(100);//char类型指针分配100字节动态内存
	if(tmp==NULL)//如果tmp=空执行，就执行return；没有则继续进行下一步操作；
	{
		return NULL;
	}
	strcpy(tmp, "dsxk");//先是在全局区里存放的（字符串常量和静态常量），然后从全局区里复制到堆区上；
	return tmp;//把返回值输出调用
}
int main25(void)
{
	char* p = NULL;//定义一个char类型的指针p=空类型
	p = phead();//然后调用上面定义的phead函数里指针指向给予的地址
	if (p != NULL)//如果p不等于空类型的话就执行一下操作
	{
		printf("%s\n", p);
		free(p);//在堆区定义内存的话最好记得释放掉内存，这里的ferr是释放内存的意思，但是不是清空内存，而是解除了与这个指针的绑定关系
		p = NULL;
	}
	system("pause");
	return 0;
}

int main26(void)//指针运算小练习
{
	//指针加一加的是指针所指向类型的大小，
	//不是加指针本身变量的大小；
	//指针的类型不单单决定了步长，还决定了解析方式；
	//指针的类型决定了往前走的字节；
	//指针加一不是加了自己本身的大小
	//列在编译器内是：b+sizeof(*b)*1这种形式表示的
	int a = 10;
	int* b = &a;
	printf("%d,%d", &b, b + 1);

	system("pause");
	return 0;
}

int main27(void)//指针数组小练习
{
	//指针也是一种数据类型，指针的类型是指它所指向内存空间的数据类型；
	//指针空间和指针所指向的内存空间是两个不同的概念；
	char a[] = "dsxk";

	for (int b = 0; b < sizeof(a); b++)
	{
		printf("%c", a[b]);
	}
	printf("\n");
	for (char* c = a; c < a + 5; c++)//这里的加5就是加了五个字节，因为我用了四个字节，但是结尾会多一个\0字节，所以就是五个字节；
	{
		printf("%c", *c);
	}

	system("pause");
	return 0;
}
int num1(int a)//无指针修改/结果不行
{
	printf("%p\n",&a);
	a = 10;//这里是打算修改的原b值但是不行；
	return a;
}
void Znum(int *a)//利用指针修改/可行
{
	*a = 20;//这里成了修改后的后c值（在main函数里面）；
}
int main28(void)
{
	//利用一个外部函数修改一个内部函数的值，这就是指针的最大用途；
	//如果想通过形参改变实参的内存内容（值），必须地址传递；
	//指针间接赋值的三个条件：1、两个变量；2、建立关系；3、通过*号操作内存；
	int a = 20;
	printf("%p\n", &a);//在这里发现与外部函数里int a无关系，连地址都不一样，别说可以联系修改地址了；
	
	int b = num1(a);
	printf("b=%d\n", b);//发现不能利用指针前学的知识来修改内部值；
	//上面都是然并卵！

	//下面才是运用了指针；
	int c = 100;//这里是原c值
	Znum(&c);
	printf("c=%d\n", c);//结果变成了在void Znum(int *a)里*a的值；
	
	system("pause");
	return 0;
}
int main29(void)//指针数组
{
	//指针数组是：是一个指针的数组；
	//数组指针是：是指向数组的指针；
	int a = 1;
	int b = 2;
	int c = 3;
	int d[4] = { 1,2,3,4 };
	for(int i=0;i<4;i++)
	{
		printf("普通数组=%d\n", d[i]);
	}
	
	char* Zd[] = { "a","b","c" };
	for(int i=0;i<3;i++)
	{
		printf("指针数组=%s\n", Zd[i]);
	}

	system("pause");
	return 0;
}

//结构体定义练习1；
//struct abc好比我们的int，float，double，char这种类型类似；
//常用的结构体定义方法：
struct abc//第一种
{
	char a[10];//这边定义了十个字符串；
	int b;//这边定义了一个整数；
};
struct abc a = { "dsxk",20 };//这边就是结合了可以用来多类型定义；整合；

struct abc1//第二种
{
	char a[10];
	int b;
} ab = { "dsxk1",30 };

struct //第三种是匿名法，暂时不知道怎么定义变量
{
	char a[10];
	int b;
}abc2;

//struct abc3两者结合起来了，替换成了abc3；
typedef struct abc3//第四种是替换法
{
	char a[10];
	int b;
}abc3;
abc3 abc = { "dsxk3",50 };

//注意一个赋值点！：
int main30(void)//常犯错误点1!!!
{
	abc3 a;
	//a.a={"dsxk"};这种是不行的，是往指针赋值
	//正确的如下：
	strcpy(a.a, "dsxk");
	a.b = 220;//平常调用结构体里的变量的用法
	printf("%s,%d\n", a.a, a.b);
	
	//箭头运算符：可以把->认为是指向的意思；
	abc3 *b;
	b->a;//用箭头运算符用来指针调用结构体里的变量；
	b->b;//用箭头运算符用来指针调用结构体里的变量；
	
	system("pause");
	return 0;
}

int main31(void)//结构体初始化//常犯错误点2
{
	//abc3* dsxk = NULL;//因为没有指向一块内存空间，所以不行
	abc3* dsxk = &a;//这里指向了上面定义的结构体里面的变量空间
	strcpy(dsxk->a, "sss");
	dsxk->b = 200;
	
	printf("%s,%d\n", dsxk->a, dsxk->b);

	system("pause");
	return 0;
}

typedef struct baby
{
	char a[10];
	int b;
}baby;
//我们定义的结构体不开辟内存；
//声明变量（dsxksss）的时候才会开辟空间；
int main32(void)//结构体变量的相互赋值
{
	baby dsxksss = { "sb",25 };
	//他们两赋值完之后是没有关系的，因为是拷贝进去的内容，不是内存地址；
	baby dsxksss1 = dsxksss;//我们可以通过一个已经开辟好的变量名，给另外一个空的变量名赋值，但是得要同一个结构体的模板
	printf("dsxksss1=%s,dsxksss1=%d", dsxksss1.a, dsxksss1.b);
	system("pause");
	return 0;
}

typedef struct baby1//结构体动态数组/静态数组；
{
	char a[10];
	int b;
}baby1;
int main33(void)
{
	int a[3] = { 1,2,3 };
	//学会类比；
	baby1 b[3]= { "dsxk",100,"dsxksss",25,"sss",15};
	//两种赋值方法都可以
	baby1 c[3] = { {"dsxk",100},{"dsxk",50},{"sss",548} };
	for(int i=0;i<3;i++)
	{
		printf("%s,%d\n", b[i].a, c[i].b);
	}

	/*
	int d[3] = { 0 };//先创建一个载体；
	int* pd = (int*)malloc(3*sizeof(int));//pd指向与堆区上分配了三个int类型的malloc动态内存空间；
	free(pd);//记得要释放掉内存，每一个分配好的动态内存空间只可以释放一次；
	*/
	//上面和下面进行一个类比
	//载体已经有了，接下来就是在堆区上分配3个动态内存空间和赋值了；
	baby1* pd = (baby1*)malloc(3*sizeof(baby1));

	if (pd == NULL)//如果pd不是空的话就给他return个-1，（保险写法）；
	{
		return -1;
	}

	for(int i=0;i<3;i++)//循环的赋好数组的值；
	{
		strcpy(pd[i].a, "dsxk");//拷贝dsxk到堆区上；
		pd[i].b = 10 + i;//这边加了i只是好为了区分出来；
	}

	for(int i=0;i<3;i++)//循环打印好数组的值
	{
		printf("第%d个:%s,%d\n", i, pd[i].a, pd[i].b);
	}

	if (pd != NULL) //如果pd不等于空的话就执行free释放内存，然后再给pd赋值为NULL，（保险写法）；
	{
		free(pd);
		pd = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}

typedef struct baby2//结构体嵌套指针
{
	//char a[10];
	char* a;//改成了char类型的指针
	int b;
}baby2;
//结构体不创建空间，只是用来声明；
int main34(void)
{
	baby2 a;
	a.a = (char*)malloc(10);
	strcpy(a.a, "dsxksss");
	a.b = 300;
	printf("%s,%d", a.a, a.b);

	if(a.a!=NULL)
	{
		free(a.a);
		a.a = NULL;
	}

	system("pause");
	return 0;
}

//指针的应用之：交换两个变量的值；
void swap1(int* pa, int* pb);
int main60(void)
{
	int a = 11;
	int b = 22;
	swap1(&a, &b);
	printf("a=%d\nb=%d\n", a, b);

	system("pause");
	return 0;
}
void swap1(int *pa,int *pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

//字符串变量的赋值和理解
int main61()
{
	char* p = "dsxk";
	char* p1 = "dsxk";
	printf("p=%p\n", p);
	printf("p1=%p\n", p1);
	//上面两个指针的内存地址是一样的，因为他们两都指向了全局区的字符串存储位置；
	//这个位置是只读不可写入东西的，所以无法进行字符串变量的修改；
	system("pause");
	return 0;
}

//数组结构体,基础赋值和循环打印数组结构体（配合数组打印知识）
struct time {
	int a;
	int b;
	int c;
};
int main62(void)
{
	struct time time1[] = { {4,5,2009},{5,3,2007},{7,30,2020} };
	for(int i=0;i<3;i++)
	{
		printf("time is=%.2i:%.2i:%.2i\n", time1[i].a, time1[i].b, time1[i].c);
	}
	system("pause");
	return 0;
}

//结构中的结构（嵌套结构体和利用指针赋值表达）例子
struct a{
	int x;
	int y;
};
struct a1 {
	struct a b1;
	struct a b2;
};
int main63(void)
{
	//如果有变量如下：
	struct a1 a;
	a.b1.x = 15; a.b2.y = 20;//给结构体中的结构体的成员赋值；
	//暂时不会scanf("接收x=%d,接收y=%d", &a.b1.x, &a.b2.y);
	printf("%d,%d", a.b1.x, a.b2.y);//一般结构体嵌套结构体的基本赋值方法

	//如果包含了指针的变量如下：
	struct a1 a1, * ap;
	ap = &a1;
	/*那么有如下四种形式是等价的：
	1：a.b1.x
	2：a->b1.x
	如下的括号可写可不写
	3：(a.b1).x
	4：(ap->b1).y
	*/
	system("pause");
	return 0;
}

//嵌套结构体的结构体数组（基本赋值方法）
struct point {
	int x;
	int y;
};
struct rectangle {
	struct point p1;
	struct point p2;
};
void printRect(struct rectangle r)
{
	printf("<%d,%d>to<%d,%d>\n", r.p1.x, r.p1.y, r.p2.x, r.p2.y);
}
int main64(int argc,char const*arsv[])
{
	struct rectangle rects[] = {
		{{1,2},{3,4}},
		{{5,6},{7,8}}
	};//2 rectangles
	for (int i = 0; i < 2; i++)printRect(rects[i]);//因为只需要打印两个结构就够了
	system("pause");
	return 0;
}

//联合union的使用；
typedef union {
	int i;
	char ch[sizeof(int)];
}CHI;
int main65(int argc,char const*arsv[])
{
	CHI chi;
	chi.i = 1234;
	for(int i=0;i<sizeof(int);i++)
	{
		printf("%02hhx\n", chi.ch[i]);//02的意思就是以2个数字输出/不足2位数补零/hh表示我就只要一个字节输出不用扩展/x表示十六进制输出；
	}

	system("pause");
	return 0;
}

