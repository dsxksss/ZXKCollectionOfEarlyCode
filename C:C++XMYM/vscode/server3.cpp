#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10
#define DKH 25466            //服务器端口号
#define serverIP "127.0.0.1" //服务器ip
#pragma comment(lib, "ws2_32")

SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;
int naddrdx = sizeof(SOCKADDR_IN);
char JSBUF[2048] = {};
void CSH_dzb()
{
    addrSer.sin_addr.s_addr = inet_addr(serverIP); //服务端ip地址
    addrSer.sin_family = AF_INET;                  //地址族
    addrSer.sin_port = htons(DKH);                 //端口号
}
int main()
{
    *JSBUF = 0;
    WSADATA wsadata;
    std::cout << "服务器启动中..." << std::endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    { //2-1、2-2
        //发生错误就输出以下内容
        std::cout << "载入socket库失败" << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "载入socket库成功" << std::endl;
    }
    sockSer = socket(AF_INET, SOCK_STREAM, 0);
    CSH_dzb();
    bind(sockSer, (SOCKADDR *)&addrSer, sizeof(SOCKADDR));
    while (true)
    {
        std::cout << "等待客户端连接中..." << std::endl;
        listen(sockSer, userMAX);
        sockCli = accept(sockSer, (SOCKADDR *)&addrCli, &naddrdx);
        //accept()成功时，返回非负整数，该整数是接收到套接字的描述符；出错时，
        //返回－1，相应地设定全局变量errno。

        if (sockCli != -1)
        {
            std::cout << "客户端已连接" << std::endl;
            while (true)
            {
                recv(sockCli, JSBUF, sizeof(JSBUF), 0);
                std::cout << "客户端内容:    " << JSBUF << std::endl;
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
            std::cout << "连接失败" << std::endl;
        }
    }
    closesocket(sockSer); //关闭服务端socket
    closesocket(sockCli); //关闭客户端socket
    WSACleanup();
    return 0;
}