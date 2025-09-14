import java.util.*;

public class RadixSort {
    
    // crea y retorna 5 colas de enteros, para los dígitos del 0 al 4
    private static List<Queue<Integer>> crearQueues() {
        List<Queue<Integer>> queues = new ArrayList<>(); //aquí almacenará las colas
        for (int i = 0; i < 5; i++) { 
            queues.add(new LinkedList<>()); 
        }
        return queues; //retorna las queues creadas
    }
    
    // función para obtener el dígito en la posición
    private static int getDigit(int num, int posic) {
        int divisor = (int) Math.pow(10, posic); //calcula 10 elevado a la potencia posic
        return (num / divisor) % 10; //divide el número para "correr" el dígito a la posición de unidades, y %10 obtiene el resultado
    }
    
    // 4 iteraciones
    public static void radixSort(int[] arr) {
        List<Queue<Integer>> queues = crearQueues(); //crea las queues que necesito
        // 4 iteraciones
        for (int digitPos = 0; digitPos < 4; digitPos++) {
            // poner cada número en la cola correspondiente a su dígito
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
            // Mostrar la lista después de esta iteración
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
            boolean valEnt = false;
            while (!valEnt) {
                System.out.print("Número " + (i + 1) + ": ");
                String ent = sc.next();
                
                if (ent.length() != 4) { 
                    System.out.println("Debe ser de 4 dígitos, intenta otra vez");
                    continue; 
                }
                
                boolean digVal = true; 
                for (char c : ent.toCharArray()) { 
                    if (c < '0' || c > '4') { 
                        digVal = false; 
                        break; 
                    }
                }
                
                if (!digVal) { 
                    System.out.println("los dígitos deben estar entre 0 y 4, intenta otra vez");
                    continue; //regresa para volver a pedirlo
                }
                
                arr[i] = Integer.parseInt(ent); 
                valEnt = true; //salir del while
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