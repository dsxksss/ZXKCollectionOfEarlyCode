package javaIo;

import java.io.*;

class Data implements Serializable {
    private String name;
    private int age;
    private String local;

    public Data(String name, int age, String local) {
        this.name = name;
        this.age = age;
        this.local = local;
    }

    public String toString(){
        return name+" "+age+" "+local;
    }
}

public class DuixianIO {
    public static void main(String[] args) {
        Data data=new Data("张三",24,"朝阳区某某某");
        try {
            ObjectOutputStream out=new ObjectOutputStream(
                    new FileOutputStream("DataObj.dat"));
            out.writeObject(data);//将对象以二进制方式存入目标文件
            out.close();//关闭写入流
            ObjectInputStream in=new ObjectInputStream(
                    new FileInputStream("DataObj.dat"));
            Data data1=(Data) in.readObject();
            //因为返回的是一个Obj对象,我们可以转换成Data对象,
            //因为所有对象都是obj类的子类,我们可以向下造型。
            System.out.println(data1);
            System.out.println(data==data1);
            //它们的内容虽然一样但是空间不一样!
            in.close();//关闭读入流
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
}
