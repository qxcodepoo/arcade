public class Adapter {
    private Calculator calc;
    
    Adapter() {
        calc = new Calculator(0);
    }

    String show() {
        return calc.toString();
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


