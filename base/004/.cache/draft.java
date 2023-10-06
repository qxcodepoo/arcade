import java.text.DecimalFormat;
import java.util.Scanner;

class Lead {
    private float thickness; //calibre
    private String hardness; //dureza
    private int size; //tamanho em mm

    public Lead(float thickness, String hardness, int size) {
    }

    public float getThickness() {
    }

    public String getHardness() {
    }

    public int getSize() {
    }

    public void setSize(int size) {
    }

    public int usagePerSheet() {
        if(hardness.equals("HB"))
            return 1;
        else if(hardness.equals("2B"))
            return 2;
        else if(hardness.equals("4B"))
            return 4;
        else
            return 6;
    }

    public String toString() {
        DecimalFormat form = new DecimalFormat("0.0");
        return form.format(thickness) + ":" + hardness + ":" + size;
    }
}


class Pencil {
    private float thickness;
    private Lead tip;

    public Pencil(float thickness) {
    }

    public float getThickness() {
    }

    public void setThickness(float value) {
    }

    public boolean hasLead() {
    }

    public boolean insert(Lead grafite) {
    }

    public Lead remove() {
    }

    public void writePage() {
    }
    
    public String toString() {
        String saida = "calibre: " + thickness + ", grafite: ";
        if (tip != null)
            saida += "[" + tip + "]";
        else
            saida += "null";
        return saida;
    }
}

public class Solver {
    public static void main(String[] _args) {
        Pencil pencil = new Pencil(0.5f);

        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if      ("end".equals(args[0])   ) { break;                                                                    }
            else if ("init".equals(args[0])  ) { pencil = new Pencil(number(args[1]));                                       }
            else if ("insert".equals(args[0])) { pencil.insert(new Lead(number(args[1]), args[2], (int) number(args[3]))); }
            else if ("remove".equals(args[0])) { pencil.remove();                                                             }
            else if ("write".equals(args[0]) ) { pencil.writePage();                                                          }
            else if ("show".equals(args[0])  ) { write(pencil.toString());                                                               }
        }
    }

    static Scanner scanner = new Scanner(System.in);

    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static float number(String str) { return Float.parseFloat(str); }
}
