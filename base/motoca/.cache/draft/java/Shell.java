import java.util.*;


class Adapter {
    // Motorcycle moto = new Motorcycle(1);
    public void init(int power) {
        // moto = new Motorcycle(power);
    }

    public void enter(String name, int age) {
        // moto.enter(new Person(name, age));
    }

    public void buy(int price) {
        // moto.buy(price);
    }

    public void drive(int km) {
        // moto.drive(km);
    }
    
    public void leave() {
        // var person = moto.leave();
        // if (person == null) {
        //     System.out.println("---");
        //     return;
        // }
        // System.out.println(person.toString());
    }

    public void honk() {
        // System.out.println(moto.honk());
    }

    public void show() {
        // System.out.println(moto.toString());
    }
}


public class Shell{
    static Adapter adp = new Adapter();

    public static void main(String[] args) {
        while(true) {
            write("$");
            String line = input();
            args = line.split(" ");
            write(line + "\n");
            
            if      (args[0].equals("end"))      { break;                                       }
            else if (args[0].equals("show"))     { adp.show();                                  }
            else if (args[0].equals("init"))     { adp.init((int) number(args[1]));             }
            else if (args[0].equals("enter"))    { adp.enter(args[1], (int) number(args[2]));   }
            else if (args[0].equals("buy"))      { adp.buy((int) number(args[1]));              }
            else if (args[0].equals("drive"))    { adp.drive((int) number(args[1]));            }
            else if (args[0].equals("honk"))     { adp.honk();                                  }
            else if (args[0].equals("leave"))    { adp.leave();                                 }
            else                                 { write("fail: comando invalido\n");       }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()            { return scanner.nextLine();      }
    public static void write(String value)  { System.out.print(value);        }
    public static double number(String str) { return Double.parseDouble(str); }
}
