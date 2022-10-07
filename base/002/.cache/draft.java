import java.util.*;

class Car{
    public int pass; // Passageiros
    public int passMax; // limite de Passageiros
    public int gas; // tanque
    public int gasMax; // limite do tanque
    public int km; // quantidade de quilometragem

    public Car() {
        this.pass = 0; // Passageiros
        this.passMax = 2; // limite de Passageiros
        this.gas = 0; // tanque
        this.gasMax = 100; // limite do tanque
        this.km = 0; // quantidade de quilometragem
    }

    public String toString() {
        return "pass: " + pass + ", gas: " + gas + ", km: " + km;
    }

    public void enter() {
        if (pass < passMax) {
            pass += 1;
            return;
        }
        System.out.println("fail: limite de pessoas atingido");
    }

    public void leave() {
        if (pass > 0) {
            pass-=1;
            return;
        }
        System.out.println("fail: nao ha ninguem no carro");
    }
    
    public void fuel(int gas) {
        this.gas += gas;
        if(this.gas > gasMax)
            this.gas = gasMax;
    }

    public void drive (int km) {
        if(this.pass == 0) {
            System.out.println("fail: nao ha ninguem no carro");
        } else if(this.gas == 0) {
            System.out.println("fail: tanque vazio");
        }
        else if(this.gas < km) {
            System.out.println("fail: tanque vazio apos andar " + this.gas + " km");
            this.km += this.gas;
            this.gas = 0;
        } else{
            this.gas = gas - km;
            this.km = this.km + km;
        }
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


