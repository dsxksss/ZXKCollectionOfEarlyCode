package xsglcx;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class MainStore {
    public static void main(String[] args) {
        File filesize = new File("datasize.siz");
        File filedata = new File("xsgl.dat");
        ZlkDataRq data = new ZlkDataRq();
        Scanner in = new Scanner(System.in);
        int size = 1;//一次程序存入数量;
        data.UIforStore();
        try {
            for (int i = 0; i < size; i++) {
                System.out.println("\n请输入第" + (i + 1) + "个学生信息:");
            data.add(new Zlk1("张三", 26,"北京市朝阳区"));
            data.add(new Zlk1("李四", 22,"北京市二环"));
            data.add(new Zlk1("王二狗", 21,"北京市三环"));
                //data.add(new Zlk1(in.next(), in.nextInt(), in.next()));
            }
            data.ObjWr(filedata);
            System.out.println("数据存入成功");
            int datasize = 0;
            if(!filesize.exists()){//判断是否存在该文件,如果没有将新建此文件
                data.Objwrsize(filesize);
                datasize+=data.ObjRdsize(filesize);
            }else {//如果已存在将正常写入size数据
                datasize = data.ObjRdsize(filesize);
                data.Objwrsize(filesize,3,datasize);
            }
            System.out.println("数据库已存" + data.ObjRdsize(filesize)
                    + "个学生信息");
            in.close();
        } catch (FileNotFoundException e) {
            //e.printStackTrace();
            System.out.print("\nFile Error!!!");
        } catch (IOException e) {
            e.printStackTrace();
            System.out.print("\n数据存入失败!!!");
        }
    }
}
