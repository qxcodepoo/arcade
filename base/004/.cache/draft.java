import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Collections;


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
    static Shell sh = new Shell();
    static Pencil lap = new Pencil(0.5f);

    public static void main(String[] args) {
        sh.addCmd("init",   () -> lap = new Pencil(sh.getFloat(1)));
        sh.addCmd("insert", () -> lap.insert(new Lead(sh.getFloat(1), sh.getStr(2), sh.getInt(3))));
        sh.addCmd("remove", () -> lap.remove());
        sh.addCmd("write",  () -> lap.writePage());
        sh.addCmd("show",   () -> System.out.println(lap.toString()));

        sh.evaluate();
    }
}

