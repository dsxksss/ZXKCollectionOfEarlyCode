package mtk;

public class CD {
    private String gq;
    private String gs;
    private int playtime;
    public CD(String gq, String gs, int playtime) {
        this.gq = gq;
        this.gs = gs;
        this.playtime = playtime;
    }

    public void print(){
        System.out.println(gq+":"+gs+":"+playtime);
    }
}
