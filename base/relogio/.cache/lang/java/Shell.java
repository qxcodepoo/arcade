import java.util.*;

public class Shell {
    public static void main(String[] a) {
        Time time = new Time(0, 0, 0);
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            
            if (args[0].equals("show"))  { 
                write("" + time); 
            }
            else if (args[0].equals("init")) {
                time = new Time((int)number(args[1]), (int)number(args[2]), (int)number(args[3]));
            }
            else if (args[0].equals("set")) {
                time.setHour((int)number(args[1]));
                time.setMinute((int)number(args[2]));
                time.setSecond((int)number(args[3]));
            }
            else if (args[0].equals("next"))  { 
                time.nextSecond(); 
            }
            else if (args[0].equals("end"))   { 
                break; 
            }
            else { 
                write("fail: comando invalido"); 
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}