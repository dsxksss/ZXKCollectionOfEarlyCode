package xsglcx;

import java.io.Serializable;

public class ZlkF implements Serializable {
    //必须是Serializable接口,不然无法使用ObjIO函数;
    protected String XSXM;
    protected String XSZZ;
    protected int XSNL;
    //构造函数
    public ZlkF(String XSXM, int XSNL,String XSZZ) {
        super();//父类的super函数不需要参数传递
        this.XSXM = XSXM;
        this.XSZZ = XSZZ;
        this.XSNL = XSNL;
    }
    public boolean namequery(String name){
        return false;
    }
    public String toString(){
        return "父类toString被调用";
    }
}
