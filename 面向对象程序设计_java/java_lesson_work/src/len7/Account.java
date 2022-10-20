package len7;

import java.util.Date;

public class Account {
    private int id = 0;//账号
    private double balance = 0;//余额
    private double annualInterestRate = 0;//利率
    private Date dateCreated;//开户日期

    public Account(){

    }

    public Account(int id,double banlance){
        this.id=id; this.balance=banlance;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }
    public double getAnnualInterestRate() {
        return annualInterestRate;
    }
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public Date getDateCreated(){
        return dateCreated;
    }

    public double getMonthlyInterestRate(){
        return annualInterestRate/1200;
    }

    public double getMonthlyInterest(){
        return annualInterestRate/1200+balance;
    }

    public void withDraw(double numb){
        if(balance>=numb) balance-=numb;
    }

    public void deposit(double numb){
        balance=balance+numb;
    }

}
