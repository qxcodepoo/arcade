import java.util.*;

// Nesse rascunho, falta a parte do nextSecond

class Time {
    private int hour   = 0;
    private int minute = 0;
    private int second = 0;

    public Time(int hour, int minute, int second) {
    }

    public void setHour(int hour) {
    }
    public void setMinute(int minute) {
    }
    public void setSecond(int second) {
    }
    public int getHour() {
    }
    public int getMinute() {
    }
    public int getSecond() {
    }
    public String toString() {
        return String.format("%02d:%02d:%02d", hour, minute, second);
    }
}

public class Solver {
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