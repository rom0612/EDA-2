import java.util.*;

public class RadixSort {
    
    private static List<Queue<Integer>> crearQueues() {
        List<Queue<Integer>> queues = new ArrayList<>(); //aquí almacena las colas
        for (int i = 0; i < 5; i++) { 
            queues.add(new LinkedList<>());
        }
        return queues;
    }
    
    // función para obtener el dígito en la posición
    private static int getDigit(int num, int posic) {
        int divisor = (int) Math.pow(10, posic); //calcula 10 elevado a la potencia posic
        return (num / divisor) % 10; //divide el número para "correr" el dígito a la posición de unidades, y %10 obtiene el resultado
    }
    
    public static void radixSort(int[] arr) {
        List<Queue<Integer>> queues = crearQueues();
        
        for (int digitPos = 0; digitPos < 4; digitPos++) {
            // Colocar cada número en la cola correspondiente a su dígito
            for (int num : arr) {
                int digit = getDigit(num, digitPos);
                queues.get(digit).add(num);
            }
            
            // desencolar números de las colas en orden
            int index = 0;
            for (Queue<Integer> queue : queues) {
                while (!queue.isEmpty()) { //sale cuando la cola está vacía
                    arr[index++] = queue.poll(); //desencolar
                }
            }
            
            // mostrar la lista después de cada iteración
            System.out.print("después de la iteración " + (digitPos + 1) + " (dígito " + digitPos + "): ");
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[15];
        
        System.out.println("Ingresa 15 números de 4 dígitos (solo dígitos del 0 al 4):");
        //verif que cumplan y los agrega al arreglo
        for (int i = 0; i < 15; i++) {
            boolean valEnt = false; //para checar si es una entrada válida, inicia como falso porqueasume que no lo es, si pasa las restricciones se cambia para salir del while
            
            while (!valEnt) {
                System.out.print("Número " + (i + 1) + ": ");
                String ent = sc.next();
                
                if (ent.length() != 4) { //ent.length mide la longitud de la entrada del scanner
                    //si no es 4 caracteres
                    System.out.println("Debe ser de 4 dígitos, intenta otra vez");
                    continue; //vuelve al inicio del while para pedir otro num
                }
                
                
                boolean digVal = true; //digVal checa si el dígito es cálido
                for (char c : ent.toCharArray()) { //recorre cada caracter de ent (toCharArray lo convierte a un arreglo de caracteres)
                    if (c < '0' || c > '4') { //verifica qe esté en el rango
                        digVal = false; //si no está marca como que no es valido
                        break; //termina el for con el primero que encuentre que no está en el ranfo
                    }
                }
                
                if (!digVal) { //si encontró que hay valores fuera del rango
                    System.out.println("los dígitos deben estar entre 0 y 4, intenta otra vez");
                    continue; //regresa para volver a pedirlo
                }
                
                // si pasa todas las validaciones, asigna el valor en la posición i
                arr[i] = Integer.parseInt(ent); //convierte String a int
                valEnt = true; //para salir del while, que se ejecuta hasta que se pone un numero valido y si sale, puede meterse a la siguiente del for
            }
        }
        
        System.out.print("\nArreglo original: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println("\n");
        
        radixSort(arr);
        System.out.print("\nArreglo ordenado: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
        
        sc.close();
    }
}