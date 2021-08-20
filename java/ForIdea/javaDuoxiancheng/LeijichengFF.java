package javaDuoxiancheng;

public class LeijichengFF extends Thread{
    @Override//记得一定要重写父类run方法
    public void run() {
        //........
    }
    public static void main(String[] args) {
     LeijichengFF dx=new LeijichengFF();
     dx.start();//调用Thread类里的start方法启动线程
    }
}
