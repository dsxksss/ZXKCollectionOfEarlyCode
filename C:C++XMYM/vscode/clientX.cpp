#include <winsock2.h>
#include <iostream>
#define userDKH 25467             //客户端端口号
#define serverDKH 25466           //服务器端口号
#define userIP "127.0.0.1"        //客户端ip
#define serverIP "103.91.211.138" //服务器端口ip
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    //加载winsocket2环境
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        std::cout << "加载socket库失败" << std::endl;
        system("pause");
        return 01;
    }
    else
    {
        std::cout << "加载socket库成功..." << std::endl;
    }

    //1、创建流式套接字
    SOCKET Slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Slisten == INVALID_SOCKET)
    {
        std::cout << "socket error" << GetLastError() << std::endl;
        system("pause");
        return 02;
    }
    else
    {
        std::cout << "正在连接服务器,请稍后....." << std::endl;
    }

    //2、连接服务器
    sockaddr_in Cliaddr;
    Cliaddr.sin_family = AF_INET;
    Cliaddr.sin_port = htons(serverDKH);
    Cliaddr.sin_addr.S_un.S_addr = inet_addr(serverIP);

    int DX = sizeof(sockaddr_in);
    if (connect(Slisten, (SOCKADDR *)&Cliaddr, DX) == SOCKET_ERROR)
    {
        std::cout << "连接失败" << GetLastError() << std::endl;
        system("pause");
        return 03;
    }

    //3、1-接受服务端的消息
    char buf[100] = {0};
    recv(Slisten, buf, 100, 0);
    std::cout << buf << std::endl;
    

    //3、2-随时给服务端发消息
    int ret = 0;
    do
    {
        char buf[100] = {0};
        std::cout << "请输入发送的聊天内容:   ";
        std::cin >> buf;
        ret = send(Slisten, buf, 100, 0);
    } while (ret != SOCKET_ERROR && ret != 0);

    //4、关闭监听套接字
    closesocket(Slisten);

    //清理winsocket2环境
    WSACleanup();

    return 0;
}