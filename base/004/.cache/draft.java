import java.text.DecimalFormat;
import java.util.Scanner;

class Lead { //todo
    private float thickness; //calibre
    private String hardness; //dureza
    private int size; //tamanho em mm

    public Lead(float thickness, String hardness, int size) { //todo
    }

    public float getThickness() { //todo
    }

    public String getHardness() { //todo
    }

    public int getSize() { //todo
    }

    public void setSize(int size) { //todo
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


class Pencil { //todo
    private float thickness;
    private Lead tip;

    public Pencil(float thickness) { //todo
    }

    public float getThickness() { //todo
    }

    public void setThickness(float value) { //todo
    }

    public boolean hasGrafite() { //todo
    }

    public boolean insert(Lead grafite) { //todo
    }

    public Lead remove() { //todo
    }

    public void writePage() { //todo
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
    public static void main(String[] args) {
        Pencil lap = new Pencil(0.5f);

        while (true) {
            String line = input();
            String[] argsL = line.split(" ");
            write('$' + line);

            if      ("end".equals(argsL[0])   ) { break;                                                                    }
            else if ("init".equals(argsL[0])  ) { lap = new Pencil(number(argsL[1]));                                       }
            else if ("insert".equals(argsL[0])) { lap.insert(new Lead(number(argsL[1]), argsL[2], (int) number(argsL[3]))); }
            else if ("remove".equals(argsL[0])) { lap.remove();                                                             }
            else if ("write".equals(argsL[0]) ) { lap.writePage();                                                          }
            else if ("show".equals(argsL[0])  ) { write(lap.toString());                                                               }
        }
    }

    static Scanner scanner = new Scanner(System.in);

    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static float number(String str) { return Float.parseFloat(str); }
}
