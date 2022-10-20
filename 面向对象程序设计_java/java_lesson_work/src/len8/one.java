package len8;

public class one {
    public static void main(String[] args){;
        Fan fan1 = new Fan();
        Fan fan2 = new Fan();
        fan1.SetSpeed(Fan.FAST);
        fan1.SetRadius(10);
        fan1.SetColor("yellow");
        fan1.SetOn(true);
        fan2.SetSpeed(Fan.MEDIUM);
        System.out.println("fan1 is: "+fan1.toString());
        System.out.println("fan2 is: "+fan2.toString());
    }
}
