package mtk;

import java.util.ArrayList;
import java.util.Scanner;

class RpgData{
    private final String roleName;//角色姓名
    private final String roleGender;//角色性别
    private final int roleAge;
    public RpgData(String roleName,
                   String roleGender, int roleAge) {
        this.roleName = roleName;
        this.roleGender = roleGender;
        this.roleAge = roleAge;
    }
    public void print(){
        System.out.println("角色姓名:"+roleName);
        System.out.println("角色性别:"+roleGender);
        System.out.println("角色年龄:"+roleAge);
    }
}
public class Xxbj {
    private final ArrayList<RpgData> rpggame=new ArrayList<RpgData>();
    public void add(RpgData dx){
        rpggame.add(dx);
    }
    public void list(){
        for(RpgData dx:rpggame){
            dx.print();//将rpggame对象里的东西交给dx来做;
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        Xxbj game1=new Xxbj();
        game1.add(new RpgData("亚瑟王","男",57));
        game1.list();
    }
}
