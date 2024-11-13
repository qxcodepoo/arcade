import java.util.Scanner;

public class Shell {
    public static void main(String[] _args) {
        Student adp = new Student(0.5f);

        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if      ("end".equals(args[0])   ) { break;                                                       }
            else if ("init".equals(args[0])  ) { adp = new Student(number(args[1]));                          }
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