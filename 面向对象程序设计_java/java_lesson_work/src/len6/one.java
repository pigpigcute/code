package len6;

import javafx.geometry.Point2D;
import java.util.Date;

public class one {
    public static void main(String[] args){
        Date date1 = new Date();
        Date date2 = new Date();
        Date date3 = new Date();
        Date date4 = new Date();
        Date date5 = new Date();
        Date date6 = new Date();
        Date date7 = new Date();
        Date date8 = new Date();
        date1.setTime(10000);
        date2.setTime(100000);
        date3.setTime(1000000);
        date4.setTime(10000000);
        date5.setTime(100000000);
        date6.setTime(1000000000);
        date7.setTime(10000000000L);
        date8.setTime(date6.getTime()*100);
        System.out.println(date1.toString());
        System.out.println(date2.toString());
        System.out.println(date3.toString());
        System.out.println(date4.toString());
        System.out.println(date5.toString());
        System.out.println(date6.toString());
        System.out.println(date7.toString());
        System.out.println(date8.toString());

    }
}
