import java.util.Scanner;

class Shell {
    public static void main(String[] _args) {
        Trampoline tr = new Trampoline();
        while(true) {
            System.out.print("$");
            var line = input();
            var args = line.split(" ");
            write(line);
            if(args[0].equals("end")) {
                break;
            } else if(args[0].equals("arrive")) { // name age
                tr.arrive(new Kid(args[1],(int) number(args[2]))) ;
            } else if(args[0].equals("enter")) {
                tr.enter();
            } else if(args[0].equals("leave")) {
                tr.leave();
            } else if(args[0].equals("remove")) {//name
                tr.remoteKid(args[1]);
            } else if(args[0].equals("show")) {
                write(tr.toString());
            } else {
                write("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}
