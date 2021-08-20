#include <winsock2.h>
#include <iostream>
#define serverIP "127.0.0.1" //������ip
#define DKH 25466            //�������˿ں�
#pragma comment(lib, "Ws2_32.lib")
int main()
{
    //��ʼ��winsocket2����;
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) == SOCKET_ERROR)
    {
        std::cout << "����socket��ʧ��" << std::endl;
        system("pause");
        return 01;
    }
    else
    {
        std::cout << "����socket��ɹ�..." << std::endl;
    }

    //1����������socket�׽���;
    SOCKET Slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    ////////////1:ipv4,2:socket����,3:ָ��Э��;/////////////////
    if (Slisten == INVALID_SOCKET)
    {
        std::cout << "socket error!!!" << std::endl;
        system("pause");
        return 02;
    }
    else
    {
        std::cout << "����socket��ɹ�..." << std::endl;
    }

    //2���󶨶˿���ip��ַ
    sockaddr_in Sreaddr;
    Sreaddr.sin_addr.S_un.S_addr = inet_addr(serverIP);
    Sreaddr.sin_port = htons(DKH);
    Sreaddr.sin_family = AF_INET;//ipv4Э��
    int DX = sizeof(sockaddr_in);
    if ((bind(Slisten, (SOCKADDR *)&Sreaddr, DX) == SOCKET_ERROR))
    {
        std::cout << "bind error!!!" << std::endl;
        system("pause");
        return 03;
    }
    else
    {
        std::cout << "����bind�ɹ�...\n" << std::endl;
    }

    //3�������׽���
    if (listen(Slisten, 5) == SOCKET_ERROR)
    {
        std::cout << "listen erroe!!!" << std::endl;
        system("pause");
        return 04;
    }
    else
    {
        std::cout << "--------����������-------" << std::endl;
        std::cout << "------�ȴ��ͻ�������------" << std::endl;
    }

    //4��select��ʼ
    fd_set readSet;    //����һ������������Ϣ���ļ���
    FD_ZERO(&readSet); //��ʼ�����涨��ļ���^^^
    FD_SET(Slisten, &readSet);
    //��ͣ��select�ſ��Զ�ȡ�׽��ֵ�״̬�ı�
    while (true)
    {
        fd_set tmpSet;    //����һ����ʱ�ļ���
        FD_ZERO(&tmpSet); //��ʼ�������ʱ�ļ���
        tmpSet = readSet; //ÿ��ѭ���������е��׽���

        //����selectѡ��������п��Զ�д�Ķ���׽��֣�������ɸѡ
        int ret = select(0, &tmpSet, NULL, NULL, NULL);
        //////���һ������ΪNULL,һֻ�ȴ�,ֱ�������ݹ���//////
        if (ret == SOCKET_ERROR)
        {
            continue;
        }

        //�ɹ�ɸѡ������tmpSet���Է��ͻ��߽��ܵ�socket
        for (int i = 0; i < tmpSet.fd_count; ++i)
        {
            //��ȡ���׽���
            SOCKET ser = tmpSet.fd_array[i];

            //���ܵ��ͻ��˵�����
            if (ser == Slisten)
            {
                SOCKET cli = accept(ser, NULL, NULL);
                //fd_set�������ֵΪ64
                if (readSet.fd_count < FD_SETSIZE)
                {
                    FD_SET(cli, &readSet);
                    std::cout << "��" << cli << "��"
                              << "���������" << std::endl;

                    //��ͻ��˷�����ʾ��Ϣ
                    char BUF[100] = {0};
                    sprintf(BUF, "---�ɹ����������---", cli);
                    send(cli, BUF, 100, 0);
                }
                else
                {
                    std::cout << "----!!!����������!!!----" << std::endl;
                }
            }
            //ȷ���ͻ���
            else
            {
                //���ܿͻ��˵�����
                char buf[100] = {0};
                ret = recv(ser, buf, 100, 0);
                if (ret == SOCKET_ERROR || ret == 0)
                {
                    closesocket(ser);
                    FD_CLR(ser, &readSet);
                    std::cout << "��" << ser << "��"
                              << "�뿪������~~~" << std::endl;
                }
                else
                {
                    std::cout<<ser<<"˵��   "<<buf<<std::endl;
                }
            }
        }
    }
    //�رռ����׽���
    closesocket(Slisten);

    //����winsocke����
    WSACleanup();

    return 0;
}