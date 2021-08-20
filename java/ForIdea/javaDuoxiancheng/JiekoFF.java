package javaDuoxiancheng;

public class JiekoFF implements Runnable{
    @Override
    public void run() {
        //........
    }
    public static void main(String[] args) {
     JiekoFF dx=new JiekoFF();
     new Thread(dx).start();//传入对象参数给线程类。
    }
}
