package xsglcx;//包名

import java.io.*;
import java.util.ArrayList;

public class ZlkDataRq {//类名对应文件名字
    private ArrayList<ZlkF> SJK = new ArrayList<ZlkF>();

    //创建了一个大容器,存放类型是ZlkF
    public void add(ZlkF zlkF) {
        SJK.add(zlkF);
        //接收一个ZlfK的父类或子类的对象,并使用其对象的add函数
    }

    public int getSize() {
        return SJK.size();
    }

    public ZlkF get(int num) {
        return SJK.get(num);
    }

    public void remove(int num) {
        SJK.remove(num);
    }

    public void list() {
        for (int i = 0; i < SJK.size(); i++) {
            System.out.println(SJK.get(i));
        }
    }

    public void ObjWr(File file)
            throws IOException {
        ObjectOutputStream out = new ObjectOutputStream(
                new FileOutputStream(file, true));
        //上面参数true是表示不覆盖文件,追加写入数据,反之false为覆盖文件内容新建。
        for (ZlkF zlkF : SJK) {
            out.writeObject(zlkF);
            out.flush();
        }
        out.close();//读完全部再关闭流
    }

    public void Objwrsize(File file, int a,int b) throws IOException {
        DataOutputStream out = new DataOutputStream(
                new BufferedOutputStream(
                        new FileOutputStream(file)));
        out.writeInt((a+b));//写入二进制整数
        out.close();//关闭流
    }
    public void Objwrsize(File file) throws IOException {
        DataOutputStream out = new DataOutputStream(
                new BufferedOutputStream(
                        new FileOutputStream(file)));
        out.writeInt(3);//写入二进制整数
        out.close();//关闭流
    }
    public ZlkF[] ObjRd(File file, int size)
            throws IOException, ClassNotFoundException {
        ObjectInputStream in = new ObjectInputStream(
                new FileInputStream(file));
        ZlkF[] a = new ZlkF[size];
        for (int i = 0; i < size; i++) {
            a[i] = (ZlkF) in.readObject();
            //System.out.println(a[i]);
        }
        in.close();
        return a;
    }

    public int ObjRdsize(File file) throws IOException {
        DataInputStream in = new DataInputStream(
                new BufferedInputStream(
                        new FileInputStream(file)));
        int j = 0;
        j=in.readInt();
        in.close();
        return j;
    }

    public boolean query(ZlkF[] data, String name,int size) throws
            ArrayIndexOutOfBoundsException {
        for (int i = 0; i < size; i++) {
            //System.out.println("查询第" + (i + 1) + "次:");
            if (data[i].namequery(name)) {
                System.out.println("已查询到:\n"+data[i]);
                return true;
            }
        }
        return false;
    }

    public String toString() {
        return SJK.toString();
    }

    public void UIforStore() {
        System.out.print("按顺序依次输入\n1、学生名字\n2、" +
                "学生年龄\n3、学生住址");
    }

    public void UIone() {
        System.out.println("================");
        System.out.println("=--学生管理程序--=");
        System.out.println("================");
    }

}
