package javaIo;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Zjieliu {
    public static void wrte(File file)throws IOException {
        //缓冲字节流提高效率
        BufferedOutputStream bis=new BufferedOutputStream
                (new FileOutputStream(file,true));
        //要写入的字符串
        String buff="我是一段即将被存入的文字";
        //开始写入
        bis.write(buff.getBytes(StandardCharsets.UTF_8));
        //关闭流.
        bis.close();
    }
    public static String read(File file)throws IOException{
        BufferedInputStream bos=new BufferedInputStream
                (new FileInputStream(file));
        //创建一个一次性取多少个字节的数组
        byte[] bytes=new byte[1024];
        //接收读取的字节数组
        StringBuilder sb=new StringBuilder();
        //读取到的字节数组长度,为-1时表示没有数据
        int length=0;
        //循环读取数据
        while ((length=bos.read(bytes))!=-1){
            //将读取到的字节数据转换成字符串
            sb.append(new String(bytes,0,length));
        }
        //关闭流
        bos.close();

        return sb.toString();
    }
    public static void main(String[] args) {
        File file=new File("/Users/zhangxiaokang/Desktop/dsxk.txt");
        try {
            //wrte(file);
            //输出已写入的内容到屏幕上。
            System.out.println(read(file));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}