import java.util.Scanner;
import java.text.DecimalFormat;

// @DROP

enum InsertResult {
    OK,
    ALREADY_HAS_LEAD,
    WRONG_THICKNESS
}

enum WriteResult {
    OK,
    NO_LEAD,
    INSUFFICIENT,
    INCOMPLETE
}

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

    public int getWearPerPage() {
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

    public boolean consume(int amount) {
        int finalSize = this.size - amount;
        if (finalSize < 10) {
            this.size = 10;
            return false;
        }
        this.size = finalSize;
        return true;
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

    public boolean hasLead() {
        return tip != null;
    }

    public InsertResult insert(Lead grafite) {
        if(this.hasLead()) {
            return InsertResult.ALREADY_HAS_LEAD;
        }
        if(this.thickness != grafite.getThickness()) {
            return InsertResult.WRONG_THICKNESS;
        }
        
        this.tip = grafite;
        return InsertResult.OK;
    }

    public Lead remove() {
        if(this.tip == null) {
            return null;
        }
        Lead backup = this.tip;
        this.tip = null;
        return backup;
    }

    public WriteResult writePage() {
        if(this.tip == null) {
            return WriteResult.NO_LEAD;
        }
        if (this.tip.getSize() == 10) {
            return WriteResult.INSUFFICIENT;
        }
        if (!this.tip.consume(this.tip.getWearPerPage())) {
            return WriteResult.INCOMPLETE;
        }
        return WriteResult.OK;
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
                printInsertResult(pencil.insert(lead));
            }
            else if (cmd.equals("remove")) { 
                // @DROP
                if (pencil.remove() == null) {
                    System.out.println("fail: nao existe grafite");
                }
            }
            else if (cmd.equals("write")) { 
                // @DROP
                printWriteResult(pencil.writePage());
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static void printInsertResult(InsertResult result) {
        if (result == InsertResult.ALREADY_HAS_LEAD)
            System.out.println("fail: ja existe grafite");
        else if (result == InsertResult.WRONG_THICKNESS)
            System.out.println("fail: calibre incompativel");
    }

    private static void printWriteResult(WriteResult result) {
        if (result == WriteResult.NO_LEAD)
            System.out.println("fail: nao existe grafite");
        else if (result == WriteResult.INSUFFICIENT)
            System.out.println("fail: tamanho insuficiente");
        else if (result == WriteResult.INCOMPLETE)
            System.out.println("fail: folha incompleta");
    }

    static Scanner scanner = new Scanner(System.in);
}
