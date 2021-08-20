package javaIo;

import java.io.*;

public class Wengbenliu {
    public static void main(String[] args) {
        try {
            //写入
            PrintWriter out=new PrintWriter(
                    new BufferedOutputStream(
                            new FileOutputStream("a.txt")));
            //在BufferedOutputStream后面还可以加一个参数表示要写入的是
            //某种规定的编码格式，而不是让他帮你自动猜
            String buf="我是一串字符";
            out.print(buf);
            out.close();//关闭流
            //读入
            BufferedReader in=new BufferedReader(
                    new InputStreamReader(
                            new FileInputStream("a.txt")));
            //一般我们使用这种手段来读取完整的文件。
            String line;
            while((line=in.readLine())!=null){
                System.out.println(line);
            }
            in.close();//关闭流
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
