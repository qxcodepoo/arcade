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


public class Shell {

    public static void main(String[] args) {
        Calculator calculator = new Calculator(0);
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                int batteryMax = Integer.parseInt(par[1]);
                calculator = new Calculator(batteryMax);
            } 
            else if (cmd.equals("show")) {
                System.out.println(calculator);
            } 
            else if (cmd.equals("charge")) {
                int value = Integer.parseInt(par[1]);
                calculator.chargeBattery(value);
            } 
            else if (cmd.equals("sum")) {
                int a = Integer.parseInt(par[1]);
                int b = Integer.parseInt(par[2]);
                calculator.sum(a, b);
            } 
            else if (cmd.equals("div")) {
                int num = Integer.parseInt(par[1]);
                int den = Integer.parseInt(par[2]);
                calculator.division(num, den);
            } 
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}