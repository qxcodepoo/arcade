import java.util.*;

class Shell {    
    private Scanner scanner = new Scanner(System.in);
    private HashMap<String, Runnable> chain = new HashMap<>();
    private ArrayList<String> ui = new ArrayList<>();

    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }

    public void addCmd(String key, Runnable value) {
        chain.put(key, value);
    }

    public int getInt(int index) {
        return Integer.parseInt(ui.get(index));
    }

    public double getDouble(int index) {
        return Double.parseDouble(ui.get(index));
    }

    public float getFloat(int index) {
        return Float.parseFloat(ui.get(index));
    }
    
    public String getStr(int index) {
        return ui.get(index);
    }

    public void execute() {
        while(true) {
            ui.clear();
            System.out.print("$");
            String line = scanner.nextLine();
            Collections.addAll(ui, line.split(" "));
            if(ui.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(ui.get(0))) {
                chain.get(ui.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    public void evaluate() {
        while(true) {
            ui.clear();
            String line = scanner.nextLine();
            Collections.addAll(ui, line.split(" "));
            System.out.println("$" + line);
            if(ui.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(ui.get(0))) {
                chain.get(ui.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
