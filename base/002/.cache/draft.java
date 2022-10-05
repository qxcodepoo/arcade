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
        var chain = sh.chain;
        var param = sh.param;

        chain.put("show",   () -> { System.out.println(car);    });
        chain.put("enter",  () -> { car.enter();                });
        chain.put("leave",  () -> { car.leave();                });
        chain.put("drive",  () -> { car.drive(parInt(1));});
        chain.put("fuel",   () -> {  car.fuel(parInt(1));});

        sh.execute();
    }

    static int parInt(int index) {
        return Integer.parseInt(param.get(index));
    }
}

class Shell {    
    public Scanner scanner = new Scanner(System.in);
    public HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String>         param = new ArrayList<>();
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


