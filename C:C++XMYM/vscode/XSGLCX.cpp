//*******************************Main_bit:0.2******************************************
#include "L_1.h"
#define MR "C:\\学生信息表0.1.txt"
using namespace std;

void UI()
{
    cout << "***************************"
         << "\n";
    cout << "*    1:填写学生信息       *"
         << "\n";
    cout << "*    2:保存学生信息       *"
         << "\n";
    cout << "*3:查看学生保存好的信息   *"
         << "\n";
    cout << "*4:查看学生未保存好的信息 *"
         << "\n";
    cout << "*     5:清理屏幕          *"
         << "\n";
    cout << "***************************" << endl;
}

int main()
{
    L_1 dx1; //创建一个函数类的对象;
    L_2 dx2; //创建一个变量类的对象;
    UI();
    int a = 0;
    int mm = 0;
    while (true)
    {
        cin >> a;
        switch (a)
        {
        case 1:
            dx1.in_L1(dx2.ZSmz, dx2.ZSxb, dx2.ZSnl, dx2.ZSxh);
            //调用了类1的in函数;
            dx1.set_L1(dx2.ZSmz, dx2.ZSxb, dx2.ZSnl, dx2.ZSxh);
            //调用了类1的set函数;
            cout << "填写成功,记得保存!" << endl;
            break;
        case 2:
            dx1.opfile_L1(MR); //写入文件信息.
            cout << "保存成功,可按数字3查看保存好的信息" << endl;
            break;
        case 3:
        A:
            cout << "请输入四位数密码:" << endl;
            cin >> mm;
            if (mm == 2546)
            {
                cout << "以下是结果:" << endl;
                dx1.refile_L1(MR); //读取文件信息.
                break;
            }
            else
            {
                cout << "密码错误请重新输入:" << endl;
                goto A;
                break;
            }
        case 4:
            cout << "以下是未保存的结果:" << endl;
            dx1.L1_print(dx1);
            break;
        case 5:
            system("cls"); //清屏函数.
            UI();
            break;
        default:
            cout << "选择错误请重新输入对应的选项" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}