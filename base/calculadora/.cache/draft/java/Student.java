import java.text.DecimalFormat;

    // public String toString() {
    //     DecimalFormat df = new DecimalFormat("0.00");
    //     return String.format("display = %s, battery = %d", df.format(this.display), this.battery);
    // }
public class Student {
    // private Calculator calc;
    // 
    Student() {
        // calc = new Calculator(0);
    }

    void show() {
        // System.out.println(calc.toString());
    }

    void init(int batteryMax) {
        // calc = new Calculator(batteryMax);
    }

    void charge(int value) {
        // calc.chargeBattery(value);
    }

    void sum(int a, int b) {
        // calc.sum(a, b);
    }

    void div(int a, int b) {
        // calc.division(a, b);
    }

    public static void main(String[] args) {
        System.out.println("Rodando o main de Adapter.java");
    }
}