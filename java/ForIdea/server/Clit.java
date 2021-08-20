package server;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Clit {
    public static void main(String[] args) {
        try {
            Scanner in=new Scanner(System.in);
            System.out.println("请输入要连接服务器的ip");
            Socket socket = new Socket(in.nextLine(), 25467);
            //由Socket对象得到输出流，并构造PrintWriter对象
            System.out.println("成功连接服务器<"+socket.getInetAddress()+">");
            System.out.println("输入发送至服务器的消息:");
            PrintWriter os = new PrintWriter(socket.getOutputStream());
            String readline=null;
            do{
                readline = in.nextLine(); //从系统标准输入读入一字符串
                //将从系统标准输入读入的字符串输出到Server
                os.println(readline);
                //刷新输出流，使Server马上收到该字符串
                os.flush();
                //在系统标准输出上打印读入的字符串
                if(readline.equals("bye")){
                    System.out.println("\f\f已断开服务器");
                    break;
                }else{
                    System.out.println("\f\f发送成功～");
                }
            } while (!readline.equals("bye"));
            os.close(); //关闭Socket输出流
            socket.close(); //关闭Socket
        } catch (Exception e) {
            e.printStackTrace();//出错，打印出错信息
        }

    }
}

