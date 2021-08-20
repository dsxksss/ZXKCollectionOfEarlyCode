package clock;

public class Clock {
    private Display hour=new Display(24);
    private Display minute=new Display(60);
    private Display second=new Display(60);
    public void start(){
        for(;;){
            second.X();
            if(second.getvalue()==0){
                minute.X();
                if(minute.getvalue()==0){
                    hour.X();
                }
            }
            System.out.printf("%02d:%02d:%02d\n",hour.getvalue(),
                    minute.getvalue(),second.getvalue());
        }
    }
    }
