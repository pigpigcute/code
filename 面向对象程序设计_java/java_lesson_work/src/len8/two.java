package len8;

public class two {
    public static void main(String[] args){
        two_RegularPolygon rp1 = new two_RegularPolygon();
        two_RegularPolygon rp2 = new two_RegularPolygon(6,4);
        two_RegularPolygon rp3 = new two_RegularPolygon(10,4,5.6,7.8);
        System.out.println("Polygon 1 perimetet: "+rp1.getPerimeter());
        System.out.println("Polygon 1 area: "+rp1.getArea());
        System.out.println();
        System.out.println("Polygon 2 perimetet: "+rp2.getPerimeter());
        System.out.println("Polygon 2 area: "+rp2.getArea());
        System.out.println();
        System.out.println("Polygon 3 perimetet: "+rp3.getPerimeter());
        System.out.println("Polygon 3 area: "+rp3.getArea());
    }
}
