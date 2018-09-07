import java.lang.Math;
public class Segmento extends Figura {
    private Punto a;
    private Punto b;
    private static int idSegmento=1;

    public Segmento(Punto pa, Punto pb){
        super("Segmento "+idSegmento);
        a=pa;
        b=pb;
        setNome("Segmento" + idSegmento);
        idSegmento++;
    }
    public Punto getA() {
        return a;
    }
    public Punto getB() {
        return b;
    }

    //@Override
    public String toString() {
        return getNome() + ": A" + a.toString() + " B" + b.toString();
    }

    public double pendenza(){
        if(a.getX()==b.getX()) return 90;
        double rad=Math.atan((b.getY()-a.getY())/(b.getX()-a.getX()));
        return Math.toDegrees(rad);
    }
    public double lunghezza(){
        return Punto.distanza(a,b);
    }

    //@Override
    public double distanza(Figura f) {
        double d, d1;
        if(f instanceof Segmento){
            Segmento s= (Segmento)f;
            d=Punto.distanza(a,s.a);
            d1=Punto.distanza(a,s.b);
            if(d>d1) d=d1;
            d1=Punto.distanza(b,s.a);
            if(d>d1) d=d1;
            d1=Punto.distanza(b,s.b);
            if(d>d1) return d1;
            else return d;
        }
        if(f instanceof Poligono){
            Poligono p= (Poligono)f;
            Punto pBar= p.baricentro();
            d=Punto.distanza(a,pBar);
            d1=Punto.distanza(b,pBar);
            if(d>d1) return d1;
            else return d;
        }
        if(f instanceof Cerchio){
            Cerchio c= (Cerchio)f;
            d=Punto.distanza(a,c.getCentro());
            d1=Punto.distanza(b,c.getCentro());
            if(d>d1) return d1;
            else return d;
        }
        return -1;

    }
}
