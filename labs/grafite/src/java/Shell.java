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
        return form.format(thickness).replace(',', '.') + ":" + hardness + ":" + size;
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

    public String insert(Lead grafite) {
        if(this.hasLead()) {
            return "fail: ja existe grafite";
        }
        if(this.thickness != grafite.getThickness()) {
            return "fail: calibre incompativel";
        }
        
        this.tip = grafite;
        return null;
    }

    public Lead remove() {
        if(this.tip == null) {
            return null;
        }
        Lead backup = this.tip;
        this.tip = null;
        return backup;
    }

    public String writePage() {
        if(this.tip == null) {
            return "fail: nao existe grafite";
        }
        if (this.tip.getSize() == 10) {
            return "fail: tamanho insuficiente";
        }
        int finalSize = this.tip.getSize() - this.tip.usagePerSheet();
        if(finalSize < 10) {
            this.tip.setSize(10);
            return "fail: folha incompleta";
        }
        this.tip.setSize(finalSize);
        return null;
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
                var error = pencil.insert(lead);
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("remove")) { 
                // @DROP
                if (pencil.remove() == null) {
                    System.out.println("fail: nao existe grafite");
                }
            }
            else if (cmd.equals("write")) { 
                // @DROP
                var error = pencil.writePage();
                if (error != null) System.out.println(error);
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
