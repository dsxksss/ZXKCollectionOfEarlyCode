package javaDuoxiancheng;

public class Bingfa2 implements Runnable{
    private static String winner;
    @Override
    public void run() {
        for (int i = 0; i <= 100; i++) {
            //模拟兔子休息
            if(Thread.currentThread().getName().equals("兔子")&&i%10==0){
                try {
                    Thread.sleep((int)0.3);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            boolean flag=gameOver(i);
            //如果比赛结束,就停止该程序。
            if (flag){
                break;
            }
            System.out.println(Thread.currentThread()
                    .getName()+"-->跑了"+i+"步");
        }
    }
    public boolean gameOver(int steps){
        //判断是否已有胜利者。
        if(winner!=null){
            return true;
        }else if(steps>=100){
            winner=Thread.currentThread().getName();
            System.out.println("winner is "+winner);
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Bingfa2 dx=new Bingfa2();
        new Thread(dx,"兔子").start();
        new Thread(dx,"乌龟").start();
    }
}
