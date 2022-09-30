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

        sh.addCmd("show",   () -> { System.out.println(calc);                          });
        sh.addCmd("init",   () -> { calc = new Calculator(sh.getInt(1)              ); });
        sh.addCmd("charge", () -> {    calc.chargeBattery(sh.getInt(1)              ); });
        sh.addCmd("sum",    () -> {              calc.sum(sh.getInt(1), sh.getInt(2)); });
        sh.addCmd("div",    () -> {         calc.division(sh.getInt(1), sh.getInt(2)); });

        sh.evaluate();
    }
}


