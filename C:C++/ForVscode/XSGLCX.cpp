//*******************************Main_bit:0.2******************************************
#include "L_1.h"
#define MR "C:\\ѧ����Ϣ��0.1.txt"
using namespace std;

void UI()
{
    cout << "***************************"
         << "\n";
    cout << "*    1:��дѧ����Ϣ       *"
         << "\n";
    cout << "*    2:����ѧ����Ϣ       *"
         << "\n";
    cout << "*3:�鿴ѧ������õ���Ϣ   *"
         << "\n";
    cout << "*4:�鿴ѧ��δ����õ���Ϣ *"
         << "\n";
    cout << "*     5:������Ļ          *"
         << "\n";
    cout << "***************************" << endl;
}

int main()
{
    L_1 dx1; //����һ��������Ķ���;
    L_2 dx2; //����һ��������Ķ���;
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
            //��������1��in����;
            dx1.set_L1(dx2.ZSmz, dx2.ZSxb, dx2.ZSnl, dx2.ZSxh);
            //��������1��set����;
            cout << "��д�ɹ�,�ǵñ���!" << endl;
            break;
        case 2:
            dx1.opfile_L1(MR); //д���ļ���Ϣ.
            cout << "����ɹ�,�ɰ�����3�鿴����õ���Ϣ" << endl;
            break;
        case 3:
        A:
            cout << "��������λ������:" << endl;
            cin >> mm;
            if (mm == 2546)
            {
                cout << "�����ǽ��:" << endl;
                dx1.refile_L1(MR); //��ȡ�ļ���Ϣ.
                break;
            }
            else
            {
                cout << "�����������������:" << endl;
                goto A;
                break;
            }
        case 4:
            cout << "������δ����Ľ��:" << endl;
            dx1.L1_print(dx1);
            break;
        case 5:
            system("cls"); //��������.
            UI();
            break;
        default:
            cout << "ѡ����������������Ӧ��ѡ��" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}