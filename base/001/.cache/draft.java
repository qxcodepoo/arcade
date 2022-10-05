import java.util.*;
import java.text.*;

class Calculator { //todo
    public int batteryMax;
    public int battery;
    public float display;

    //Inicia os atributos, battery e display começam com o zero.
    public Calculator(int batteryMax) { //todo
    }

    //Aumenta a bateria, porém não além do máximo.
    public void chargeBattery(int value) { //todo 
    }

    //Tenta gastar uma unidade da bateria e emite um erro se não conseguir.
    public boolean useBattery() { //todo 
    }

    //Se conseguir gastar bateria, armazene a soma no atributo display.
    public void sum(int a, int b) { //todo 
    }

    //Se conseguir gastar bateria e não for divisão por 0.
    public void division(int num, int den) { //todo
    }

    //Retorna o conteúdo do display com duas casas decimais.
    public String toString() { 
        DecimalFormat form = new DecimalFormat("0.00");
        return "display = " + form.format(this.display).replace(",",".") + ", battery = " + this.battery;
    }
}

public class Solver {

    static Shell sh = new Shell();
    static Calculator calc = new Calculator(0);

    public static void main(String[] args) {
        var chain = sh.chain;
        var param = sh.param;

        chain.put("show",   () -> { System.out.println(calc);                    });
        chain.put("init",   () -> { calc = new Calculator(parInt(1)           ); });
        chain.put("charge", () -> {    calc.chargeBattery(parInt(1)           ); });
        chain.put("sum",    () -> {              calc.sum(parInt(1), parInt(2)); });
        chain.put("div",    () -> {         calc.division(parInt(1), parInt(2)); });

        sh.execute();
    }
    static int parInt(int index) {
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
