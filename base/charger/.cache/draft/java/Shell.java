import java.util.Scanner;


public class Shell {
    public static void main(String[] _args) {

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if(cmd.equals("end")) {
                break;
            }
            // else if (cmd.equals("show")) { 
            // }
            // else if(cmd.equals("turn_on")) { 
            // }
            // else if(cmd.equals("turn_off")) { 
            // }
            // else if(cmd.equals("use")) { 
            //     var minutes = Integer.parseInt(par[1]);
            // }
            // else if(cmd.equals("set_battery")) {
            //     // CRIE UM OBJETO BATERIA E ATRIBUA AO NOTEBOOK
            //     var capacity = Integer.parseInt(par[1]);
            // }
            // else if(cmd.equals("rm_battery")) {
            //     // REMOVA A BATERIA DO NOTEBOOK E IMPRIMA SE EXISTIR
            // }
            // else if(cmd.equals("set_charger")) {
            //     // CRIE UM OBJETO CHARGER E ATRIBUA AO NOTEBOOK
            //     var power = Integer.parseInt(par[1]);
            // }
            // else if(cmd.equals("rm_charger")) {
            //     // REMOVA O CARREGADOR DO NOTEBOOK E IMPRIMA SE EXISTIR
            // }
            else {
                System.out.println("fail: comando inválido");
            }

        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
