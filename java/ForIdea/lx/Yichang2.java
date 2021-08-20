package lx;


class OpenException2 extends Exception{}
class CloseException2 extends OpenException2{}
class NewExeption extends Exception{}

public class Yichang2 {
    //如果父类构造函数抛出了异常，子类构造也要声明同异常。
    public Yichang2()throws OpenException2{}
    public void f()throws OpenException2{}
    public static void main(String[] args) {
    }
}
//成员函数不能增加更多的异常是因为我们有可能拿子类
//对象当作父类对象来看待。在那时候如果通过父类的一个
//对象去调用子类的一个函数的时候我们得处理好所有异常
//但是在构造的时候,构造的过程中会自动调用父类的构造,
//父类的构造里所抛的异常都声明了,就可以抛出额外的异常。
class NewClass extends Yichang2 {
    public NewClass()throws OpenException2,NewExeption{}
    public void f(){}
    public static void main(String[] args) {
        try {
            Yichang2 p=new NewClass();//向上造型
            p.f();
            //一个catch可以利用｜区分多个异常类。
        } catch (OpenException2 | NewExeption e) {
            e.printStackTrace();
        }
    }
}