import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;

class Lead {
    private float thickness;
    private String hardness;
    private int size;

    public Lead(float thickness, String hardness, int size) {
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
    public float getThickness() {
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
    private float thickness;
    private Lead tip; //lead da ponta
    private ArrayList<Lead> barrel; //grafites no cano

    public Pencil(float thickness) {
        this.thickness = thickness;
        this.barrel = new ArrayList<>();
    }

    public String toString() {
        String saida = "calibre: " + thickness + ", bico: ";
        if (this.tip != null)
            saida += "[" + this.tip + "]";
        else
            saida += "[]";
        saida += ", tambor: {";
            for (Lead g : barrel)
                saida += "[" + g + "]";
        return saida + "}";
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
}
//!KEEP
class Solver{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pencil lapiseira = new Pencil(0.5f);
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            if(ui[0].equals("end")) {
                break;
            } else if(ui[0].equals("help")) {
                System.out.println("init _calibre; insert _calibre _dureza _tamanho; remove; writePage _folhas");
            } else if(ui[0].equals("init")) { //thickness
                lapiseira = new Pencil(Float.parseFloat(ui[1]));
            } else if(ui[0].equals("insert")) {//thickness hardness size
                float thickness = Float.parseFloat(ui[1]);
                String hardness  = ui[2];
                int size = Integer.parseInt(ui[3]);
                lapiseira.insert(new Lead(thickness, hardness, size));
            } else if(ui[0].equals("remove")) {
                lapiseira.remove();
            } else if(ui[0].equals("show")) {
                System.out.println(lapiseira);
            } else if (ui[0].equals("write")) {
                lapiseira.writePage();
            } else if (ui[0].equals("pull")) {
                lapiseira.pull();
            }  else {
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}


//!OFF