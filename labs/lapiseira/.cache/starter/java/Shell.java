import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.ArrayList;
public class Shell {
    public static void main(String[] _args) {

        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) { 
            } 
            else if (cmd.equals("init")) { 
                // var thickness = Double.parseDouble(par[1]);
            } 
            else if (cmd.equals("insert")) { 
                // var thickness = Double.parseDouble(par[1]);
                // var hardness = par[2];
                // var size = Integer.parseInt(par[3]);
            } 
            else if (cmd.equals("remove")) { 
            } 
            else if (cmd.equals("write")) { 
            } 
            else if (cmd.equals("pull")) { 
            } 
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static void printInsertResult(InsertResult result) {
        if (result == InsertResult.WRONG_THICKNESS)
            System.out.println("fail: calibre incompatível");
    }

    private static void printPullResult(PullResult result) {
        if (result == PullResult.TIP_OCCUPIED)
            System.out.println("fail: ja existe grafite no bico");
        else if (result == PullResult.BARREL_EMPTY)
            System.out.println("fail: nao existe grafite no barril");
    }

    private static void printWriteResult(WriteResult result) {
        if (result == WriteResult.NO_LEAD)
            System.out.println("fail: nao existe grafite no bico");
        else if (result == WriteResult.INSUFFICIENT)
            System.out.println("fail: tamanho insuficiente");
        else if (result == WriteResult.INCOMPLETE)
            System.out.println("fail: folha incompleta");
    }

    static Scanner scanner = new Scanner(System.in);
}
