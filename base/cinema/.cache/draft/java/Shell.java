import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

class Adapter {
    public void init(int capacity) {
    }
  
    public void reserve(String id, String phone, int index) {
    }
  
    public void cancel(String id) {
    }
  
    public void show() {
    }
  }

public class Shell {
    public static void main(String[] _args) {
        Adapter adp = new Adapter();
        while (true) {
            var line = input();
            var args = line.split(" ");
            write('$' + line);

            if (args[0].equals("end"))           { break;                                                }
            else if (args[0].equals("init"))     { adp.init((int) number(args[1]));                      }
            else if (args[0].equals("show"))     { adp.show();                                           }
            else if (args[0].equals("reserve"))  { adp.reserve(args[1], args[2], (int) number(args[3])); }
            else if (args[0].equals("cancel"))   { adp.cancel(args[1]);                                  }
            else                                 { write("fail: comando invalido");                }  
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}
