package lx;

import java.util.Scanner;
class OpenException extends Exception{
}
class CloseException extends OpenException{
}
public class Yichang {
    public static void main(String[] args) {
        int[] a = new int[10];
        int idx;
        Scanner in = new Scanner(System.in);
        idx = in.nextInt();
        try {
            a[idx] = 10;
            System.out.println("hello");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("已捕捉异常！！！");
        }
    }
}



//class OpenException extends Throwable{
//
//}
//class OpenException2 extends Throwable{
//
//}

class Yichangone {
//    public static int fopen() {
//        return -1;
//    }
//    public static void readfile()throws OpenException{//<-这里。
//        if(fopen()==-1){
//            throw new OpenException();//抛出一个自己写的异常类
//            //异常类继承的是Throwable这个类的内容才可以被抛出。
//            //抛出了异常记得要给予代码处理才不会报错。
//            //有两种解决方法:
//            //一种是直接try/catch,抛出异常后程序不再继续运行
//            //还有一种就是在函数后加上throws <要抛出的异常类>。
//            //这句话表示这个函数可能会抛出某个异常的函数。
//            //也可以throws <异常类1>,<异常类2>抛出多个可能发生的异常
//            //异常声明了多个的话也得多加catch处理。
//        }
//    }


    public static int open(){
        return -1;
    }
    public static void readFile()throws
            OpenException,CloseException{
        if(open()==-1){
         throw new CloseException();
        }
    }
    public static void main(String[] args) {
        try{
            readFile();
        }catch (OpenException e){
            e.printStackTrace();
            System.out.println("已捕捉到其父类中的子类异常");
        }

    }
}