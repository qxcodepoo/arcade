import java.util.Scanner;

class Adapter {
    // private Pencil pencil;
    public Adapter(double thickness) {
        // pencil = new Pencil(thickness);
    }

    public void insert(Double thickness, String hardness, int length) {
        // pencil.insert(new Lead(thickness, hardness, length));
    }

    public void remove() {
        // pencil.remove();
    }

    public void writePage() {
        // pencil.writePage();
    }

    public void show() {
        // System.out.println(pencil.toString());
    }
}


public class Shell {
    public static void main(String[] _args) {
        Adapter adp = new Adapter(0.5f);

        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if      ("end".equals(args[0])   ) { break;                                                       }
            else if ("init".equals(args[0])  ) { adp = new Adapter(number(args[1]));                          }
            else if ("insert".equals(args[0])) { adp.insert(number(args[1]), args[2], (int) number(args[3])); }
            else if ("remove".equals(args[0])) { adp.remove();                                                }
            else if ("write".equals(args[0]) ) { adp.writePage();                                             }
            else if ("show".equals(args[0])  ) { adp.show();                                                  }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static double number(String str) { return Double.parseDouble(str); }
}
