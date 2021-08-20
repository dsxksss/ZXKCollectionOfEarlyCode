package JAVAXXBJ;

public class DVD extends LiedejJCfulei {
    public DVD(String dym, String dy, int playTime) {
        super("","",dym,dy,playTime);
    }
    public void print() {
        System.out.println("电影:" + dym +
                "\n导演:" + dy + "\n播放时长:" + playTime + "\n");
    }
}
