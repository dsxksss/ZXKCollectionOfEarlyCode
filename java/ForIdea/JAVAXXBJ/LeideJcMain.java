package JAVAXXBJ;

import java.util.ArrayList;

public class LeideJcMain {
    private ArrayList<LiedejJCfulei> FL = new ArrayList<LiedejJCfulei>();

    public void add(LiedejJCfulei dx) {
        FL.add(dx);
    }

    public void list() {//打印每一个子类对象的自带变量值
        for (LiedejJCfulei FL2 : FL) {
            FL2.print();
        }
    }

    public static void main(String[] args) {
        LeideJcMain dx = new LeideJcMain();
        dx.add(new CD("清明雨上", "许嵩", 340));
        dx.add(new CD("周杰伦","简单爱",315));
        dx.add(new DVD("星际穿越", "克里斯托弗·诺兰", 10000));
        dx.add(new DVD("阿凡达","詹姆斯·卡梅隆",10000));
        System.out.println(dx.toString() );
        dx.list();
    }
}
