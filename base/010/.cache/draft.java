import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
//!KEEP
class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Sala sala = new Sala(0);
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String[] ui = line.split(" ");
            if(ui[0].equals("end")) {
                break;
            } else if(ui[0].equals("init")) {
                sala = new Sala(Integer.parseInt(ui[1]));
            } else if(ui[0].equals("show")) {
                System.out.println(sala);
            } else if(ui[0].equals("reservar")) {
                sala.reservar(ui[1], ui[2], Integer.parseInt(ui[3]));
            } else if(ui[0].equals("cancelar")) {
                sala.cancelar(ui[1]);
            } else {
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}

