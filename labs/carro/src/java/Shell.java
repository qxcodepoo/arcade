import java.util.*;

enum DriveResult {
    OK,
    NO_PASSENGERS,
    INCOMPLETE,
    NO_GAS,
}

class Car{
    public int pass; // Passageiros
    public int passMax; // limite de Passageiros
    public int gas; // tanque
    public int gasMax; // limite do tanque
    public int km; // quantidade de quilometragem

    public Car() {
        this.pass = 0; // Passageiros
        this.passMax = 2; // limite de Passageiros
        this.gas = 0; // tanque
        this.gasMax = 100; // limite do tanque
        this.km = 0; // quantidade de quilometragem
    }

    public boolean enter() {
        if (pass < passMax) {
            pass += 1;
            return true;
        }
        return false;
    }

    public boolean leave() {
        if (pass > 0) {
            pass-=1;
            return true;
        }
        return false;
    }

    public void fuel(int gas) {
        this.gas += gas;
        if(this.gas > gasMax)
        this.gas = gasMax;
    }
    
    public DriveResult drive (int km) {
        if(this.pass == 0) {
            return DriveResult.NO_PASSENGERS;
        } 
        if(this.gas == 0) {
            return DriveResult.NO_GAS;
        }
        if(this.gas < km) {
            this.km += this.gas;
            this.gas = 0;
            return DriveResult.INCOMPLETE;
        } 
        this.gas -= km;
        this.km += km;
        return DriveResult.OK;
    }

    public String toString() {
        return "pass: " + pass + ", gas: " + gas + ", km: " + km;
    }
};
// @KEEP

public class Shell {
    private static final String CAR_FULL_MSG = "fail: limite de pessoas atingido";
    private static final String CAR_EMPTY_MSG = "fail: nao ha ninguem no carro";
    private static final String NO_GAS_MSG = "fail: tanque vazio";
    private static final String INCOMPLETE_TRIP_MSG = "fail: viagem incompleta";
    private static final String INVALID_COMMAND_MSG = "fail: comando invalido";
    
    public static void main(String[] a) {
        Car car = new Car();
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                System.out.println(car);
            } 
            else if (cmd.equals("enter")) {
                if (!car.enter())
                    System.out.println(CAR_FULL_MSG);
            } 
            else if (cmd.equals("leave")) {
                if (!car.leave())
                    System.out.println(CAR_EMPTY_MSG);
            } 
            else if (cmd.equals("fuel")) {
                int increment = Integer.parseInt(par[1]);
                car.fuel(increment);
            } 
            else if (cmd.equals("drive")) {
                int distance = Integer.parseInt(par[1]);
                switch (car.drive(distance)) {
                    case NO_PASSENGERS:
                        System.out.println(CAR_EMPTY_MSG);
                        break;
                    case NO_GAS:
                        System.out.println(NO_GAS_MSG);
                        break;
                    case INCOMPLETE:
                        System.out.println(INCOMPLETE_TRIP_MSG);
                        break;
                    case OK:
                        break;
                }
            }  
            else {
                System.out.println(INVALID_COMMAND_MSG);
            }
        }   
    }
    private static Scanner scanner = new Scanner(System.in);
}
