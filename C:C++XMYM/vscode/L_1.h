//***********************JG_bit:0.2******************************************
#ifndef _MYSTRING_
#define _MYSTRING_
#include <iostream> //c++基本库
#include <string.h> //string类型
#include <fstream>  //文件创建的类函数;
#define MAX 200
using namespace std;
class L_1
{
private:          //私有的:
    string L1_xm; //学生姓名
    string L1_xb; //学生性别
    int L1_nl;    //学生年龄
    int L1_xh;    //学生学号
public:           //公开的:
    //*****************************类的初始化********************************************
    L_1(string &GZHS_L_1_mz, string &GZHS_L_1_xb, int GZHS_L_1_nl, int GZHS_L_1_xh)
        : L1_xm(GZHS_L_1_mz), L1_xb(GZHS_L_1_xb), L1_nl(GZHS_L_1_nl), L1_xh(GZHS_L_1_xh) {}
    L_1() : L1_xm("error xb"), L1_xb("error xb"), L1_nl(0), L1_xh(0) {}//默认构造函数
    //**************************类的公用函数列表*****************************************
    void L1_print(L_1 &dx)const;//加上const养成良好习惯;
    //学生信息打印函数,c1:需要一个打印的L_1的对象用来打印信息;
    void set_L1(const string &SET_L1_mz, const string &SET_L1_xb,
                const int &SET_L1_nl, const int &SET_L1_xh);
    //学生信息接受设置函数:
    //c1:需要设置的学生名字,c2:需要设置学生性别,
    //c3:需要设置学生年龄,c4:需要设置学生学号.
    void opfile_L1(const char *WJMR);
    //创建一个用来存放学生信息的文件
    //c1:要创建的文件目录地址,
    //(隐式)c2:文件的打开方式.
    void refile_L1(const char *WJMR);
    //读取文件信息.
    void in_L1(string &IN_mz, string &IN_xb, int &IN_nl, int &IN_xh);
    //接收用户输入.
};
class L_2
{
public:
    string ZSmz = "error ZSmz";
    string ZSxb = "error ZSxb";
    int ZSnl = 0, ZSxh = 0;
};
void L_1::L1_print(L_1 &dx)const
{
    cout << "你的名字是：" << dx.L1_xm << "\n"; //输出"你的名字是："
    cout << "你的性别是：" << dx.L1_xb << "\n"; //         性别
    cout << "你的年龄是：" << dx.L1_nl << "\n"; //         年龄
    cout << "你的学号是：" << dx.L1_xh << endl; //         学号
}
void L_1::set_L1(const string &SET_L1_mz, const string &SET_L1_xb,
                 const int &SET_L1_nl, const int &SET_L1_xh)
{
    L1_xm = SET_L1_mz;
    L1_xb = SET_L1_xb;
    L1_nl = SET_L1_nl;
    L1_xh = SET_L1_xh;
}
void L_1::opfile_L1(const char *WJMR)
{
    ofstream out;             //创建了一个ofstream类的对象
    out.open(WJMR, ios::app); //创建了一个文件
    //c2:初始位置：app:在末尾追加写.
    string WZ[4];
    WZ[0] = "你的名字是：";
    WZ[1] = "你的性别是：";
    WZ[2] = "你的年龄是：";
    WZ[3] = "你的学号是：";
    if (out.is_open()) //判断有没有成功打开文件,如果成功打开了就走以下内容.
    {
        out << WZ[0] << L1_xm << "\n"
            << WZ[1] << L1_xb << "\n"
            << WZ[2] << L1_nl << "\n"
            << WZ[3] << L1_xh << endl;
        out.close(); //关闭这个文件;
    }
}
void L_1::refile_L1(const char *WJMR)
{
    char LSCC[MAX];
    ifstream in(WJMR, ios::in);
    if (!in.is_open())
    {
        cout << "文件打开错误";
    }
    while (!in.eof()) //eof:如果读文件到达文件末尾就return：true;
    {                 //eof查看最后一次读文件操作是否为文件最后一个记录，
                      //如果是，则返回非零值，如果文件还有内容，返回零.
        for (int i = 0; i < 4; i++)
        {
            in.getline(LSCC, MAX); //获取字符的函数;
            //c1:用来存入的字符数组,c2:读取字符的个数.
            cout << LSCC << endl;
        }
        cout << "按回车键看下个学生信息" << endl;
        system("pause");
        cout << endl;
        if (in.eof() != 0)
        {
            cout << "已经没有信息了,重新按菜单选择对应功能" << endl;
            break;
        }
    }
}
void L_1::in_L1(string &IN_mz, string &IN_xb, int &IN_nl, int &IN_xh)
{
    cout << "输入你的姓名:";
    cin >> IN_mz;
    cout << "输入你的性别(男或女):";
    cin >> IN_xb;
    cout << "输入你的年龄:";
    cin >> IN_nl;
    cout << "输入你的学号:";
    cin >> IN_xh;
}

#endif