import java.util.*;

class Shell {    
    private Scanner scanner = new Scanner(System.in);
    private HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String> param = new ArrayList<>();

    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }

    public void addCmd(String key, Runnable value) {
        chain.put(key, value);
    }

    public int getInt(int index) {
        return Integer.parseInt(param.get(index));
    }

    public double getDouble(int index) {
        return Double.parseDouble(param.get(index));
    }

    public float getFloat(int index) {
        return Float.parseFloat(param.get(index));
    }
    
    public String getStr(int index) {
        return param.get(index);
    }

    public void execute() {
        while(true) {
            param.clear();
            System.out.print("$");
            String line = scanner.nextLine();
            Collections.addAll(param, line.split(" "));
            if(param.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(param.get(0))) {
                chain.get(param.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    public void evaluate() {
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
