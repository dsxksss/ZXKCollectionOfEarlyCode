package clock;

public class Display {
    private int value=0;
    private int limit=0;
    public void X() {
        value++;
        if (value == limit) {
            value = 0;
        }
    }
     public int getvalue(){
        return value;
    }
    public Display(int limit){
        this.limit=limit;
    }
}
