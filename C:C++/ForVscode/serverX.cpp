#include <winsock2.h>
#include <iostream>
#define serverIP "127.0.0.1" //服务器ip
#define DKH 25466            //服务器端口号
#pragma comment(lib, "Ws2_32.lib")
int main()
{
    //初始化winsocket2环境;
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) == SOCKET_ERROR)
    {
        std::cout << "加载socket库失败" << std::endl;
        system("pause");
        return 01;
    }
    else
    {
        std::cout << "加载socket库成功..." << std::endl;
    }

    //1、创建监听socket套接字;
    SOCKET Slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    ////////////1:ipv4,2:socket类型,3:指定协议;/////////////////
    if (Slisten == INVALID_SOCKET)
    {
        std::cout << "socket error!!!" << std::endl;
        system("pause");
        return 02;
    }
    else
    {
        std::cout << "创建socket库成功..." << std::endl;
    }

    //2、绑定端口与ip地址
    sockaddr_in Sreaddr;
    Sreaddr.sin_addr.S_un.S_addr = inet_addr(serverIP);
    Sreaddr.sin_port = htons(DKH);
    Sreaddr.sin_family = AF_INET;//ipv4协议
    int DX = sizeof(sockaddr_in);
    if ((bind(Slisten, (SOCKADDR *)&Sreaddr, DX) == SOCKET_ERROR))
    {
        std::cout << "bind error!!!" << std::endl;
        system("pause");
        return 03;
    }
    else
    {
        std::cout << "创建bind成功...\n" << std::endl;
    }

    //3、监听套接字
    if (listen(Slisten, 5) == SOCKET_ERROR)
    {
        std::cout << "listen erroe!!!" << std::endl;
        system("pause");
        return 04;
    }
    else
    {
        std::cout << "--------监听连接中-------" << std::endl;
        std::cout << "------等待客户端连接------" << std::endl;
    }

    //4、select开始
    fd_set readSet;    //定义一个读（接受消息）的集合
    FD_ZERO(&readSet); //初始化上面定义的集合^^^
    FD_SET(Slisten, &readSet);
    //不停的select才可以读取套接字的状态改变
    while (true)
    {
        fd_set tmpSet;    //定义一个临时的集合
        FD_ZERO(&tmpSet); //初始化这个临时的集合
        tmpSet = readSet; //每次循环都是所有的套接字

        //利用select选择出集合中可以读写的多个套接字，类似于筛选
        int ret = select(0, &tmpSet, NULL, NULL, NULL);
        //////最后一个参数为NULL,一只等待,直到有数据过来//////
        if (ret == SOCKET_ERROR)
        {
            continue;
        }

        //成功筛选出来的tmpSet可以发送或者接受的socket
        for (int i = 0; i < tmpSet.fd_count; ++i)
        {
            //获取到套接字
            SOCKET ser = tmpSet.fd_array[i];

            //接受到客户端的链接
            if (ser == Slisten)
            {
                SOCKET cli = accept(ser, NULL, NULL);
                //fd_set集合最大值为64
                if (readSet.fd_count < FD_SETSIZE)
                {
                    FD_SET(cli, &readSet);
                    std::cout << "【" << cli << "】"
                              << "进入服务器" << std::endl;

                    //向客户端发送提示消息
                    char BUF[100] = {0};
                    sprintf(BUF, "---成功加入服务器---", cli);
                    send(cli, BUF, 100, 0);
                }
                else
                {
                    std::cout << "----!!!服务器已满!!!----" << std::endl;
                }
            }
            //确定客户端
            else
            {
                //接受客户端的数据
                char buf[100] = {0};
                ret = recv(ser, buf, 100, 0);
                if (ret == SOCKET_ERROR || ret == 0)
                {
                    closesocket(ser);
                    FD_CLR(ser, &readSet);
                    std::cout << "【" << ser << "】"
                              << "离开服务器~~~" << std::endl;
                }
                else
                {
                    std::cout<<ser<<"说：   "<<buf<<std::endl;
                }
            }
        }
    }
    //关闭监听套接字
    closesocket(Slisten);

    //清理winsocke环境
    WSACleanup();

    return 0;
}