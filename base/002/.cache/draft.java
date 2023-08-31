import java.util.*;


// Nesse rascunho estão faltando os atributos e métodos
// correspondentes às funcionalidades de abastecer e dirigir o carro.


class Car{
    public int pass; // Passageiros
    public int passMax; // limite de Passageiros

    public Car() {
    }

    public void enter() {
    }

    public void leave() {
    }

    public String toString() {
    }
};


public class Solver {
    public static void main(String[] a) {
        Car car = new Car();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if      (args[0].equals("show"))  { System.out.println(car);              }
            else if (args[0].equals("enter")) { car.enter();                          }
            else if (args[0].equals("leave")) { car.leave();                          }
            else if (args[0].equals("end"))   { break;                                }
            else                              { write("fail: comando invalido");}
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}





