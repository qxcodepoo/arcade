import java.util.*;

public class Shell {
    public static void main(String[] a) {
        Student stu = new Student(0, 0, 0);
        
        while (true) {
            System.out.print("$");

            var line = input();
            write(line);

            var args = line.split(" ");

            
            if (args[0].equals("show"))  { 
                stu.show(); 
            }
            else if (args[0].equals("init")) {
                stu = new Student((int)number(args[1]), (int)number(args[2]), (int)number(args[3]));
            }
            else if (args[0].equals("set")) {
                stu.setHour((int)number(args[1]));
                stu.setMinute((int)number(args[2]));
                stu.setSecond((int)number(args[3]));
            }
            else if (args[0].equals("next"))  { 
                stu.nextSecond(); 
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