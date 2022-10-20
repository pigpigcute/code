package len5;

public class two {
    public static void main(String[] args){
        Stock Stock1 = new Stock();
        System.out.println("Previous Closing Price: "+Stock1.getPreviousClosingPrice());
        System.out.println("Current Price: "+Stock1.getCurrentPrice());
        System.out.println("Price Change: "+Stock1.getChangePercent()+"%");
    }
}

class Stock{
    String symbol,name;
    double previousClosingPrice,currentPrice;
    Stock(){
        symbol="ORCL";
        name="Oracl e Corporation";
        previousClosingPrice=34.5;
        currentPrice=34.35;
    }
    Stock(String newsymbol,String newname){
        symbol=newsymbol;
        name=newname;
    }
    double getChangePercent(){return 100*(currentPrice-previousClosingPrice)/previousClosingPrice;}
    double getPreviousClosingPrice(){return previousClosingPrice;}
    double getCurrentPrice(){return currentPrice;}

    void setCurrentPrice(double x){
        currentPrice=x;
    }
    void setPreviousClosingPrice(double x){previousClosingPrice=x;}

}
