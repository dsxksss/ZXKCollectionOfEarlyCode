package tingchechang;

import java.sql.Time;
import java.util.ArrayList;

public class BigCarData {
    private ArrayList<CarData> data=new ArrayList<CarData>();

    public void add(CarData dx){
        this.data.add(dx);
    }

    public CarData getCar(int index){
        return this.data.get(index);
    }

    public int getSize(){
        return this.data.size();
    }

    public boolean found(String name){
        for (int i = 0; i < this.data.size(); i++) {
            if(this.data.get(i).nameEquals(name)){
                return true;
            }
        }
        return false;
    }

    public void start(){
        //TODO 获取时间功能,并且让start可以调用setRmb()函数;
    }
}
