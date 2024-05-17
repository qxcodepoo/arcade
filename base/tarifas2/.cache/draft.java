import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

enum Label {
    WITHDRAW("withdraw"), //saque
    DEPOSIT("deposit"),   //deposito
    FEE("fee"),           //tarifa
    REVERSE("reverse"),   //extorno de tarifa
    OPENING("opening"),   //abertura da conta
    ERROR("error");

    private String name;

    private Label(String name) {
    }
    
    String getName() {
    }
    public String toString() {
    }
}

class Operation {
    private int index;    
    private Label label;
    //O valor em negativo se for débito
    private int value;
    //O saldo residual
    private int balance;
    public Operation(int index, Label label, int value, int balance) {
    }
    
    public static String pad(String string, int length) {
    }
    public String toString() {
    }
    int getIndex() {
    }
    Label getLabel() {
    }
    int getValue() {
    }
    int getBalance() {
    }
};

class BalanceManager {
    //O id da próxima operação dessa conta
    private int nextId;
    //A lista de operações realizadas
    private List<Operation> extract;
    private int balance;

    public BalanceManager() {
    }
    
    public void addOperation(Label label, int value) {
    }

    public Operation getOperation(int index) {
    }

    int getBalance() {
    }

    public List<Operation> getExtract(int qtdOp) {
    }

    public String toString() {
    }
}

class Account {
    //O número da conta
    private int id;
    private BalanceManager balanceManager;

    public Account(int id) {
    }
    public boolean deposit(Label label, int value) {
        if(value < 0){
            System.out.println("fail: invalid value");
            return false;
        }
        balanceManager.addOperation(label, value);
        return true;
    }
    public boolean withdraw(int value) {
    }

    public void fee(int value) {
    }
    
    public void reverse(int index) {
    }

    public String toString() {
    }

    BalanceManager getBalanceManager() {
    }
}

class Solver{
    public static void main(String[] _args) {
        Account conta = new Account(0);
        while (true) {
            var line = input();
            var args = line.split(" ");
            write("$" + line);

            if (args[0].equals("end")) {
                break;
            } else if (args[0].equals("show")) {
                System.out.println(conta);
            } else if (args[0].equals("init")) {
                conta = new Account((int) number(args[1]));
            } else if (args[0].equals("withdraw")) {
                conta.withdraw((int) number(args[1]));
            } else if (args[0].equals("fee")) {
                conta.fee((int) number(args[1]));
            } else if (args[0].equals("deposit")) {
                conta.deposit(Label.DEPOSIT, (int) number(args[1]));
            } else if (args[0].equals("reverse")) {
                for (int i = 1; i < args.length; i++) {
                    conta.reverse((int) number(args[i]));
                }
            } else if (args[0].equals("extract")) {
                var extract = conta.getBalanceManager().getExtract((int) number(args[1]));
                for (var op : extract) {
                    System.out.println(op);
                }
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static int number(String str)   { return Integer.parseInt(str); }
}
