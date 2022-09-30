import java.util.*;

class Car{
    public int pass; // Passageiros
    public int passMax; // limite de Passageiros
    public int gas; // tanque
    public int gasMax; // limite do tanque
    public int km; // quantidade de quilometragem

    public Car() { //todo
    }

    public String toString() { //todo
    }

    public void enter() { //todo
    }

    public void leave() { //todo
    }
    
    public void fuel(int gas) { //todo
    }

    public void drive (int km) { //todo
    }    
};

public class Solver {

    static Shell sh = new Shell();
    static Car car = new Car();

    public static void main(String[] args) {

        sh.setfn("show",   () -> { System.out.println(car);    });
        sh.setfn("enter",  () -> { car.enter();                });
        sh.setfn("leave",  () -> { car.leave();                });
        sh.setfn("drive",  () -> { car.drive(toInt(sh.par(1)));});
        sh.setfn("fuel",   () -> {  car.fuel(toInt(sh.par(1)));});

        sh.execute();
    }

    static int toInt(String s) {
        return Integer.parseInt(s);
    }
}

class Shell {    
    private Scanner scanner = new Scanner(System.in);
    private HashMap<String, Runnable> chain = new HashMap<>();
    private ArrayList<String> ui = new ArrayList<>();

    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }

    public void setfn(String key, Runnable value) {
        chain.put(key, value);
    }

    public String par(int index) {
        return ui.get(index);
    }

    public void execute() {
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


