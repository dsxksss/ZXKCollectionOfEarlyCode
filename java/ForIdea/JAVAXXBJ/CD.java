package JAVAXXBJ;

public class CD extends LiedejJCfulei {
    public CD(String gqm, String gsm, int playTime) {
        super(gqm,gsm,"","",playTime);
    }
@Override
    public void print() {
        System.out.println("歌曲:" + gqm +
                "\n歌手:" + gsm + "\n播放时长:" + playTime + "\n");
    }
}
