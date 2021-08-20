/*
socket/c++�����µ�����
��һ���֡���������
����һ�������������׽��֣�create����
���������������׽��ֽ�����Ϣ�󶨣�bind��������ʼ�������ӣ�listen����
�����������������û��˵���������accept����
�����ġ���ʼ���ݴ���(send/receive)��
�����塢�ر��׽��֣�closesocket����
�ڶ����֡��ͻ���
����һ�������ͻ��׽��֣�create����
����������Զ�̷������������ӣ�connect�����类�����򴴽����ս��̡�
����������ʼ���ݴ���(send/receive)��
�����ġ��ر��׽��֣�closesocket����
socket�������ṹ������ע��
�ṹ������ע��
1-1-SOCKET:�׽�������
1-2-SOCKADDR_IN:��ŵ�ַ/�˿ں�/��ַ��
1-3-WSADATA:���windows socket��ʼ����Ϣ
��������������ע��
2-1-WSAStartup():������Ӧ��socket���,
       ��1:��Ҫ���õ�socket�汾
       ��2:ָ��WSADATA���ݽṹ��ָ��;
2-2-MAKEWORD():��ʾʹ��WINSOCK2�汾.������Ǻ���,�Ǻ�
2-3-socket():
       ��1:����Э����,INET����ipv4
       ��2:sock_stream�����׽������ͣ�tcp
       ��3:0��ָ��Э�飬���õ�Э����tcp��udp��;
2-4-inet_addr():��һ��ip��ַ�ַ���ת����һ������ֵ
2-5-htons():���������޷��Ŷ�������ת���������ֽ�˳��
2-6-bind():��socket�׽��ְ�
       ��1:�����׽���
       ��2:��ʶ�����ĸ�"�ط�"
       ��3:���"�ط�"��ռ�ش�С;
2-7-listen():����TCP���͵ķ�����������ã�ʵ�ּ�������
       ��1:Ҫ������Ŀ���׽���
       ��2:ָ�����ں�Ϊ���׽����Ŷӵ�������Ӹ���;
2-8-accept():���ܿͻ��˵�����
       ��1:�����Ŀ���׽���
       ��2:�ͻ���IP�Ͷ˿���Ϣ��/��ַ��
       ��3:��ַ���Ĵ�С;
2-9-send():��Ŀ�귢����Ϣ
       ��1:�Է�socket
       ��2:���͵�����
       ��3:�������ݵĴ�С
       ��4:Ĭ��Ϊ0;
2-10-recv():����Ŀ�귢�͵���Ϣ
       ��1:�Է�socket
       ��2:���յ�����
       ��3:�������ݵĴ�С
       ��4:Ĭ��Ϊ0;
2-11connect():�����˷�������
       ��1:�ͻ���socket�׽���
       ��2:�����IP�Ͷ˿���Ϣ��/��ַ��
       ��3:��ַ���Ĵ�С
*/
#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10           //�Ŷ�����Ĭ��10��
#define userDKH 25467         //�ͻ��˶˿ں�
#define serverDKH 25466       //�������˿ں�
#define userIP "127.0.0.1"   //�ͻ���ip
#define serverIP "103.91.211.138" //�������˿�ip
#pragma comment(lib, "ws2_32")
//===========ȫ�ֳ���=============
//����������
const int BUF_SIZE = 2048;
//===========ȫ�ֱ���=============
SOCKET sockSer, sockCli;      //���������/�ͻ��˵�socket�׽���1-1
SOCKADDR_IN addrSer, addrCli; //���������/�ͻ��˵ĵ�ַ���1-2
int naddr = sizeof(SOCKADDR_IN);

char sendBUF[BUF_SIZE];
char recvBUF[BUF_SIZE];
//===========��������=============
int main()
{
    //����socket��
    std::cout << "�ͻ�������" << std::endl;
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        //���������Ϣ
        std::cout << "����socket��ʧ��" << std::endl;
        system("pause");
        return 0;
    }
    //����Soucket;
    sockCli = socket(AF_INET, SOCK_STREAM, 0);
    //����Э����,INET����ipv4��
    //sock_stream�����׽������ͣ�tcp��
    //0��ָ��Э�飬���õ�Э����tcp��udp��

    //��ʼ���ͻ��˵�ַ��
    addrCli.sin_addr.s_addr = inet_addr(userIP);
    addrCli.sin_family = AF_INET;
    addrCli.sin_port = htons(userDKH);

    //��ʼ����������ַ
    addrSer.sin_addr.s_addr = inet_addr(serverIP);
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(serverDKH);
    while (true)
    {
        if (connect(sockCli, (SOCKADDR *)&addrSer, sizeof(addrSer)) != SOCKET_ERROR)
        { //2-11
            std::cout << "���������ӳɹ�\n\n\n" << std::endl;
            while (true)
            {
                //���շ�������Ϣ
                recv(sockCli, recvBUF, sizeof(recvBUF), 0);
                std::cout << "����˷�����Ϣ:" << recvBUF << std::endl;
                //���͸���������Ϣ
                std::cout << "������Ҫ���͸�����������Ϣ:      ";
                std::cin >> sendBUF;
                send(sockCli, sendBUF, sizeof(sendBUF), 0);
            }
        }
        else
        {
            //cout << "�ͻ�������ʧ��" << endl;
        }
    }
    closesocket(sockSer);
    closesocket(sockCli);
    WSACleanup();
    return 0;
}