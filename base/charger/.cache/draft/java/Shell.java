import java.util.Scanner;

class Adapter {
    // private Notebook notebook = new Notebook();
    public void show() {
        // System.out.println(notebook);
    }

    public void turnOn() {
        // notebook.turnOn();
    }

    public void turnOff() {
        // notebook.turnOff();
    }

    public void setCharger(int power) {
        //Implementar
    }

    public void removeCharger() {
        // Charger charger = notebook.removeCharger();
        // if (charger != null) {
        //     System.out.println("Removido " + charger);
        // } else {
        //     System.out.println("fail: Sem carregador");
        // }
    }

    public void setBattery(int capacity) {
        //Implementar
    }

    public void removeBattery() {
        // Bateria battery = notebook.removeBattery();
        // if (battery != null) {
        //     System.out.println("Removido " + battery);
        // } else {
        //     System.out.println("fail: Sem bateria");
        // }
    }

    public void use(int minutes) {
        // notebook.use(minutes);
    }
}

public class Shell {
    public static void main(String[] _args) {
        Adapter adapter = new Adapter();

        while (true) {
            var line = input();
            var args = line.split(" ");
            write("$" + line + "\n");

            if      (args[0].equals("end")        ) { break;                                         }
            else if (args[0].equals("show")       ) { adapter.show();                                }
            else if (args[0].equals("turn_on")    ) { adapter.turnOn();                              }
            else if (args[0].equals("turn_off")   ) { adapter.turnOff();                             }
            else if (args[0].equals("set_charger")) { adapter.setCharger(Integer.parseInt(args[1])); }
            else if (args[0].equals("set_battery")) { adapter.setBattery(Integer.parseInt(args[1])); }
            else if (args[0].equals("rm_charger") ) { adapter.removeCharger();                       }
            else if (args[0].equals("rm_battery") ) { adapter.removeBattery();                       }
            else if (args[0].equals("use")        ) { adapter.use(Integer.parseInt(args[1]));        }
            else                                    { write("fail: comando inválido");         } 

        }
    }
    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static void    write(String value)  { System.out.println(value); }
}
