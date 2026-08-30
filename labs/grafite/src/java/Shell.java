import java.util.Scanner;
import java.text.DecimalFormat;

// @DROP

class Lead {
    private double thickness; //calibre
    private String hardness; //dureza
    private int size; //tamanho em mm

    public Lead(double thickness, String hardness, int size) {
        this.thickness = thickness;
        this.hardness = hardness;
        this.size = size;
    }

    public double getThickness() {
        return thickness;
    }

    public String getHardness() {
        return hardness;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int usagePerSheet() {
        if(hardness.equals("HB")) {
            return 1;
        } else if(hardness.equals("2B")) {
            return 2;
        } else if(hardness.equals("4B")) {
            return 4;
        } else {
            return 6;
        }
    }

    public String toString() {
        DecimalFormat form = new DecimalFormat("0.0");
        return form.format(thickness) + ":" + hardness + ":" + size;
    }
}

class Pencil {
    private double thickness;
    private Lead tip;

    public Pencil(double thickness) {
        this.thickness = thickness;
        this.tip = null;
    }

    public double getThickness() {
        return thickness;
    }

    public void setThickness(double value) {
        this.thickness = value;
    }

    public boolean hasLead() {
        return tip != null;
    }

    public boolean insert(Lead grafite) {
        if(this.hasLead()) {
            System.out.println("fail: ja existe grafite");
            return false;
        }
        if(this.thickness != grafite.getThickness()) {
            System.out.println("fail: calibre incompativel");
            return false;
        }
        
        this.tip = grafite;
        return true;
    }

    public Lead remove() {
        if(this.tip == null) {
            System.out.println("fail: nao existe grafite");
            return null;
        }
        Lead backup = this.tip;
        this.tip = null;
        return backup;
    }

    public void writePage() {
        if(this.tip == null) {
            System.out.println("fail: nao existe grafite");
            return;
        }
        if (this.tip.getSize() == 10) {
            System.out.println("fail: tamanho insuficiente");
            return;
        }
        int finalSize = this.tip.getSize() - this.tip.usagePerSheet();
        if(finalSize < 10) {
            this.tip.setSize(10);
            System.out.println("fail: folha incompleta");
            return;
        }
        this.tip.setSize(finalSize);
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

// @KEEP

public class Shell {
    public static void main(String[] args) {
        // @DROP
        Pencil pencil = new Pencil(0.5);
        // @KEEP

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // @COM
            else if (cmd.equals("init")) { 
                var thickness = Double.parseDouble(par[1]);
                // @DROP
                pencil = new Pencil(thickness);
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(pencil);
            }
            else if (cmd.equals("insert")) { 
                var thickness = Double.parseDouble(par[1]);
                var hardness = par[2];
                var size = Integer.parseInt(par[3]);
                // @DROP
                var lead = new Lead(thickness, hardness, size);
                pencil.insert(lead);
            }
            else if (cmd.equals("remove")) { 
                // @DROP
                pencil.remove();
            }
            else if (cmd.equals("write")) { 
                // @DROP
                pencil.writePage();
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
