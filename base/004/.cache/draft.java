import java.text.DecimalFormat;
import java.util.*;

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
        sh.chain.put("init",   () -> lap = new Pencil(getFloat(1)));
        sh.chain.put("insert", () -> lap.insert(new Lead(getFloat(1), sh.param.get(2), getInt(3))));
        sh.chain.put("remove", () -> lap.remove());
        sh.chain.put("write",  () -> lap.writePage());
        sh.chain.put("show",   () -> System.out.println(lap.toString()));

        sh.execute();
    }
    static float getFloat(int index) {
        return Float.parseFloat(sh.param.get(index));
    }
    static int getInt(int index) {
        return Integer.parseInt(sh.param.get(index));
    }
}

class Shell {    
    public Scanner scanner = new Scanner(System.in);
    public HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String> param = new ArrayList<>();
    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }
    public void execute() {
        while(true) {
            param.clear();
            String line = scanner.nextLine();
            Collections.addAll(param, line.split(" "));
            System.out.println("$" + line);
            if(param.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(param.get(0))) {
                chain.get(param.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}

