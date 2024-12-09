import java.util.*;

import java.text.DecimalFormat;

class Adapter {
    void init() {
    }

    void show() {
    }

    void init(int batteryMax) {
    }

    void charge(int value) {
    }

    void sum(int a, int b) {
    }

    void div(int a, int b) {
    }
}


public class Shell {
    static Adapter adp = new Adapter();

    public static void main(String[] _args) {
        while (true) {
            System.out.print("$");
            var line = input();
            var args = line.split(" ");
            write(line);

            if      (args[0].equals("end"   )) { break;                                                 }
            else if (args[0].equals("show"  )) { adp.show();                                            }
            else if (args[0].equals("init"  )) { adp.init((int) number(args[1]));                       }
            else if (args[0].equals("charge")) { adp.charge((int) number(args[1]));                     }
            else if (args[0].equals("sum"   )) { adp.sum((int) number(args[1]), (int) number(args[2])); }
            else if (args[0].equals("div"   )) { adp.div((int) number(args[1]), (int) number(args[2])); }
            else                               { write("fail: comando invalido");                 }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}
