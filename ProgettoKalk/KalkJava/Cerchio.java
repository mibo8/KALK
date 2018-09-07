import java.lang.Math;
public class Cerchio extends Figura{
    Punto centro;
    double raggio;
    static int idCerchio=1;

    public Cerchio(double x, double y, double r){
        super("Cerchio " + idCerchio);
        centro= new Punto(x,y);
        raggio=r;
        setNome("Cerchio" + idCerchio);
        idCerchio++;
    }
    public Punto getCentro(){
        return centro;
    }
    public double getRaggio(){
        return raggio;
    }
    public String toString() {
        return getNome() + ": Centro " + centro.toString() + "Raggio " + raggio;
    }
    public double distanza(Figura f) {
        double d, d1;
        if(f instanceof Segmento){
            Segmento s= (Segmento)f;
            d=Punto.distanza(centro,s.getA());
            d1=Punto.distanza(centro,s.getB());
            if(d<d1) return d;
            else return d1;
        }
        if(f instanceof Poligono) {
            Poligono p = (Poligono) f;
            d = Punto.distanza(centro, p.baricentro());
            return d;
        }
        if(f instanceof Cerchio){
            Cerchio c= (Cerchio)f;
            d=Punto.distanza(centro,c.centro);
            return d;
        }
        return -1;
    }
    public double area(){
        return Math.PI*Math.pow(raggio,2);
    }
    public double perimetro(){
        return (Math.PI*raggio)*2;
    }
    public double diametro(){
        return (2*raggio);
    }
}
