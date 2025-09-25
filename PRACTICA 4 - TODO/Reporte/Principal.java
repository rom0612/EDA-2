import java.util.ArrayList;
public class Principal {
    public static void main (String [] args){
        ArrayList<Integer>listEnteros=new ArrayList<Integer>();

        listEnteros.add(1);
        listEnteros.add(3);
        listEnteros.add(5);
        listEnteros.add(7);
        listEnteros.add(7);
        listEnteros.add(7);
        listEnteros.add(9);
        listEnteros.add(10);
        listEnteros.add(11);

        int numBuscado=7;
        int fin=listEnteros.size()-1;
        int total=BusquedaBinaria.contarAp(listEnteros, 0, fin, numBuscado);

        System.out.println("la lista tiene " + total + " veces el numero "+ numBuscado);


        //============COMPUS
        ArrayList<Computadora>listaCompus=new ArrayList<>();
        Computadora c1 = new Computadora("HP", "Aurora R15", 32,"nueva", "Windows 11");
        Computadora c2 = new Computadora("Lenovo", "ThinkPad T480", 16,"no sirve", "Ubuntu");
        Computadora c3 = new Computadora("Apple", "MacBook Air M2", 2,"nueva", "macOS");
        Computadora c4 = new Computadora("HP", "Compaq dx2400", 2,"muy vieja", "Windows 11");
        listaCompus.add(c1);
        listaCompus.add(c2);
        listaCompus.add(c3);
        listaCompus.add(c4);
        String marcaBusq1="HP";
        String marcaBusq2="hp";
        String marcaBusq3="apple";
        String marcaBusq4="acer";
        int bl1= BusquedaLineal.contarApCompu(listaCompus, marcaBusq1);
        int bl2= BusquedaLineal.contarApCompu(listaCompus, marcaBusq2);
        int bl3= BusquedaLineal.contarApCompu(listaCompus, marcaBusq3);
        int bl4= BusquedaLineal.contarApCompu(listaCompus, marcaBusq4);

        System.out.println("la lista contiene " + bl1 + " computadoras de la marca " + marcaBusq1);
        System.out.println("la lista contiene " + bl2 + " computadoras de la marca " + marcaBusq2);
        System.out.println("la lista contiene " + bl3 + " computadoras de la marca " + marcaBusq3);
        System.out.println("la lista contiene " + bl4 + " computadoras de la marca " + marcaBusq4);

    }
}
