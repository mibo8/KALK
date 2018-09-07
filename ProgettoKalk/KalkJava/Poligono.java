public abstract class Poligono extends Figura{
    protected int nLati;
    protected Punto[] p;
    public Poligono(int n){
        super("Poligono");
        nLati=n;

    }

    @Override
    public double distanza(Figura f) {
        double d, d1;
        if (f instanceof Segmento) {
            Segmento s = (Segmento) f;
            d = Punto.distanza(baricentro(), s.getA());
            d1 = Punto.distanza(baricentro(), s.getA());
            if (d < d1) return d;
            else return d1;
        }
        if (f instanceof Poligono) {
            Poligono p = (Poligono) f;
            d = Punto.distanza(baricentro(), p.baricentro());
            return d;
        }
        if (f instanceof Cerchio) {
            Cerchio c = (Cerchio) f;
            d = Punto.distanza(baricentro(), c.getCentro());
            return d;
        }
        return -1;
    }
    public abstract double perimetro();
    public abstract double area();
    public abstract Punto baricentro();

}
