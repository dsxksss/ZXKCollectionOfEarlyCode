#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10
#define DKH 25466            //�������˿ں�
#define serverIP "127.0.0.1" //������ip
#pragma comment(lib, "ws2_32")

SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;
int naddrdx = sizeof(SOCKADDR_IN);
char JSBUF[2048] = {};
void CSH_dzb()
{
    addrSer.sin_addr.s_addr = inet_addr(serverIP); //�����ip��ַ
    addrSer.sin_family = AF_INET;                  //��ַ��
    addrSer.sin_port = htons(DKH);                 //�˿ں�
}
int main()
{
    *JSBUF = 0;
    WSADATA wsadata;
    std::cout << "������������..." << std::endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    { //2-1��2-2
        //��������������������
        std::cout << "����socket��ʧ��" << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "����socket��ɹ�" << std::endl;
    }
    sockSer = socket(AF_INET, SOCK_STREAM, 0);
    CSH_dzb();
    bind(sockSer, (SOCKADDR *)&addrSer, sizeof(SOCKADDR));
    while (true)
    {
        std::cout << "�ȴ��ͻ���������..." << std::endl;
        listen(sockSer, userMAX);
        sockCli = accept(sockSer, (SOCKADDR *)&addrCli, &naddrdx);
        //accept()�ɹ�ʱ�����طǸ��������������ǽ��յ��׽��ֵ�������������ʱ��
        //���أ�1����Ӧ���趨ȫ�ֱ���errno��

        if (sockCli != -1)
        {
            std::cout << "�ͻ���������" << std::endl;
            while (true)
            {
                recv(sockCli, JSBUF, sizeof(JSBUF), 0);
                std::cout << "�ͻ�������:    " << JSBUF << std::endl;
                Sleep(1700);
                if (*JSBUF == 0)
                {
                    break;
                }
                *JSBUF = 0;
            }
        }
        else if (sockCli == -1)
        {
            std::cout << "����ʧ��" << std::endl;
        }
    }
    closesocket(sockSer); //�رշ����socket
    closesocket(sockCli); //�رտͻ���socket
    WSACleanup();
    return 0;
}