import java.util.Scanner;
public class Shell{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while(true){
            String line = scanner.nextLine();
            String[] ui = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else{
                System.out.println("fail: comando invalido");
            }
        }
    }
}