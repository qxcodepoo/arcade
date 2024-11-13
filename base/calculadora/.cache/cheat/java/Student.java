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


public class Student {
    private Calculator calc;
    
    Student() {
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

    public static void main(String[] args) {
        System.out.println("Rodando o main de Adapter.java");
    }
}