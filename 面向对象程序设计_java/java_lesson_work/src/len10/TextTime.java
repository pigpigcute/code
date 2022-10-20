package len10;

public class TextTime {
    public static  void main(String[] args){
        Time t1 = new Time();
        Time t2 = new Time(555550000);
        System.out.println("Hour: "+(t1.hour+8)+" minute: "+t1.minute+" Second: "+t1.second);
        System.out.println("Hour: "+t2.hour+" minute: "+t2.minute+" Second: "+t2.second);
    }
}
