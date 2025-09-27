import java.util.ArrayList;
public class ListaEnteros {
        ArrayList<Integer>listEnteros=new ArrayList<Integer>();
        public ListaEnteros() {
            this.listEnteros = new ArrayList<>();
        }

        public void inicializarlista(){
            listEnteros.add(7);
            listEnteros.add(7);
            listEnteros.add(7);
            listEnteros.add(1);
            listEnteros.add(3);
            listEnteros.add(5);
            listEnteros.add(5);
            listEnteros.add(7);
            listEnteros.add(2);
        }  

        //obtener la lista
        public ArrayList<Integer> obtenerLista() {
            return new ArrayList<>(listEnteros); //devuelve una copia
        }

}

