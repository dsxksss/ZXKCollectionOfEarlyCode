#include <iostream>
#include <windows.h>//moveʹ���˲��ֺ���
#include <time.h>//gettimeʹ���˲��ֺ���
using namespace std;
void move(int x, int y)//��������
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y}; //x,yΪ��Ļ����
    SetConsoleCursorPosition(hout, pos);
}
void gettime_now()
{
    time_t timer;//����һ��6�ṹ�����;
    char *nowtime=new char[30];//�������ڴ���ʱ��Ŀռ�;
    timer=time(NULL);//��ȡ��ǰʱ����ṹ�����
    nowtime=ctime(&timer);//����ȡ��ʱ��Ķ�������ctime����ת�����ַ�����;
    cout<<nowtime+12<<endl;//�����12�������˶���Ӣ��;
    delete []nowtime;//�������˻��տռ�
    Sleep(900);//0.9�����
    move(0, 0);//ˢ����Ļ,����1=x��Ļ����,2=y��Ļ����;
}
int main()
{
    while (1)
    {
        cout<<"��ǰʱ��:"<<endl;
        gettime_now();
    }
    system("pause");
    return 0;
}