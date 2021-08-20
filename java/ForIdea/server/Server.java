package server;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;
import java.util.Scanner;

public class Server {
    private Socket socket=null;

    public  Server(ServerSocket serverSocket) {
        try {
            System.out.println("等待客户端连接中...");
            this.socket=serverSocket.accept();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("serverSocket异常抛出");
            System.out.println("处理异常或重新运行程序");
        }
    }
    public Socket getSocket(){
        return socket;
    }
    public void close(){

    }
    public static void main(String[] args) {
        try {
            System.out.println("请输入服务器要开启的端口");
            Scanner in=new Scanner(System.in);
            Server server=new Server(new ServerSocket(in.nextInt()));
            System.out.println("客户端<" + server.getSocket().getInetAddress() + ">已连接");
            InputStreamReader isr = new InputStreamReader(server.getSocket().getInputStream());
            BufferedReader br = new BufferedReader(isr);
            while (true) {
                String date = br.readLine();
                if (date != null) {
                    System.out.println("客户端<"+server.getSocket().getInetAddress()+">:"+date);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
