import java.util.Scanner;

public class Shell {

    public static void main(String[] _args) {
        Student adp = new Student("", "");

        while (true) {
            System.out.print("$");
            var line = input();
            var args = line.split(" ");
            write(line); //test echo

            if      (args[0].equals("end")  ) { break;                               }

            else if (args[0].equals("init") ) { adp = new Student(args[1], args[2]); }
            else if (args[0].equals("show") ) { adp.show();                          }
            else if (args[0].equals("noise")) { adp.noise();                         }
            else if (args[0].equals("grow") ) { adp.grow((int) number(args[1]));     }

            else                              { write("fail: comando invalido");     }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);}
    public static double number(String str)   { return Double.parseDouble(str); }
}
