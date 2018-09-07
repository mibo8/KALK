public abstract class Figura {
    private String nome;
    private static  int id=1;

    public Figura(String s){
        nome=s;
        id++;
    }
    public String getNome(){
        return nome;
    }
    public void setNome(String s){
        nome=s;
    }
    public int getId(){
        return id;
    }
    public abstract double distanza(Figura f);
    public abstract String toString();

}
