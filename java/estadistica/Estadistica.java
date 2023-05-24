import java.util.Arrays;

class Estadistica{
    public double media(double[] datos) 
    {
        // Time Complexity O(n)
        double result = 0;
        for (int i = 0; i < datos.length; i++) {
            result += datos[i];
        }
        return result / datos.length;
    }

    public int media(int[] datos) 
    {
        int result = 0;
        for (int i = 0; i < datos.length; i++) {
            result += datos[i];
        }
        return result / datos.length;
    }

    public boolean isSorted(double[] datos) 
    {
        for (int i = 0; i < datos.length - 1; i++) {
            if (datos[i] > datos[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public boolean isSorted(int[] datos) 
    {
        /* Time Complexity O(n) */
        for (int i = 0; i < datos.length - 1; i++) {
            if (datos[i] > datos[i + 1]) {
                return false;
            }
        }
        return true;
    }


    public double mediana(double[] datos) 
    {
        // Time complexity O(1)
        return datos.length % 2  == 0 ? (datos[datos.length / 2] + datos[(datos.length / 2) + 1]) / 2 : datos[datos.length / 2] ;
    }

    public int mediana(int[] datos) {
        return datos.length % 2  == 0 ? (datos[datos.length / 2] + datos[(datos.length / 2) + 1]) / 2 : datos[datos.length / 2] ;
    }

    public static void main(String[] args) 
    {
        Estadistica e = new Estadistica();
        double datos[] = {14.7, 3.9, 2.2, 1.7, 3.11};
        
        System.out.println(Arrays.toString(datos) + "\t" + e.isSorted(datos));
        Arrays.sort(datos);
        System.out.println(Arrays.toString(datos) + "\t" + e.isSorted(datos)); 
        System.out.println("Promedio: "+ e.media(datos));
        System.out.println("Mediana " + e.mediana(datos));                                  
    }
}