import java.util.*;

public class Shell {
    Student adp = new Student();

    public void processLine(String line) {
        var args = line.split(" ");
        if      (args[0].equals("show"))  { adp.show();                           }
        else if (args[0].equals("enter")) { adp.enter();                          }
        else if (args[0].equals("leave")) { adp.leave();                          }
        else if (args[0].equals("drive")) { adp.drive(Integer.parseInt(args[1])); }
        else if (args[0].equals("fuel"))  { adp.fuel(Integer.parseInt(args[1]));  }
        else                              { System.out.println("fail: comando invalido");}
    }

    public static void main(String[] a) {
        Shell shell = new Shell();

        while (true) {
            System.out.print("$");
            var line = input();
            write(line); // comente para executar interativamente
            if (line.equals("end")) {
                break;
            }
            shell.processLine(line);
        }
    }
    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static void    write(String value)  { System.out.println(value); }
}
