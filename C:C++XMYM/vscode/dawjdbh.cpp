#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class L_1
{
private:
    int SP_BH, SP_KC;
    float SP_JG;
    string SP_MZ;

public:
    L_1(int a = 0, string b = "NULL", int c = 0, float d = 0.0)
        : SP_BH(a), SP_MZ(b), SP_KC(c), SP_JG(d) {}
    //~L_1(){}
    void SP_MZ_HS(); //��Ʒ�������庯��;
    int SP_set(const int &SPBH, const string SPMZ, const int &SPKC,
               const float &SPJG); //����1:��Ʒ���;����2:��Ʒ����;����3:��Ʒ���;����4:��Ʒ�۸�;
    int SP_print(L_1 &dx);         //װ��Ʒ���ݵĶ���;
                                   //void SP_CZ_HS();//��Ʒ���Ʋ��Һ���;
};
int L_1::SP_set(const int &SPBH, const string SPMZ, const int &SPKC,
                const float &SPJG)
{
    L_1 CK;
    CK.SP_BH = SPBH;
    CK.SP_MZ = SPMZ;
    CK.SP_KC = SPKC;
    CK.SP_JG = SPJG;
    return 0;
}
int L_1::SP_print(L_1 &dx)
{
    cout << "��Ʒ���:" << dx.SP_BH << "  ��Ʒ����:" << dx.SP_MZ << "  ��Ʒ�۸�:" << dx.SP_JG << "  ��Ʒ���:" << dx.SP_KC << "\n"
         << endl;
    return 0;
}

void L_1::SP_MZ_HS()
{
    L_1 SP[50]; //��Ʒ���ݶ���
    SP[0] = SP_set(0, "���ܲ�", 30, 3.5);
    SP_print(SP[0]);
    SP[1] = SP_set(1, "ţ��", 40, 5.0);
    SP_print(SP[1]);
    SP[2] = SP_set(2, "�ɿ���", 32, 10.5);
    SP_print(SP[2]);
}

//���������Ʒ��Ϣ�Ĺ��ܣ�����ɡ�������

//void L_1::SP_CZ_HS() {
//	cout << "��1ѡ����Ʒ" << endl;
//	int a = 0;
//	cin >> a;
//	if (a == 1) {
//		cout << "������Ʒ���" << endl;
//
//	}
//}

int main()
{
    L_1 A;
    A.SP_MZ_HS();
    //A.SP_CZ_HS();
    system("pause");
    return 0;
}
