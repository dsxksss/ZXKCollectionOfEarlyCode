package tingchechang;

public class CarData {
    private String carName;
    private String carNum;
    private String name;
    private int carTime;
    private double RMB;

    public CarData(String name,String carName, String carNum) {
        this.carName = carName;
        this.carNum = carNum;
        this.name = name;
        this.carTime = 0;
        this.RMB = 0.0;
    }

    public void setRmb(int carTime){
        if (carTime<60){
            this.RMB+=2.5;
        }
    }

    public void printGo(double num){
        if(num ==this.RMB){
            System.out.println("支付成功,请往出口方向行驶...");
        }
    }

    public boolean nameEquals(String name){
        if(this.name.equals(name)){
            return true;
        }
        return true;
    }

    public String toString(){
        return "车主姓名:"+name+"  车型:"+carName+"  车牌号:"+carNum
                +"  停车:"+carTime+"分钟"+" 停车费共:"+RMB+"元";
    }

}
