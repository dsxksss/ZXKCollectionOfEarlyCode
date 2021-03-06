/*
socket/c++环境下的流程
第一部分　服务器端
　　一、创建服务器套接字（create）。
　　二、服务器套接字进行信息绑定（bind），并开始监听连接（listen）。
　　三、接受来自用户端的连接请求（accept）。
　　四、开始数据传输(send/receive)。
　　五、关闭套接字（closesocket）。
第二部分　客户端
　　一、创建客户套接字（create）。
　　二、与远程服务器进行连接（connect），如被接受则创建接收进程。
　　三、开始数据传输(send/receive)。
　　四、关闭套接字（closesocket）。
socket编程所需结构及函数注解
结构体类型注解
1-1-SOCKET:套接字类型
1-2-SOCKADDR_IN:存放地址/端口号/地址族
1-3-WSADATA:存放windows socket初始化信息
函数参数及作用注解
2-1-WSAStartup():进行相应的socket库绑定,
       参1:你要调用的socket版本
       参2:指向WSADATA数据结构的指针;
2-2-MAKEWORD():表示使用WINSOCK2版本.这个不是函数,是宏
2-3-socket():
       参1:描述协议族,INET属于ipv4
       参2:sock_stream创建套接字类型：tcp
       参3:0不指定协议，常用的协议有tcp、udp等;
2-4-inet_addr():将一个ip地址字符串转换成一个整数值
2-5-htons():将主机的无符号短整形数转换成网络字节顺序。
2-6-bind():与socket套接字绑定
       参1:待绑定套接字
       参2:标识绑定在哪个"地方"
       参3:这个"地方"的占地大小;
2-7-listen():仅被TCP类型的服务器程序调用，实现监听服务
       参1:要监听的目标套接字
       参2:指定了内核为此套接字排队的最大连接个数;
2-8-accept():接受客户端的请求
       参1:服务端目标套接字
       参2:客户端IP和端口信息等/地址包
       参3:地址包的大小;
2-9-send():向目标发送信息
       参1:对方socket
       参2:发送的内容
       参3:发送内容的大小
       参4:默认为0;
2-10-recv():接受目标发送的信息
       参1:对方socket
       参2:接收的内容
       参3:接收内容的大小
       参4:默认为0;
2-11connect():向服务端发送请求
       参1:客户端socket套接字
       参2:服务端IP和端口信息等/地址包
       参3:地址包的大小
*/
#include <iostream>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#define userMAX 10           //排队数，默认10人
#define userDKH 25467         //客户端端口号
#define serverDKH 25466       //服务器端口号
#define userIP "127.0.0.1"   //客户端ip
#define serverIP "103.91.211.138" //服务器端口ip
#pragma comment(lib, "ws2_32")
//===========全局常量=============
//创建缓冲区
const int BUF_SIZE = 2048;
//===========全局变量=============
SOCKET sockSer, sockCli;      //创建服务端/客户端的socket套接字1-1
SOCKADDR_IN addrSer, addrCli; //创建服务端/客户端的地址存放1-2
int naddr = sizeof(SOCKADDR_IN);

char sendBUF[BUF_SIZE];
char recvBUF[BUF_SIZE];
//===========函数声明=============
int main()
{
    //加载socket库
    std::cout << "客户端启动" << std::endl;
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        //输出出错信息
        std::cout << "载入socket库失败" << std::endl;
        system("pause");
        return 0;
    }
    //创建Soucket;
    sockCli = socket(AF_INET, SOCK_STREAM, 0);
    //描述协议族,INET属于ipv4；
    //sock_stream创建套接字类型：tcp；
    //0不指定协议，常用的协议有tcp、udp等

    //初始化客户端地址包
    addrCli.sin_addr.s_addr = inet_addr(userIP);
    addrCli.sin_family = AF_INET;
    addrCli.sin_port = htons(userDKH);

    //初始化服务器地址
    addrSer.sin_addr.s_addr = inet_addr(serverIP);
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(serverDKH);
    while (true)
    {
        if (connect(sockCli, (SOCKADDR *)&addrSer, sizeof(addrSer)) != SOCKET_ERROR)
        { //2-11
            std::cout << "服务器连接成功\n\n\n" << std::endl;
            while (true)
            {
                //接收服务器信息
                recv(sockCli, recvBUF, sizeof(recvBUF), 0);
                std::cout << "服务端发的信息:" << recvBUF << std::endl;
                //发送给服务器信息
                std::cout << "请输入要发送给服务器的信息:      ";
                std::cin >> sendBUF;
                send(sockCli, sendBUF, sizeof(sendBUF), 0);
            }
        }
        else
        {
            //cout << "客户端连接失败" << endl;
        }
    }
    closesocket(sockSer);
    closesocket(sockCli);
    WSACleanup();
    return 0;
}