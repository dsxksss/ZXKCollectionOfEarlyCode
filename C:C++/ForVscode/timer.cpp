#include <iostream>
#include <windows.h>//move使用了部分函数
#include <time.h>//gettime使用了部分函数
using namespace std;
void move(int x, int y)//清屏方法
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y}; //x,y为屏幕坐标
    SetConsoleCursorPosition(hout, pos);
}
void gettime_now()
{
    time_t timer;//创建一个6结构体对象;
    char *nowtime=new char[30];//创建用于储存时间的空间;
    timer=time(NULL);//获取当前时间给结构体对象
    nowtime=ctime(&timer);//将获取到时间的对象利用ctime函数转换成字符类型;
    cout<<nowtime+12<<endl;//这里加12是屏蔽了多余英文;
    delete []nowtime;//别忘记了回收空间
    Sleep(900);//0.9秒继续
    move(0, 0);//刷新屏幕,参数1=x屏幕坐标,2=y屏幕坐标;
}
int main()
{
    while (1)
    {
        cout<<"当前时间:"<<endl;
        gettime_now();
    }
    system("pause");
    return 0;
}