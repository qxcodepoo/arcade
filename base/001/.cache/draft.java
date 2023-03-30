import java.util.*;
import java.text.*;

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
        if (value < 0)
            return;
        this.battery += value;
        if (this.battery > this.batteryMax)
            this.battery = this.batteryMax;
    }

    public boolean useBattery() { 
        if (this.battery == 0){
            System.out.println("fail: bateria insuficiente");
            return false;
        }
        this.battery -= 1;
        return true;
    }

    public void sum(int a, int b) { 
        if (useBattery())
            this.display = (a + b);
    }

    public void division(int num, int den) {
        if (!useBattery())
            return;
        if (den == 0){
            System.out.println("fail: divisao por zero");
        }
        else
            this.display = (float) num / den;
    }

    public String toString() { 
        DecimalFormat form = new DecimalFormat("0.00");
        return "display = " + form.format(this.display).replace(",", ".") + ", battery = " + this.battery;
    }
}

public class Solver {
    static Calculator calc = new Calculator(0);

    public static void main(String[] args) {
        while (true)
        {
            String line = input();
            String[] argsL = line.split(" ");
            write('$' + line);

            if      ("show".equals(argsL[0]))    { write(calc.toString());                            }
            else if ("init".equals(argsL[0]))    { calc = new Calculator(number(argsL[1]));           }   
            else if ("charge".equals(argsL[0]))  { calc.chargeBattery(number(argsL[1]));              }
            else if ("sum".equals(argsL[0]))     { calc.sum(number(argsL[1]), number(argsL[2]));      }
            else if ("div".equals(argsL[0]))     { calc.division(number(argsL[1]), number(argsL[2])); }
            else if ("end".equals(argsL[0]))     { break;                                             }
            else                                 { write("fail: comando invalido");             }
        }
    }

    public static String input() { 
        Scanner scanner = new Scanner(System.in); 
        String input = scanner.nextLine(); 
        scanner.close(); 
        return input; 
    }

    public static void write(String value) { System.out.println(value);                }
    public static int number(String str)   { return Integer.parseInt(str);             }
}
