package Text;

public class WuMingFen {
    String theMa;
    int quantity;
    boolean likeSoup;

    public WuMingFen(){
        theMa = "酸辣";
        quantity = 2;
        likeSoup = true;
    }
    public WuMingFen( String theMa,int quantity,boolean likeSoup){
//        this(theMa,quantity,likeSoup);
        this.theMa = theMa;
        this.quantity = quantity;
        this.likeSoup = likeSoup;
    }
    public WuMingFen( String theMa,int quantity){
        this.theMa = theMa;
        this.quantity = quantity;
    }
    public void check(){
        System.out.println("面码："+theMa+"，粉的份量："+quantity+"两，是否带汤："+likeSoup);
    }
}
