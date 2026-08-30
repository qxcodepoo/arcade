import java.util.Scanner;

// @DROP
class Bateria {
    private int capacity;
    private int charge;

    public Bateria(int capacity) {
        this.capacity = capacity;
        this.charge = capacity;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getCharge() {
        return charge;
    }

    public void setCharge(int value) {
        if (value <= 0) {
            this.charge = 0;
        } else if (value >= this.capacity) {
            this.charge = this.capacity;
        } else {
            this.charge = value;
        }
    }

    @Override
    public String toString() {
        return charge + "/" + capacity;
    }
}

class Charger {
    private int power;

    public Charger(int power) {
        this.power = power;
    }

    public int getPower() {
        return power;
    }

    @Override
    public String toString() {
        return power + "W";
    }
}

class Notebook {
    private boolean inUse = false;
    private int usage = 0;
    private Bateria battery = null;
    private Charger charger = null;

    @Override
    public String toString() {
        StringBuilder status = new StringBuilder("Notebook: ");
        
        if (!inUse) {
            status.append("desligado");
        } else {
            status.append("ligado por ").append(usage).append(" min");
        }

        if (charger != null) {
            status.append(", Carregador ").append(charger);
        }

        if (battery != null) {
            status.append(", Bateria ").append(battery);
        }

        return status.toString();
    }

    public void turnOn() {
        if (charger != null || (battery != null && battery.getCharge() > 0)) {
            inUse = true;
        } else {
            System.out.println("fail: não foi possível ligar");
        }
    }

    public void turnOff() {
        inUse = false;
        usage = 0;
    }

    public void use(int minutes) {
        if (!inUse) {
            System.out.println("fail: desligado");
            return;
        }

        if (charger != null && battery == null) {
            usage += minutes;
            return;
        }

        if (charger == null && battery != null) {
            if (battery.getCharge() > minutes) {
                battery.setCharge(battery.getCharge() - minutes);
                usage += minutes;
            } else {
                battery.setCharge(0);
                inUse = false;
                System.out.println("fail: descarregou");
            }
            return;
        }

        if (charger != null && battery != null) {
            usage += minutes;
            battery.setCharge(battery.getCharge() + charger.getPower() * minutes);
        }
    }

    public void setBattery(Bateria newBattery) {
        battery = newBattery;
    }

    public Bateria removeBattery() {
        if (battery != null) {
            if (charger == null && inUse) {
                inUse = false;
            }

            Bateria removedBattery = battery;
            battery = null;
            return removedBattery;
        }
        return null;
    }

    public void setCharger(Charger newCharger) {
        if (charger != null) {
            System.out.println("fail: carregador já conectado");
        } else {
            charger = newCharger;
        }
    }

    public Charger removeCharger() {
        if (charger != null) {
            if ((battery == null || battery.getCharge() == 0) && inUse) {
                inUse = false;
            }
            Charger removedCharger = charger;
            charger = null;
            return removedCharger;
        }
        return null;
    }
}
// @KEEP

public class Shell {
    public static void main(String[] _args) {
        // @DROP
        var notebook = new Notebook();
        // @KEEP

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if(cmd.equals("end")) {
                break;
            }
            // @COM
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(notebook);
            }
            else if(cmd.equals("turn_on")) { 
                // @DROP
                notebook.turnOn();
            }
            else if(cmd.equals("turn_off")) { 
                // @DROP
                notebook.turnOff();
            }
            else if(cmd.equals("use")) { 
                var minutes = Integer.parseInt(par[1]);
                // @DROP
                notebook.use(minutes);
            }
            else if(cmd.equals("set_battery")) {
                // CRIE UM OBJETO BATERIA E ATRIBUA AO NOTEBOOK
                var capacity = Integer.parseInt(par[1]);
                // @DROP
                notebook.setBattery(new Bateria(capacity));
            }
            else if(cmd.equals("rm_battery")) {
                // REMOVA A BATERIA DO NOTEBOOK E IMPRIMA SE EXISTIR
                // @DROP
                var battery = notebook.removeBattery();
                if (battery != null) {
                    System.out.println("Removido " + battery);
                } else {
                    System.out.println("fail: Sem bateria");
                }
            }
            else if(cmd.equals("set_charger")) {
                // CRIE UM OBJETO CHARGER E ATRIBUA AO NOTEBOOK
                var power = Integer.parseInt(par[1]);
                // @DROP
                notebook.setCharger(new Charger(power));
            }
            else if(cmd.equals("rm_charger")) {
                // REMOVA O CARREGADOR DO NOTEBOOK E IMPRIMA SE EXISTIR
                // @DROP
                var charger = notebook.removeCharger();
                if (charger != null) {
                    System.out.println("Removido " + charger);
                } else {
                    System.out.println("fail: Sem carregador");
                }
            }
            // @KEEP
            else {
                System.out.println("fail: comando inválido");
            }

        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
