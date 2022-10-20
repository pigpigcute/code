package len7;

import java.util.Date;

public class TextAccount {
    public static void main(String[] aegs){
        Account at = new Account(1122,20000);
        at.setAnnualInterestRate(4.5);
        at.withDraw(2500);
        at.deposit(3000);
        System.out.println("Balance is "+at.getBalance());
        System.out.println("Monthly interest is "+at.getMonthlyInterest());
        System.out.println("This account was created at "+at.getDateCreated());
    }
}
