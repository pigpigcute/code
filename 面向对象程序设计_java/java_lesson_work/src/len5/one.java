package len5;

public class one {
    public static void main(String[] args) {
        Rectangle Rectangle1 = new Rectangle(4,40);
        Rectangle Rectangle2 = new Rectangle(3.5,35.9);

        System.out.println("The area of a rectangle with width "+Rectangle1.width+" and height "+Rectangle1.height+" is "+Rectangle1.getArea());
        System.out.println("The perimeter of a rectangle is "+Rectangle1.getPerimeter());
        System.out.println("The area of a rectangle with width "+Rectangle2.width+" and height "+Rectangle2.height+" is "+Rectangle2.getArea());
        System.out.println("The perimeter of a rectangle is "+Rectangle2.getPerimeter());
    }
}
class Rectangle{
    double width,height;
    Rectangle(){
        width=1;height=1;
    }
    Rectangle(double x,double y){
        width=x;height=y;
    }

    double getArea(){
        return width*height;
    }

    double getPerimeter(){
        return 2*(width+height);
    }
}



