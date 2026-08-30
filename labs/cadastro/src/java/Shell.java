import java.util.*;
import java.util.stream.Collectors;

// @DROP
//excessão lançada em quaisquer erros relacionados à conta
class AccountException extends RuntimeException {
    public AccountException(String message) {
        super(message);
    }
}


abstract class Account {
    protected int id;
    protected double balance;
    protected String clientId;
    protected String type; //CC or CP

    public Account(int id, String clientId) {
        this.id = id;
        this.clientId = clientId;
        this.balance = 0;
    }

    //abstract method
    public abstract void monthlyUpdate();
    //saque
    public void withdraw(double value) {
        if(balance >= value)
            balance -= value;
        else
            throw new AccountException("fail: saldo insuficiente");
    }
    //deposito
    public void deposit(double value) {
        balance += value;
    }
    //transferencia para outra conta
    public void transfer(Account other, double value) {
        this.withdraw(value);
        other.deposit(value);
    }

    public String toString() {
        return id + ":" + clientId + ":" + String.format("%.2f", balance) + ":" + type;
    }

    //GETS and SETS
    int getId() {
        return this.id;
    }

    double getBalance() {
        return this.balance;
    }

    String getClientId() {
        return this.clientId;
    }

    String getType() {
        return this.type;
    }
}

class CheckingAccount extends Account {
    //inicializa conta.type com "CC"
    public CheckingAccount(int id, String idClient) {
        super(id, idClient);
        this.type = "CC";
    }
    //retira 20 do saldo
    public void monthlyUpdate() {
        balance -= 20;
    }
}

class SavingsAccount extends Account {
    public SavingsAccount(int id, String idClient) {
        super(id, idClient);
        this.type = "CP";
    }
    //aumenta saldo em 1%
    public void monthlyUpdate() {
        balance *= 1.01;
    }
}

class Client {
    private String clientId;
    private List<Account> accounts;
    public Client(String clientId) {
        this.clientId = clientId;
        this.accounts = new ArrayList<>();
    }

    public void addAccount(Account account) {
        if(this.accounts.stream().findFirst().filter(acc -> acc.getId() == account.getId()).orElse(null) == null)
            this.accounts.add(account);
    }
    public java.lang.String toString() {
        return this.clientId + " [" + this.accounts.stream().map(ac -> "" + ac.getId()).collect(Collectors.joining(", ")) + "]";
    }
    //GETS and SETS
    String getClientId() {
        return this.clientId;
    }

    void setClientId(String clientId) {
        this.clientId = clientId;
    }

    List<Account> getAccounts() {
        return this.accounts;
    }

    void setAccounts(List<Account> accounts) {
        this.accounts = accounts;
    }
};

class BankAgency {
    private Map<String, Client> clients;
    private Map<Integer, Account> accounts;
    private int nextAccountId = 0;

    //obtém conta ou lança excessão
    private Account getAccount(int id) {
        Account account = accounts.get(id);
        if(account == null)
            throw new AccountException("fail: conta nao encontrada");
        return account;
    }

    public BankAgency() {
        this.clients = new TreeMap<>();
        this.accounts = new TreeMap<>();
    }

    //se o cliente não existir
    //cria o cliente
    //cria uma conta poupança e uma conta corrent para o cliente
    //adiciona essas contas no vetor de contas e no vetor do cliente
    //adiciona o cliente no mapa de clientes
    public void addClient(String clientId) {
        if(this.clients.get(clientId) == null) {
            Client client = new Client(clientId);
            Account cc = new CheckingAccount(nextAccountId++, clientId);
            Account cp = new SavingsAccount(nextAccountId++, clientId);
            this.accounts.put(cc.getId(), cc);
            this.accounts.put(cp.getId(), cp);

            client.addAccount(cc);
            client.addAccount(cp);
            clients.put(clientId, client);
        }
    }
    //obtem o cliente e invoca as ações
    public void withdraw(int idConta, double value) {
        getAccount(idConta).withdraw(value);
    }
    public void deposit(int idConta, double value) {
        getAccount(idConta).deposit(value);
    }
    public void transfer(int contaDe, int contaPara, double value) {
        getAccount(contaDe).transfer(getAccount(contaPara), value);
    }
    public void monthlyUpdate() {
        this.accounts.values().forEach(acc -> acc.monthlyUpdate());
    }

    public String toString() {
        return "- Clients\n" + this.clients.values().stream().map(cc -> "" + cc).collect(Collectors.joining("\n")) + "\n" +
              "- Accounts\n" + this.accounts.values().stream().map(cc -> "" + cc).collect(Collectors.joining("\n"));
    }
};

// @KEEP
public class Shell {
    public static void main(String[] s) {
        BankAgency agency = new BankAgency(); // @DROP
        while(true){
            try {
                var line = scanner.nextLine();
                var args = line.split(" ");
                var cmd = args[0];
                System.out.println("$" + line);

                if(cmd.equals("end")) {
                    break;
                }
                else if(cmd.equals("show")) {
                    // @DROP
                    System.out.println("" + agency);
                }
                else if(cmd.equals("addCli")) {
                    // @COM
                    var clientId = args[1];
                    // @DROP
                    agency.addClient(clientId);
                }
                else if(cmd.equals("saque")) {
                    // @COM
                    var accountId = Integer.parseInt(args[1]);
                    var value = Double.parseDouble(args[2]);
                    // @DROP
                    agency.withdraw(accountId, value);
                }
                else if(cmd.equals("deposito")) {
                    // @COM
                    var accountId = Integer.parseInt(args[1]);
                    var value = Double.parseDouble(args[2]);
                    // @DROP
                    agency.deposit(accountId, value);
                }
                else if(cmd.equals("transf")) {
                    // @COM
                    var accountIdFrom = Integer.parseInt(args[1]);
                    var accountIdTo = Integer.parseInt(args[2]);
                    var value = Double.parseDouble(args[3]);
                    // @DROP
                    agency.transfer(accountIdFrom, accountIdTo, value);
                }
                else if(cmd.equals("update")) {
                    // @DROP  
                    agency.monthlyUpdate();
                }
                else {
                    System.out.println("fail: comando invalido");
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
