import java.lang.Math;

public class Punto {
    private double x;
    private double y;
    public Punto(){
        x=0;
        y=0;
    }
    public Punto(double cx, double cy){
        x=cx;
        y=cy;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public void setX(double cx){
        x=cx;
    }
    public void setY(double cy){
        y=cy;
    }
    public static double distanza(Punto p1, Punto p2){
        return Math.sqrt(((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
    }

    @Override
    public String toString() {
        return "(" + x + "," + y + ") ";
    }
}
