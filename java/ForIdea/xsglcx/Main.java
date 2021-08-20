package xsglcx;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        File filesize=new File("datasize.siz");
        File filedata=new File("xsgl.dat");
        ZlkDataRq dx=new ZlkDataRq();
        Scanner in=new Scanner(System.in);
        dx.UIone();
        try {
            int datasize=0;
            datasize=dx.ObjRdsize(filesize);
            System.out.println("数据库已有"+datasize+"个学生信息");
            ZlkF[] data=dx.ObjRd(filedata, datasize);
            System.out.println("请输入学生名字用于查询资料库：");
            if(!dx.query(data,in.next(),datasize)){
                System.out.println("未找到此人信息.");
            }
            in.close();
        } catch (FileNotFoundException e){
            e.printStackTrace();
            System.out.println("FileError!!!");
        } catch (IOException | ClassNotFoundException
                |ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
            System.out.println("DataError!!!");
        }
    }
}
