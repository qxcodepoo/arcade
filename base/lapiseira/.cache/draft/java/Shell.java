import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;

class Adapter {
    // private Pencil pencil = new Pencil(0);
    // 
    public void init(double thickness) {
        // this.pencil = new Pencil(thickness);
    }

    public void insert(double thickness, String hardness, int size) {
        // pencil.insert(new Lead(thickness, hardness, size));
    }

    public void remove() {
        // pencil.remove();
    }

    public void show() {
        // System.out.println(pencil);
    }

    public void write() {
        // pencil.writePage();
    }

    public void pull() {
        // pencil.pull();
    }
}

public class Shell {
    public static void main(String[] _args) {
        
        Adapter adp =   new Adapter();

        while(true) {
            var line = input();
            var args = line.split(" ");
            write("$" + line);

            if(args[0].equals("end")) {
                break;
            } else if(args[0].equals("init")) { //thickness
                adp.init(number(args[1]));
            } else if(args[0].equals("insert")) {//thickness hardness size
                adp.insert(number(args[1]), args[2], (int) number(args[3]));
            } else if(args[0].equals("remove")) {
                adp.remove();
            } else if(args[0].equals("show")) {
                adp.show();
            } else if (args[0].equals("write")) {
                adp.write();
            } else if (args[0].equals("pull")) {
                adp.pull();
            }  else {
                write("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static double number(String str)   { return Double.parseDouble(str); }
}
