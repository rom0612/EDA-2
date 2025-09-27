import java.util.ArrayList;
public class ListaComputadoras {
    ArrayList<Computadora>listaCompus=new ArrayList<Computadora>();
        public ListaComputadoras() {
            this.listaCompus = new ArrayList<>();
        }

        public void inicializarlista(){
        Computadora c1 = new Computadora("HP", "Aurora R15", 32,"nueva", "Windows 11");
        Computadora c2 = new Computadora("Lenovo", "ThinkPad T480", 16,"no sirve", "Ubuntu");
        Computadora c3 = new Computadora("Apple", "MacBook Air M2", 2,"nueva", "macOS");
        Computadora c4 = new Computadora("HP", "Compaq dx2400", 2,"muy vieja", "Windows 11");
        listaCompus.add(c1);
        listaCompus.add(c2);
        listaCompus.add(c3);
        listaCompus.add(c4);
        }

        public ArrayList<Computadora> obtenerLista(){
            return new ArrayList<>(listaCompus);
        }

}
