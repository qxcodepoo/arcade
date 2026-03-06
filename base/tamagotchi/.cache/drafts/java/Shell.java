import java.util.*;

public class Shell {
    public static void main(String[] a) {
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // else if (cmd.equals("init")) {
            //     // CRIE UM NOVO JOGO COM UM NOVO PET
            //     var energy = Integer.parseInt(par[1]);
            //     var clean = Integer.parseInt(par[2]);
            // }
            // else if (cmd.equals("show")) { 
            // }
            // else if (cmd.equals("play")) { 
            // }
            // else if (cmd.equals("shower")) { 
            // }
            // else if (cmd.equals("sleep")) { 
            // }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
