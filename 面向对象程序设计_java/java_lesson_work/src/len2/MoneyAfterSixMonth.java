package len2;

import java.util.Scanner;

public class MoneyAfterSixMonth {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        final double rate=0.00417;
        System.out.print("Enter monthly saving amount:");
        double account=0;
        double add=input.nextDouble();
        int t=6;
        while(t>0){
            account=(account+add)*(1+rate);
            t--;
        }
        System.out.print("After the sixth month, the account value is "+account);
    }
}
