package len8;

public class three_QuadraticEquation {
    private double a, b, c;
    // 构造方法
    public three_QuadraticEquation(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }
    // getter方法
    public double getA() {
        return a;
    }
    public double getB() {
        return b;
    }
    public double getC() {
        return c;
    }
    public double getDiscriminant(){
        return b * b - 4 * a * c;
    }

    public double getRoot1(){
        return (-b + Math.sqrt(getDiscriminant())) / (2 * a);
    }
    public double getRoot2(){
        return (-b - Math.sqrt(getDiscriminant())) / (2 * a);
    }
}

