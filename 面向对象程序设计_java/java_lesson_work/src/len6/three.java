package len6;

import java.util.GregorianCalendar;

public class three {
    public static void main(String[] srgs){
        GregorianCalendar t1 = new GregorianCalendar();
        GregorianCalendar t2 = new GregorianCalendar();
        t2.setTimeInMillis(1234567898765L);
        System.out.println("Year is "+t1.get(GregorianCalendar.YEAR));
        System.out.println("Month is "+(t1.get(GregorianCalendar.MONTH)+1));
        System.out.println("Date is "+t1.get(GregorianCalendar.DAY_OF_MONTH));
        System.out.println("Year is "+t2.get(GregorianCalendar.YEAR));
        System.out.println("Month is "+(t2.get(GregorianCalendar.MONTH)+1));
        System.out.println("Date is "+t2.get(GregorianCalendar.DAY_OF_MONTH));
    }
}
