
public class Main {
    public static void main (String args[]) {
        VettoreFigure vf= new VettoreFigure();
        Segmento s= new Segmento(new Punto(0,0),new Punto(100,0));
        Cerchio c= new Cerchio(200,0,100);
        Triangolo t= new Triangolo(0,0,100,100,0,100);
        Rettangolo r= new Rettangolo(100,100,200,0);
        vf.pushFigura(s);
        vf.pushFigura(c);
        vf.pushFigura(t);
        vf.pushFigura(r);
        System.out.println(vf.getFiguraByIndex(0));
        System.out.println(vf.getFiguraByIndex(1));
        double d= vf.getFiguraByIndex(0).distanza(vf.getFiguraByIndex(1));
        System.out.println("Distanza: " + d);
        Cerchio c1=(Cerchio)vf.getFiguraByIndex(1);
        System.out.println("Area " + c1.getNome() + ": " + c1.area());
    }

}
