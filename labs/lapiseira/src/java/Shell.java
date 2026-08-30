import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;
// @DROP

class Lead {
    private double thickness;
    private String hardness;
    private int size;

    public Lead(double thickness, String hardness, int size) {
        this.thickness = thickness;
        this.hardness = hardness;
        this.size = size;
    }

    public String toString() {
        DecimalFormat form = new DecimalFormat("0.0");
        return form.format(thickness) + ":" + hardness + ":" + size;
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
}

class Pencil {
    private double thickness;
    private Lead tip; //lead da ponta
    private ArrayList<Lead> barrel; //grafites no cano

    public Pencil(double thickness) {
        this.thickness = thickness;
        this.barrel = new ArrayList<>();
    }

    //insere um lead no barril
    public boolean insert(Lead lead) {
        if(this.thickness != lead.getThickness()) {
            System.out.println("fail: calibre incompatível");
            return false;
        }
        this.barrel.add(lead);
        return true;
    }

    //remove e retorna o lead da ponta
    public Lead remove() {
        if(this.tip == null) {
            System.out.println("fail: nao existe grafite no bico");
            return null;
        }
        Lead backup = this.tip;
        this.tip = null;
        return backup;
    }

    // se a ponta estiver vazia, puxa o próximo lead do barril
    public boolean pull() {
        if (this.tip != null) {
            System.out.println("fail: ja existe grafite no bico");
            return false;
        }
        if (this.barrel.size() == 0) {
            System.out.println("fail: nao existe grafite no barril");
            return false;
        }
        this.tip = this.barrel.remove(0);
        return true;
    }

    //se tiver grafite suficiente no bico, gaste e retorne true
    //lembre que os últimos 10mm não podem ser utilizados
    public void writePage() {
        if(this.tip == null) {
            System.out.println("fail: nao existe grafite no bico");
            return;
        }
        if (this.tip.getSize() == 10) {
            System.out.println("fail: tamanho insuficiente");
            return;
        }
        int finalSize = this.tip.getSize() - this.tip.usagePerSheet();
        if(finalSize >= 10) {
            this.tip.setSize(finalSize);
        } else {
            this.tip.setSize(10);
            System.out.println("fail: folha incompleta");
        }
    }

    public String toString() {
        String saida = "calibre: " + thickness + ", bico: ";
        if (this.tip != null) {
            saida += "[" + this.tip + "]";
        } else {
            saida += "[]";
        }
        saida += ", tambor: <";
        for (Lead g : barrel) {
            saida += "[" + g + "]";
        }
        return saida + ">";
    }
}
// @KEEP
public class Shell {
    public static void main(String[] _args) {
        // @DROP
        Pencil adp = new Pencil(0);
        // @KEEP

        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(adp);
            } 
            else if (cmd.equals("init")) { 
                // @COM
                var thickness = Double.parseDouble(par[1]);
                // @DROP
                adp = new Pencil(thickness);
            } 
            else if (cmd.equals("insert")) { 
                // @COM
                var thickness = Double.parseDouble(par[1]);
                var hardness = par[2];
                var size = Integer.parseInt(par[3]);
                // @DROP
                adp.insert(new Lead(thickness, hardness, size));
            } 
            else if (cmd.equals("remove")) { 
                // @DROP
                adp.remove();
            } 
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(adp);
            } 
            else if (cmd.equals("write")) { 
                // @DROP
                adp.writePage();
            } 
            else if (cmd.equals("pull")) { 
                // @DROP
                adp.pull();
            } 
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
