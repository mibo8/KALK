public class Triangolo extends Poligono{
    private static int idTriangolo=1;
    public Triangolo(double xa, double ya, double xb, double yb, double xc, double yc){
        super(3);
        p= new Punto[3];
        p[0]= new Punto(xa,ya);
        p[1]= new Punto(xb,yb);
        p[2]= new Punto(xc,yc);
        setNome("Triangolo" + idTriangolo);
        idTriangolo++;
    }
    public double perimetro(){
        return (Punto.distanza(p[0],p[1])+ Punto.distanza(p[1],p[2])+ Punto.distanza(p[2],p[0])) ;
    }
    public double area(){
        return Math.abs((p[2].getX()-p[0].getX())*(p[1].getY()-p[0].getY())-(p[1].getX()-p[0].getX())*(p[2].getY()-p[0].getY())/2);
    }
    public Punto baricentro(){
        double cx, cy;
        cx=(p[0].getX()+p[1].getX()+p[2].getX())/3;
        cy=(p[0].getY()+p[1].getY()+p[2].getY())/3;
        return new Punto(cx,cy);
    }
    public String toString(){
        return getNome() +  ": A" + p[0].toString() + "B" + p[1].toString() + "C" + p[2].toString();
    }

}