import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

// @DROP
enum Label {
    WITHDRAW("withdraw"), //saque
    DEPOSIT("deposit"),   //deposito
    FEE("fee"),           //tarifa
    REVERSE("reverse"),   //extorno de tarifa
    OPENING("opening"),   //abertura da conta
    ERROR("error");

    private String name;

    private Label(String name) {
        this.name = name;
    }
    
    String getName() {
        return this.name;
    }
    public String toString() {
        return this.name;
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
        this.index = index;
        this.label = label;
        this.value = value;
        this.balance = balance;
    }
    
    public static String pad(String string, int length) {
        return String.format("%1$"+length+ "s", string);
    }
    public String toString() {
        return pad("" + index, 2) + ":" + pad("" + label, 9) + ":" + pad("" + value, 5) + ":" + pad("" + balance, 5);
    }
    int getIndex() {
        return this.index;
    }
    Label getLabel() {
        return this.label;
    }
    int getValue() {
        return this.value;
    }
    int getBalance() {
        return this.balance;
    }
};

class BalanceManager {
    //O id da próxima operação dessa conta
    private int nextId;
    //A lista de operações realizadas
    private List<Operation> extract;
    private int balance;

    public BalanceManager() {
        this.extract = new ArrayList<Operation>();
        this.balance = 0;
    }
    
    public void addOperation(Label label, int value) {
        balance += value;
        extract.add(new Operation(nextId, label, value, balance));
        nextId += 1;
    }

    public Operation getOperation(int index) {
        if (index < 0 || index >= extract.size()) {
            return new Operation(0, Label.ERROR, 0, 0);
        }
        return extract.get(index);
    }

    int getBalance() {
        return balance;
    }

    public List<Operation> getExtract(int qtdOp) {
        int inicio = 0;
        if (qtdOp != 0) {
            inicio = extract.size() - qtdOp;
            if (inicio < 0) {
                inicio = 0;
            }
        }
        return extract.subList(inicio, extract.size());
    }

    public String toString() {
        return "" + this.balance;
    }
}

class Account {
    //O número da conta
    private int id;
    private BalanceManager balanceManager;

    public Account(int id) {
        this.id = id;
        this.balanceManager = new BalanceManager();
        this.balanceManager.addOperation(Label.OPENING, 0);
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
        if(value < 0){
            System.out.println("fail: invalid value");
            return false;
        }
        if(value > this.balanceManager.getBalance()) {
            System.out.println("fail: insufficient balance");
            return false;
        }
        balanceManager.addOperation(Label.WITHDRAW, -value);
        return true;
    }

    public void fee(int value) {
        balanceManager.addOperation(Label.FEE, -value);
    }
    
    public void reverse(int index) {
        var op = this.balanceManager.getOperation(index);
        if(op.getLabel() == Label.ERROR) {
            System.out.println("fail: index " + index + " invalid");
            return;
        }
        if(op.getLabel() != Label.FEE) {
            System.out.println("fail: index " + index + " is not a fee");
            return;
        }
        balanceManager.addOperation(Label.REVERSE, -op.getValue());
        return;
    }

    public String toString() {
        return "account:" + this.id + " balance:" + this.balanceManager.getBalance();
    }

    BalanceManager getBalanceManager() {
        return this.balanceManager;
    }
}

// @KEEP

public class Shell{
    public static void main(String[] _args) {
        Account conta = new Account(0); // @DROP
        while (true) {
            var line = scanner.nextLine();
            var args = line.split(" ");
            var cmd = args[0];
            System.out.println("$" + line);

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("show")) {
                // @DROP
                System.out.println(conta);
            } else if (cmd.equals("init")) {
                // @COM
                var id = Integer.parseInt(args[1]);
                // @DROP
                conta = new Account(id);
            } else if (cmd.equals("withdraw")) {
                // @COM
                var value = Integer.parseInt(args[1]);
                // @DROP
                conta.withdraw(value);
            } else if (cmd.equals("fee")) {
                // @COM
                var value = Integer.parseInt(args[1]);
                // @DROP
                conta.fee(value);
            } else if (cmd.equals("deposit")) {
                // @COM
                var value = Integer.parseInt(args[1]);
                // @DROP
                conta.deposit(Label.DEPOSIT, value);
            } else if (cmd.equals("reverse")) {
                // @COM
                for (int i = 1; i < args.length; i++) {
                    var index = Integer.parseInt(args[i]);
                    // @DROP
                    conta.reverse(index);
                }
            } else if (cmd.equals("extract")) {
                // @COM
                var qtdOp = Integer.parseInt(args[1]);
                // @DROP
                var extract = conta.getBalanceManager().getExtract(qtdOp);
                System.out.println(extract.stream().map(Operation::toString).collect(Collectors.joining("\n")));
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
