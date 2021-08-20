package javaIo;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
//客户端
public class Wkaisocket {
    public static void main(String[] args) {
        try {
            Socket socket=new Socket(InetAddress.
                    getByName("localhost"),25466);
            PrintWriter out=new PrintWriter(
                    new BufferedWriter(
                            new OutputStreamWriter(
                                    socket.getOutputStream())));
            out.println("hello");//向服务端写入
            out.flush();//冲刷流data
            BufferedReader in=new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
            String line=in.readLine();
            System.out.println(line);
            out.close();//关闭写入流
            in.close();//关闭读入流
            socket.close();//关闭socket
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
