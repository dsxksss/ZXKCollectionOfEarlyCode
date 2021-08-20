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
    void SP_MZ_HS(); //商品内容总体函数;
    int SP_set(const int &SPBH, const string SPMZ, const int &SPKC,
               const float &SPJG); //参数1:商品编号;参数2:商品名字;参数3:商品库存;参数4:商品价格;
    int SP_print(L_1 &dx);         //装商品内容的对象;
                                   //void SP_CZ_HS();//商品名称查找函数;
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
    cout << "商品编号:" << dx.SP_BH << "  商品名字:" << dx.SP_MZ << "  商品价格:" << dx.SP_JG << "  商品库存:" << dx.SP_KC << "\n"
         << endl;
    return 0;
}

void L_1::SP_MZ_HS()
{
    L_1 SP[50]; //商品内容对象；
    SP[0] = SP_set(0, "胡萝卜", 30, 3.5);
    SP_print(SP[0]);
    SP[1] = SP_set(1, "牛奶", 40, 5.0);
    SP_print(SP[1]);
    SP[2] = SP_set(2, "巧克力", 32, 10.5);
    SP_print(SP[2]);
}

//完成增加商品信息的功能（待完成。。。）

//void L_1::SP_CZ_HS() {
//	cout << "按1选择商品" << endl;
//	int a = 0;
//	cin >> a;
//	if (a == 1) {
//		cout << "输入商品编号" << endl;
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
