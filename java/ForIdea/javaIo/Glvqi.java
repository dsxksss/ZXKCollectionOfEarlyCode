package javaIo;

import java.io.*;
import java.nio.file.FileAlreadyExistsException;

public class Glvqi {
    public static void main(String[] args) {
     System.out.println("hello world");
     byte[] buf=new byte[10];//字节数组，char在java里是字符类型。
     for (int i=0;i< buf.length;i++){
      buf[i]=(byte) i;
     }
     try {
         //写入
         DataOutputStream out=new DataOutputStream(
                 new BufferedOutputStream(
                         new FileOutputStream("a.dat")));
         int i=123456;
         out.writeInt(i);//写入二进制整数
         out.close();//关闭流
         //读入
         DataInputStream in=new DataInputStream(
                 new BufferedInputStream(
                         new FileInputStream("a.dat")));
         int j=in.readInt();//将读到的二进制int型data赋值给j
         System.out.println(j);//输出j内容
         in.close();//关闭流
     } catch (IOException e){
         e.printStackTrace();
     }
    }
}
