public class Rettangolo extends Poligono{
    private static int idRettangolo=1;
    public Rettangolo(double base, double altezza, double x, double y){
        super(4);
        p= new Punto[4];
        p[0]= new Punto(x,y);
        p[1]= new Punto(x+base,y);
        p[2]= new Punto(x+base, y-altezza);
        p[3]= new Punto(x,y-altezza);
        setNome("Rettangolo" + idRettangolo);
        idRettangolo++;
    }
    public double Diagonale(){
        return Math.sqrt(Math.pow(Punto.distanza(p[0],p[1]),2) + Math.pow(Punto.distanza(p[1],p[2]),2));
    }
    public double perimetro(){
        return (Punto.distanza(p[0],p[1])+ Punto.distanza(p[1],p[2])) *2;
    }
    public double area(){
        return Punto.distanza(p[0],p[1])* Punto.distanza(p[1],p[2]);
    }
    public Punto baricentro(){
        double cx, cy;
        cx=(p[0].getX()+p[1].getX())/2;
        cy=(p[0].getY()+p[1].getY())/2;
        return new Punto (cx,cy);
    }
    public String toString(){
        return "A" + p[0].toString() + "B" + p[1].toString() + "C" + p[2].toString() + "D" + p[3].toString();
    }

}