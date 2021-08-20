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
#define userMAX 10
#define DKH 25466             //�������˿ں�
#define serverIP "127.0.0.1" //������ip
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
    std::cout << "������������..." << std::endl;
    //����socket��
    WSADATA wsadata; //1-3
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
    //����Soucket
    sockSer = socket(AF_INET, SOCK_STREAM, 0); //2-3
    //��ʼ����ַ��
    addrSer.sin_addr.s_addr = inet_addr(serverIP); //�����ip��ַ��2-4
    addrSer.sin_family = AF_INET;                  //��ַ��
    addrSer.sin_port = htons(DKH);                 //�˿ںš�2-5
    //��socket(bind)
    bind(sockSer, (SOCKADDR *)&addrSer, sizeof(SOCKADDR)); //2-6
    //socket���ư���"Э�飬 ip��ַ,  �˿ں�"������Ҫ�أ�
    //����������ͨ������bind������socket��������Ҫ�ذ�һ����;
    //ǿ�ƽ�SOCKADDR_INETת����SOCKEADDR;
    //���ü���
    while (true)
    {
        std::cout << "�ȴ��ͻ���������..." << std::endl;
        //������������;
        listen(sockSer, userMAX); //2-7
        //�ȴ����������
        //��������
        sockCli = accept(sockSer, (SOCKADDR *)&addrCli, &naddr); //2-8
        if (sockCli != INVALID_SOCKET)
        { //INVALID_SOCKET��ʾ���socket����
            std::cout << "�ͻ������ӳɹ�\n\n\n" << std::endl;
            while (true)//2-9,2-10
            {
                std::cout << "������Ҫ���͸��ͻ��˵���Ϣ:      ";
                std::cin >> sendBUF;                        //���洴���õ��ַ�������
                send(sockCli, sendBUF, sizeof(sendBUF), 0); //2-9��д
                recv(sockCli, recvBUF, sizeof(recvBUF), 0); //2-10����
                std::cout << "�ͻ��˷�������Ϣ:" << recvBUF << std::endl;
            }
        }
        else
        {
            std::cout << "����ʧ��" << std::endl;
        }
    }
    closesocket(sockSer); //�رշ����socket
    closesocket(sockCli); //�رտͻ���socket
    WSACleanup();
    return 0;
}