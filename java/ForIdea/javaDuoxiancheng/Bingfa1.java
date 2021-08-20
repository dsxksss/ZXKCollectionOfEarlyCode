package javaDuoxiancheng;

public class Bingfa1 implements Runnable {
    private int P = 20;

    @Override
    public void run() {
        while (P >= 0) {
            //模拟线程延时
            try {
                Thread.sleep(200);//200毫秒后再执行;
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.out.println("延时模拟错误");
            }
            System.out.println(Thread.currentThread()
                    .getName() + "<--抢到了第" + P-- + "张票");
            //Thread.currentThread().getName()的作用是获取当前线程名字。
        }
    }
    public static void main(String[] args) {
        Bingfa1 dx = new Bingfa1();
        new Thread(dx,"张三").start();//第二个参数是自己设置的线程名字。
        new Thread(dx,"李四").start();
        new Thread(dx,"王二狗").start();
    }
}
