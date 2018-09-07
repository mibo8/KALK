import java.util.Vector;
public class VettoreFigure {
    private Vector<Figura> vFig;
    public VettoreFigure(){
        vFig= new Vector<Figura>();
    }
    public void pushFigura(Figura f){
        vFig.add(f);
    }
    public Figura getFiguraByIndex(int i){
        return vFig.elementAt(i);
    }
}
