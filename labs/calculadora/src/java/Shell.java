import java.util.*;
import java.text.DecimalFormat;

// @DROP

enum DivisionResult {
    OK, NO_BATTERY, DIVISION_BY_ZERO
}

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

    public boolean sum(int a, int b) {
        if (this.battery == 0) {
            return false;
        }
        this.battery -= 1;
        this.display = (a + b);
        return true;
    }

    public DivisionResult division(int num, int den) {
        if (this.battery == 0) {
            return DivisionResult.NO_BATTERY;
        }
        this.battery -= 1;
        if (den == 0) {
            return DivisionResult.DIVISION_BY_ZERO;
        }
        this.display = (float) num / den;
        return DivisionResult.OK;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("0.00");
        return String.format("display = %s, battery = %d", df.format(this.display).replace(',', '.'), this.battery);
    }
}

// @KEEP

public class Shell {
    static String NoBatteryMsg = "fail: bateria insuficiente";
    static String DivisionByZeroMsg = "fail: divisao por zero";
    static String InvalidCommandMsg = "fail: comando invalido";

    public static void main(String[] args) {
        // @COM
        Calculator calculator = new Calculator(0);
        // @KEEP
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // CHAME O CONSTRUTOR
                // @COM
                int batteryMax = Integer.parseInt(par[1]);
                // @DROP
                calculator = new Calculator(batteryMax);
            } 
            else if (cmd.equals("show")) {
                // MOSTRAR
                // @DROP
                System.out.println(calculator);
            } 
            else if (cmd.equals("charge")) {
                // RECARREGAR A BATERIA
                // @COM
                int value = Integer.parseInt(par[1]);
                // @DROP
                calculator.chargeBattery(value);
            } 
            else if (cmd.equals("sum")) {
                // SOMAR
                // @COM
                int a = Integer.parseInt(par[1]);
                int b = Integer.parseInt(par[2]);
                // @DROP
                if (!calculator.sum(a, b)) {
                    System.out.println(NoBatteryMsg);
                }
            } 
            else if (cmd.equals("div")) {
                // DIVIDIR
                // @COM
                int num = Integer.parseInt(par[1]);
                int den = Integer.parseInt(par[2]);
                // @DROP
                switch (calculator.division(num, den)) {
                    case NO_BATTERY:
                        System.out.println(NoBatteryMsg);
                        break;
                    case DIVISION_BY_ZERO:
                        System.out.println(DivisionByZeroMsg);
                        break;
                    case OK:
                        break;
                }
            } 
            else {
                System.out.println(InvalidCommandMsg);
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
