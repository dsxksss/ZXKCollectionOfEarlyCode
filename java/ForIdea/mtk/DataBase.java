package mtk;

import java.util.ArrayList;

public class DataBase {
    private ArrayList<CD> cd=new ArrayList<CD>();
    public void add(CD cd){
        this.cd.add(cd);
    }
    public void list(){
        for(CD cd:this.cd){
            cd.print();
        }
    }
    public static void main(String[] args) {
        DataBase database=new DataBase();
        database.add(new CD("清明雨上","许嵩",120));
        database.list();
    }

}
