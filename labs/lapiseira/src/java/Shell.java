import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;
// @DROP

enum InsertResult {
    OK,
    WRONG_THICKNESS
}

enum PullResult {
    OK,
    TIP_OCCUPIED,
    BARREL_EMPTY
}

enum WriteResult {
    OK,
    NO_LEAD,
    INSUFFICIENT,
    INCOMPLETE
}

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

    public int getWearPerPage() {
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
    public boolean consume(int amount) {
        int finalSize = this.size - amount;
        if (finalSize < 10) {
            this.size = 10;
            return false;
        }
        this.size = finalSize;
        return true;
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
    public InsertResult insert(Lead lead) {
        if(this.thickness != lead.getThickness()) {
            return InsertResult.WRONG_THICKNESS;
        }
        this.barrel.add(lead);
        return InsertResult.OK;
    }

    //remove e retorna o lead da ponta
    public Lead remove() {
        if(this.tip == null) {
            return null;
        }
        Lead backup = this.tip;
        this.tip = null;
        return backup;
    }

    // se a ponta estiver vazia, puxa o próximo lead do barril
    public PullResult pull() {
        if (this.tip != null) {
            return PullResult.TIP_OCCUPIED;
        }
        if (this.barrel.size() == 0) {
            return PullResult.BARREL_EMPTY;
        }
        this.tip = this.barrel.remove(0);
        return PullResult.OK;
    }

    //se tiver grafite suficiente no bico, gaste e retorne true
    //lembre que os últimos 10mm não podem ser utilizados
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
                printInsertResult(adp.insert(new Lead(thickness, hardness, size)));
            } 
            else if (cmd.equals("remove")) { 
                // @DROP
                if (adp.remove() == null)
                    System.out.println("fail: nao existe grafite no bico");
            } 
            else if (cmd.equals("write")) { 
                // @DROP
                printWriteResult(adp.writePage());
            } 
            else if (cmd.equals("pull")) { 
                // @DROP
                printPullResult(adp.pull());
            } 
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static void printInsertResult(InsertResult result) {
        if (result == InsertResult.WRONG_THICKNESS)
            System.out.println("fail: calibre incompatível");
    }

    private static void printPullResult(PullResult result) {
        if (result == PullResult.TIP_OCCUPIED)
            System.out.println("fail: ja existe grafite no bico");
        else if (result == PullResult.BARREL_EMPTY)
            System.out.println("fail: nao existe grafite no barril");
    }

    private static void printWriteResult(WriteResult result) {
        if (result == WriteResult.NO_LEAD)
            System.out.println("fail: nao existe grafite no bico");
        else if (result == WriteResult.INSUFFICIENT)
            System.out.println("fail: tamanho insuficiente");
        else if (result == WriteResult.INCOMPLETE)
            System.out.println("fail: folha incompleta");
    }

    static Scanner scanner = new Scanner(System.in);
}
