#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10                //�Ŷ�����Ĭ��10��
#define userDKH 25467             //�ͻ��˶˿ں�
#define serverDKH 25466           //�������˿ں�
#define userIP "127.0.0.1"        //�ͻ���ip
#define serverIP "103.91.211.138" //�������˿�ip
#pragma comment(lib, "ws2_32")

SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;
int naddrdx = sizeof(SOCKADDR_IN);
char FSBUF[2048] = {};

void CSH_dzb()
{
    //��ʼ���ͻ��˵�ַ��
    addrCli.sin_addr.s_addr = inet_addr(userIP);
    addrCli.sin_family = AF_INET;
    addrCli.sin_port = htons(userDKH);

    //��ʼ����������ַ
    addrSer.sin_addr.s_addr = inet_addr(serverIP);
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(serverDKH);
}

int main()
{
    *FSBUF = 0;
    WSADATA wsadata;
    std::cout << "�ͻ���������..." << std::endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    { //2-1��2-2
        //��������������������
        std::cout << "����socket��ʧ��" << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "�ͻ��������ɹ�" << std::endl;
    }
    sockCli = socket(AF_INET, SOCK_STREAM, 0);
    CSH_dzb();
    std::cout << "�������ӷ�����" << std::endl;
    while (true)
    {
        sockSer = connect(sockCli, (SOCKADDR *)&addrSer, sizeof(addrSer));
        if (sockSer == 0)
        {
            std::cout << "���������ӳɹ�" << std::endl;
            std::cout << "�ͻ���20���ʼ�����Ե�......" << std::endl;
            Sleep(20000);
            std::cout << "$$$$$�ͻ��˳�ʼ�����$$$$$\n\n\n"
                      << std::endl;
            while (true)
            {
                std::cout << "����Ҫ���͵�����:     ";
                Sleep(300);
                std::cin >> FSBUF;
                Sleep(1000);
                send(sockCli, FSBUF, sizeof(FSBUF), 0);
            }
        }
    }
    closesocket(sockSer); //�رշ����socket
    closesocket(sockCli); //�رտͻ���socket
    WSACleanup();
    return 0;
}