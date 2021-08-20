#include <winsock2.h>
#include <iostream>
#define userDKH 25467             //�ͻ��˶˿ں�
#define serverDKH 25466           //�������˿ں�
#define userIP "127.0.0.1"        //�ͻ���ip
#define serverIP "103.91.211.138" //�������˿�ip
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    //����winsocket2����
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        std::cout << "����socket��ʧ��" << std::endl;
        system("pause");
        return 01;
    }
    else
    {
        std::cout << "����socket��ɹ�..." << std::endl;
    }

    //1��������ʽ�׽���
    SOCKET Slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Slisten == INVALID_SOCKET)
    {
        std::cout << "socket error" << GetLastError() << std::endl;
        system("pause");
        return 02;
    }
    else
    {
        std::cout << "�������ӷ�����,���Ժ�....." << std::endl;
    }

    //2�����ӷ�����
    sockaddr_in Cliaddr;
    Cliaddr.sin_family = AF_INET;
    Cliaddr.sin_port = htons(serverDKH);
    Cliaddr.sin_addr.S_un.S_addr = inet_addr(serverIP);

    int DX = sizeof(sockaddr_in);
    if (connect(Slisten, (SOCKADDR *)&Cliaddr, DX) == SOCKET_ERROR)
    {
        std::cout << "����ʧ��" << GetLastError() << std::endl;
        system("pause");
        return 03;
    }

    //3��1-���ܷ���˵���Ϣ
    char buf[100] = {0};
    recv(Slisten, buf, 100, 0);
    std::cout << buf << std::endl;
    

    //3��2-��ʱ������˷���Ϣ
    int ret = 0;
    do
    {
        char buf[100] = {0};
        std::cout << "�����뷢�͵���������:   ";
        std::cin >> buf;
        ret = send(Slisten, buf, 100, 0);
    } while (ret != SOCKET_ERROR && ret != 0);

    //4���رռ����׽���
    closesocket(Slisten);

    //����winsocket2����
    WSACleanup();

    return 0;
}