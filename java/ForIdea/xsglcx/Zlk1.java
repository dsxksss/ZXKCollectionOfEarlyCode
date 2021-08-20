package xsglcx;

public class Zlk1 extends ZlkF {//继承了父类ZlkF所有内容的子类
    //构造函数
    public Zlk1(String XSXM,int XSNL,String XSZZ) {
        super(XSXM,XSNL,XSZZ);//把每个参数依次传递给父类构造。
    }

    @Override
    public boolean namequery(String name){
        if(this.XSXM.equals(name)) {
            return true;
        }
        else{return false;}
    }

    @Override
    public String toString(){
        return "["+XSXM+"\t"+XSNL+"\t"+XSZZ+"]";
        //覆盖父类toString函数
    }
}
