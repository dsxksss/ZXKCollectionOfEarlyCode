#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10                //排队数，默认10人
#define userDKH 25467             //客户端端口号
#define serverDKH 25466           //服务器端口号
#define userIP "127.0.0.1"        //客户端ip
#define serverIP "103.91.211.138" //服务器端口ip
#pragma comment(lib, "ws2_32")

SOCKET sockSer, sockCli;
SOCKADDR_IN addrSer, addrCli;
int naddrdx = sizeof(SOCKADDR_IN);
char FSBUF[2048] = {};

void CSH_dzb()
{
    //初始化客户端地址包
    addrCli.sin_addr.s_addr = inet_addr(userIP);
    addrCli.sin_family = AF_INET;
    addrCli.sin_port = htons(userDKH);

    //初始化服务器地址
    addrSer.sin_addr.s_addr = inet_addr(serverIP);
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(serverDKH);
}

int main()
{
    *FSBUF = 0;
    WSADATA wsadata;
    std::cout << "客户端启动中..." << std::endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    { //2-1、2-2
        //发生错误就输出以下内容
        std::cout << "载入socket库失败" << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "客户端启动成功" << std::endl;
    }
    sockCli = socket(AF_INET, SOCK_STREAM, 0);
    CSH_dzb();
    std::cout << "正在连接服务器" << std::endl;
    while (true)
    {
        sockSer = connect(sockCli, (SOCKADDR *)&addrSer, sizeof(addrSer));
        if (sockSer == 0)
        {
            std::cout << "服务器连接成功" << std::endl;
            std::cout << "客户端20秒初始化请稍等......" << std::endl;
            Sleep(20000);
            std::cout << "$$$$$客户端初始化完成$$$$$\n\n\n"
                      << std::endl;
            while (true)
            {
                std::cout << "输入要发送的内容:     ";
                Sleep(300);
                std::cin >> FSBUF;
                Sleep(1000);
                send(sockCli, FSBUF, sizeof(FSBUF), 0);
            }
        }
    }
    closesocket(sockSer); //关闭服务端socket
    closesocket(sockCli); //关闭客户端socket
    WSACleanup();
    return 0;
}