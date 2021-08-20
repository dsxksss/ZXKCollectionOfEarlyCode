package lx;

class F{
    protected int a;
    public int z(){
        return this.a;
    }
}

class Lx extends F {
    public void showA(){
        System.out.println(z());
    }
}

