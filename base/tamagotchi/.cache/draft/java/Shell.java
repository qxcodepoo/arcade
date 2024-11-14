import java.util.*;


public class Shell {
    public static void main(String[] a) {
        Student stu = new Student();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if      (args[0].equals("end"))   { break;                                                                           }
            else if (args[0].equals("show"))  { stu.show();                                                           }
            else if (args[0].equals("init"))  { stu.init((int)number(args[1]), (int)number(args[2]), (int)number(args[3])); }
            else if (args[0].equals("play"))  { stu.play();                                                                      }
            else if (args[0].equals("eat"))   { stu.eat();                                                                       }
            else if (args[0].equals("sleep")) { stu.sleep();                                                                     }
            else if (args[0].equals("shower")){ stu.shower();                                                                    }
            else                              { write("fail: comando invalido");                                                 }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}
