import java.util.*;

class Adapter {
    // Car car = new Car();
    
    public void enter() {
        // car.enter();
    }

    public void leave() {
        // car.leave();
    }

    public void fuel(int gas) {
        // car.fuel(gas);
    }

    public void drive(int km) {
        // car.drive(km);
    }

    public void show() {
        // System.out.println(car.toString());
    }
}


public class Shell {
    
    public static void main(String[] a) {
        Adapter adp = new Adapter();
        
        while (true) {
            System.out.print("$");
            var line = input();
            write(line); // comente para executar interativamente
            var args = line.split(" ");
            if      (args[0].equals("end"))   { break;                                }
            else if (args[0].equals("show"))  { adp.show();                           }
            else if (args[0].equals("enter")) { adp.enter();                          }
            else if (args[0].equals("leave")) { adp.leave();                          }
            else if (args[0].equals("drive")) { adp.drive(Integer.parseInt(args[1])); }
            else if (args[0].equals("fuel"))  { adp.fuel(Integer.parseInt(args[1]));  }
            else                              { System.out.println("fail: comando invalido");}
        }
    }
    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static void    write(String value)  { System.out.println(value); }
}
