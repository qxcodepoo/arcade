import java.util.*;

import java.text.DecimalFormat;


class Calculator {
    public int batteryMax;
    public int battery;
    public float display;

    public Calculator(int batteryMax) {
        this.batteryMax = batteryMax;
        this.battery = 0;
        this.display = 0.0f;
    }

    public void chargeBattery(int value) {
        if (value < 0) {
            return;
        }
        this.battery += value;
        if (this.battery > this.batteryMax) {
            this.battery = this.batteryMax;
        }
    }

    public void sum(int a, int b) {
        if (this.battery == 0) {
            System.out.println("fail: bateria insuficiente");
            return;
        }
        this.battery -= 1;
        this.display = (a + b);
    }

    public void division(int num, int den) {
        if (this.battery == 0) {
            System.out.println("fail: bateria insuficiente");
            return;
        }
        this.battery -= 1;
        if (den == 0) {
            System.out.println("fail: divisao por zero");
            return;
        }
        this.display = (float) num / den;
        
    }
    public String toString() {
        DecimalFormat df = new DecimalFormat("0.00");
        return String.format("display = %s, battery = %d", df.format(this.display), this.battery);
    }
}

class Adapter {
    private Calculator calc = new Calculator(0);
    
    void init() {
        calc = new Calculator(0);
    }

    void show() {
        System.out.println(calc.toString());
    }

    void init(int batteryMax) {
        calc = new Calculator(batteryMax);
    }

    void charge(int value) {
        calc.chargeBattery(value);
    }

    void sum(int a, int b) {
        calc.sum(a, b);
    }

    void div(int a, int b) {
        calc.division(a, b);
    }
}


public class Shell {
    static Adapter adp = new Adapter();

    public static void main(String[] _args) {
        while (true) {
            System.out.print("$");
            var line = input();
            var args = line.split(" ");
            write(line);

            if      (args[0].equals("end"   )) { break;                                                 }
            else if (args[0].equals("show"  )) { adp.show();                                            }
            else if (args[0].equals("init"  )) { adp.init((int) number(args[1]));                       }
            else if (args[0].equals("charge")) { adp.charge((int) number(args[1]));                     }
            else if (args[0].equals("sum"   )) { adp.sum((int) number(args[1]), (int) number(args[2])); }
            else if (args[0].equals("div"   )) { adp.div((int) number(args[1]), (int) number(args[2])); }
            else                               { write("fail: comando invalido");                 }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}