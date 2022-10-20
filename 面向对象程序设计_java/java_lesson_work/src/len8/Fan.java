package len8;

public class Fan{
    static int SLOW=1,MEDIUM=2,FAST=3;
    private int speed=SLOW;
    private boolean on = false;
    private double radius = 5;
    public String color = "blue";

    public Fan(){
        speed=SLOW; on=false; radius= 5; color="blue";
    }

    public int getSpeed(){return speed;}
    public void SetSpeed(int speed){this.speed=speed;}
    public boolean getOn(){return on;}
    public void SetOn(boolean on){this.on=on;}
    public double getRadius(){return radius;}
    public void SetRadius(double radius){this.radius=radius;}
    public String getColor(){return color;}
    public void SetColor(String color){this.color=color;}

    public String toString(){
        if(on==true){
            return "speed is "+speed+" and color is "+color+" and radius is "+radius;
        }else{
            return "color is "+color+" and radius is "+radius+" and fan is off ";
        }
    }
}
