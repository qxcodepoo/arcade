import java.util.Scanner;

class Adapter {
    // private Animal animal = new Animal("", "");
    public void init(String especie, String barulho) {
        // animal = new Animal(especie, barulho);
    }
    
    public void noise() {
        // System.out.println(animal.fazerBarulho());
    }

    public void grow(int nivel) {
        // animal.envelhecer(nivel);
    }

    public void show() {
        // System.out.println(animal.toString());
    }
}

public class Shell {

    public static void main(String[] _args) {
        Adapter adp = new Adapter();

        while (true) {
            write("$");
            var line = input();
            var args = line.split(" ");
            write(line + "\n"); //test echo

            if      (args[0].equals("end")  ) { break;                                   }
            else if (args[0].equals("init") ) { adp.init(args[1], args[2]);              }
            else if (args[0].equals("show") ) { adp.show();                              }
            else if (args[0].equals("noise")) { adp.noise();                             }
            else if (args[0].equals("grow") ) { adp.grow((int) number(args[1]));         }
            else                              { write("fail: comando invalido\n"); }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.print(value);}
    public static double number(String str)   { return Double.parseDouble(str); }
}
