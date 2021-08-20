//***********************JG_bit:0.2******************************************
#ifndef _MYSTRING_
#define _MYSTRING_
#include <iostream> //c++������
#include <string.h> //string����
#include <fstream>  //�ļ��������ຯ��;
#define MAX 200
using namespace std;
class L_1
{
private:          //˽�е�:
    string L1_xm; //ѧ������
    string L1_xb; //ѧ���Ա�
    int L1_nl;    //ѧ������
    int L1_xh;    //ѧ��ѧ��
public:           //������:
    //*****************************��ĳ�ʼ��********************************************
    L_1(string &GZHS_L_1_mz, string &GZHS_L_1_xb, int GZHS_L_1_nl, int GZHS_L_1_xh)
        : L1_xm(GZHS_L_1_mz), L1_xb(GZHS_L_1_xb), L1_nl(GZHS_L_1_nl), L1_xh(GZHS_L_1_xh) {}
    L_1() : L1_xm("error xb"), L1_xb("error xb"), L1_nl(0), L1_xh(0) {}//Ĭ�Ϲ��캯��
    //**************************��Ĺ��ú����б�*****************************************
    void L1_print(L_1 &dx)const;//����const��������ϰ��;
    //ѧ����Ϣ��ӡ����,c1:��Ҫһ����ӡ��L_1�Ķ���������ӡ��Ϣ;
    void set_L1(const string &SET_L1_mz, const string &SET_L1_xb,
                const int &SET_L1_nl, const int &SET_L1_xh);
    //ѧ����Ϣ�������ú���:
    //c1:��Ҫ���õ�ѧ������,c2:��Ҫ����ѧ���Ա�,
    //c3:��Ҫ����ѧ������,c4:��Ҫ����ѧ��ѧ��.
    void opfile_L1(const char *WJMR);
    //����һ���������ѧ����Ϣ���ļ�
    //c1:Ҫ�������ļ�Ŀ¼��ַ,
    //(��ʽ)c2:�ļ��Ĵ򿪷�ʽ.
    void refile_L1(const char *WJMR);
    //��ȡ�ļ���Ϣ.
    void in_L1(string &IN_mz, string &IN_xb, int &IN_nl, int &IN_xh);
    //�����û�����.
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
    cout << "��������ǣ�" << dx.L1_xm << "\n"; //���"��������ǣ�"
    cout << "����Ա��ǣ�" << dx.L1_xb << "\n"; //         �Ա�
    cout << "��������ǣ�" << dx.L1_nl << "\n"; //         ����
    cout << "���ѧ���ǣ�" << dx.L1_xh << endl; //         ѧ��
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
    ofstream out;             //������һ��ofstream��Ķ���
    out.open(WJMR, ios::app); //������һ���ļ�
    //c2:��ʼλ�ã�app:��ĩβ׷��д.
    string WZ[4];
    WZ[0] = "��������ǣ�";
    WZ[1] = "����Ա��ǣ�";
    WZ[2] = "��������ǣ�";
    WZ[3] = "���ѧ���ǣ�";
    if (out.is_open()) //�ж���û�гɹ����ļ�,����ɹ����˾�����������.
    {
        out << WZ[0] << L1_xm << "\n"
            << WZ[1] << L1_xb << "\n"
            << WZ[2] << L1_nl << "\n"
            << WZ[3] << L1_xh << endl;
        out.close(); //�ر�����ļ�;
    }
}
void L_1::refile_L1(const char *WJMR)
{
    char LSCC[MAX];
    ifstream in(WJMR, ios::in);
    if (!in.is_open())
    {
        cout << "�ļ��򿪴���";
    }
    while (!in.eof()) //eof:������ļ������ļ�ĩβ��return��true;
    {                 //eof�鿴���һ�ζ��ļ������Ƿ�Ϊ�ļ����һ����¼��
                      //����ǣ��򷵻ط���ֵ������ļ��������ݣ�������.
        for (int i = 0; i < 4; i++)
        {
            in.getline(LSCC, MAX); //��ȡ�ַ��ĺ���;
            //c1:����������ַ�����,c2:��ȡ�ַ��ĸ���.
            cout << LSCC << endl;
        }
        cout << "���س������¸�ѧ����Ϣ" << endl;
        system("pause");
        cout << endl;
        if (in.eof() != 0)
        {
            cout << "�Ѿ�û����Ϣ��,���°��˵�ѡ���Ӧ����" << endl;
            break;
        }
    }
}
void L_1::in_L1(string &IN_mz, string &IN_xb, int &IN_nl, int &IN_xh)
{
    cout << "�����������:";
    cin >> IN_mz;
    cout << "��������Ա�(�л�Ů):";
    cin >> IN_xb;
    cout << "�����������:";
    cin >> IN_nl;
    cout << "�������ѧ��:";
    cin >> IN_xh;
}

#endif