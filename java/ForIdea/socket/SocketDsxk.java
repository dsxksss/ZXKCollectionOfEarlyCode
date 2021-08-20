package socket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class SocketDsxk {
    private ServerSocket serverSocket;//服务器地址服务
    private Socket socket;//socket创建
    public SocketDsxk(int port) {
        super();
        try {
            this.serverSocket = new ServerSocket(port);//利用构造,服务器接收一个端口并设置.
            this.socket = null;
            System.out.println("[服务器已开启]");
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("构造错误:< SocketDsxk(int port) >!!!");
        }
    }

    public SocketDsxk(String ip, int port) {//利用构造,设置客户端要连接的目标ip与端口
        super();
        try {
            this.socket = new Socket(ip, port);
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("构造错误:< SocketDsxk(String ip,int port) >!!!");
        }
    }

    public Socket accept() {//阻塞等待客户端连接服务器
        try {
            this.socket = this.serverSocket.accept();
            System.out.println("客户端<"+socket.getInetAddress()+">已连接服务器");
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< accept() >!!!");
        }
        return this.socket;
    }

    public void createOutStream(String buffer) {//单次写入信息至客户端
        try {
            PrintWriter out = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    this.socket.getOutputStream())));
            out.println(buffer);
            out.flush();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createOutStream(String buffer) >!!!");
        }
    }

    public void createOutStream() {//持续写入数据至客户端遇到";,;"字符则断开
        Scanner in = new Scanner(System.in);
        try {
            PrintWriter out = new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    this.socket.getOutputStream())));
            String buffer;
            do {
                buffer = in.next();
                out.println(buffer);
                out.flush();
            } while (buffer.equals(";,;"));
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createOutStream() >!!!");
        }
    }

    public void createInStream(Socket socket,int num) {//按设置好的次数读取目标流
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
            String line;
            for (int i = 0; i <= num; i++) {
                line = in.readLine();
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createInStream(int num) >!!!");
        }
    }
    public void createInStream(int num) {//按设置好的次数读取目标流
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            this.socket.getInputStream()));
            String line;
            for (int i = 0; i <= num; i++) {
                line = in.readLine();
                System.out.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createInStream(int num) >!!!");
        }
    }

    public void createInStream(Socket socket) {//循环读取目标的数据/遇到";,;"字符则断开
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
            String line;
            do {
                line=in.readLine();
                System.out.println(line);
            } while (line.equals(";,;"));
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createInStream() >!!!");
        }
    }

    public void createInStream() {//循环读取目标的数据/遇到";,;"字符则断开
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            this.socket.getInputStream()));
            String line;
            do {
                line=in.readLine();
                System.out.println(line);
            } while (line.equals(";,;"));
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< createInStream() >!!!");
        }
    }

    public boolean isConnected() {//判断当前客户端是否还在连接
        if (this.socket.isConnected()) {
            return true;
        }
        return false;
    }

    public void closeSocket() {//关闭socket
        try {
            this.socket.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< closeSocket() >!!!");
        }
    }

    public void closeServerSocketClose() {//关闭serverSocket
        try {
            this.serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< closeServerSocketClose >!!!");
        }
    }

    public void closeAll() {//关闭所有资源
        try {
            this.serverSocket.close();
            this.socket.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("错误:< closeAll() >!!!");
        }
    }

    public void uiServer(){
        System.out.println("==================================================");
        System.out.println("||   =======*+          |*|      |*|      *+*   ||");
        System.out.println("||   |*       **        |*|      |*|     **     ||");
        System.out.println("||   |*        **       |*|      |*|   +*       ||");
        System.out.println("||   |*         **      |*|      |*|**++        ||");
        System.out.println("||   |*        **       |*|      |*|   +*       ||");
        System.out.println("||   |*       **        |*|      |*|     **     ||");
        System.out.println("||   =======*+          |*|      |*|      *+*   ||");
        System.out.println("==================================================");
        System.out.println("*=*=*=*=*=*=*=*=");
        System.out.println("等待客户端连接...*");
        System.out.println("*=*=*=*=*=*=*=*=");

    }

    public String toString() {
        return "此对象是SocketDsxk对象";
    }
}
