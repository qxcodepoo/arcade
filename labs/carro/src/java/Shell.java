import java.util.*;

enum Result {
    OK,
    CAR_FULL,
    CAR_EMPTY,
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

    public Result enter() {
        if (pass < passMax) {
            pass += 1;
            return Result.OK;
        }
        return Result.CAR_FULL;
    }

    public Result leave() {
        if (pass > 0) {
            pass-=1;
            return Result.OK;
        }
        return Result.CAR_EMPTY;
    }

    public void fuel(int gas) {
        this.gas += gas;
        if(this.gas > gasMax)
        this.gas = gasMax;
    }
    
    public Result drive (int km) {
        if(this.pass == 0) {
            return Result.CAR_EMPTY;
        } 
        if(this.gas == 0) {
            return Result.NO_GAS;
        }
        if(this.gas < km) {
            this.km += this.gas;
            this.gas = 0;
            return Result.INCOMPLETE;
        } 
        this.gas -= km;
        this.km += km;
        return Result.OK;
    }

    public String toString() {
        return "pass: " + pass + ", gas: " + gas + ", km: " + km;
    }
};
// @KEEP

public class Shell {

    public static void printResult(Result result) {
        switch (result) {
            case CAR_FULL:
                System.out.println("fail: limite de pessoas atingido");
                break;
            case CAR_EMPTY:
                System.out.println("fail: nao ha ninguem no carro");
                break;
            case NO_GAS:
                System.out.println("fail: tanque vazio");
                break;
            case INCOMPLETE:
                System.out.println("fail: viagem incompleta");
                break;
            case OK:
                break;
            default:
                break;  
        }
    }
    
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
                // MOSTRE OS ATRIBUTOS DO CARRO
                // @DROP
                System.out.println(car);
            } 
            else if (cmd.equals("enter")) {
                printResult(car.enter());

            } 
            else if (cmd.equals("leave")) {
                printResult(car.leave());
            } 
            else if (cmd.equals("fuel")) {
                int increment = Integer.parseInt(par[1]);
                car.fuel(increment);
            } 
            else if (cmd.equals("drive")) {
                int distance = Integer.parseInt(par[1]);
                printResult(car.drive(distance));
            }  
            else {
                System.out.println("fail: comando invalido");
            }
        }   
    }
    private static Scanner scanner = new Scanner(System.in);
}
