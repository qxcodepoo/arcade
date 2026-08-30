import java.util.*;

// @DROP
enum Label {
    GIVE("give"), TAKE("take"), PLUS("plus");

    private final String text;

    Label(String text) {
        this.text = text;
    }

    @Override
    public String toString() {
        return text;
    }
}

class Operation {
    private int id;
    private String name;
    private Label label;
    private int value;

    public Operation(int id, String name, Label label, int value) {
        this.id = id;
        this.name = name;
        this.label = label;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public Label getLabel() {
        return label;
    }

    public int getValue() {
        return value;
    }

    public String str() {
        return String.format("id:%d %s:%s %d", id, label, name, value);
    }
}

class Client {
    private String name;
    private int limite;
    private List<Operation> operations = new ArrayList<>();

    public Client(String name, int limite) {
        this.name = name;
        this.limite = limite;
    }

    public String getName() {
        return name;
    }

    public int getLimite() {
        return limite;
    }

    public int getBalance() {
        return operations.stream()
            .mapToInt(op -> op.getLabel() == Label.TAKE ? -op.getValue() : op.getValue())
            .sum();
    }

    public void addOperation(Operation op) {
        operations.add(op);
    }

    public List<Operation> getOperations() {
        return operations;
    }

    public String str() {
        return String.format("%s %d/%d", name, getBalance(), limite);
    }
}

class Agiota {
    private List<Client> aliveList = new ArrayList<>();
    private List<Client> deathList = new ArrayList<>();
    private List<Operation> aliveOper = new ArrayList<>();
    private List<Operation> deathOper = new ArrayList<>();
    private int nextOpId = 0;

    public Optional<Client> findClient(String name) {
        return aliveList.stream().filter(cli -> cli.getName().equals(name)).findFirst();
    }

    private void pushOperation(Client cli, Label label, int value) {
        Operation op = new Operation(nextOpId++, cli.getName(), label, value);
        aliveOper.add(op);
        cli.addOperation(op);
    }

    public void addClient(String name, int limite) {
        if (findClient(name).isPresent()) {
            System.out.println("fail: cliente ja existe");
            return;
        }
        aliveList.add(new Client(name, limite));
        aliveList.sort(Comparator.comparing(Client::getName));
    }

    public void give(String name, int value) {
        Client cli = findClient(name).orElse(null);
        if (cli == null) {
            System.out.println("fail: cliente nao existe");
            return;
        }
        if (cli.getBalance() + value > cli.getLimite()) {
            System.out.println("fail: limite excedido");
            return;
        }
        pushOperation(cli, Label.GIVE, value);
    }

    public void take(String name, int value) {
        Client cli = findClient(name).orElse(null);
        if (cli == null) {
            System.out.println("fail: cliente nao existe");
            return;
        }
        pushOperation(cli, Label.TAKE, value);
    }

    public void plus() {
        List<String> toDie = new ArrayList<>();
        for (Client cli : aliveList) {
            int increment = (int) Math.ceil(cli.getBalance() * 0.1);
            pushOperation(cli, Label.PLUS, increment);
            if (cli.getBalance() > cli.getLimite()) {
                toDie.add(cli.getName());
            }
        }
        toDie.forEach(this::kill);
    }

    public void kill(String name) {
        Optional<Client> cliOpt = findClient(name);
        if (cliOpt.isEmpty()) {
            System.out.println("fail: cliente nao existe");
            return;
        }
        Client cli = cliOpt.get();
        deathList.add(cli);
        aliveList.remove(cli);

        List<Operation> remaining = new ArrayList<>();
        for (Operation op : aliveOper) {
            if (op.getName().equals(name)) {
                deathOper.add(op);
            } else {
                remaining.add(op);
            }
        }
        aliveOper = remaining;
    }

    public String str() {
        StringBuilder sb = new StringBuilder();
        aliveList.forEach(cli -> sb.append(":) ").append(cli.str()).append("\n"));
        aliveOper.forEach(op -> sb.append("+ ").append(op.str()).append("\n"));
        deathList.forEach(cli -> sb.append(":( ").append(cli.str()).append("\n"));
        deathOper.forEach(op -> sb.append("- ").append(op.str()).append("\n"));
        return sb.toString().trim();
    }
}

// @KEEP
public class Shell {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Agiota agiota = new Agiota();

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            String[] parts = line.split(" ");
            String cmd = parts[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // @DROP
                System.out.println(agiota.str());
            }
            else if (cmd.equals("addCli")) {
                // @COM
                String name = parts[1];
                int limite = Integer.parseInt(parts[2]);
                // @DROP
                agiota.addClient(name, limite);
            }
            else if (cmd.equals("showCli")) {
                // @COM
                String name = parts[1];
                // @DROP
                Client cli = agiota.findClient(name).orElse(null);
                if (cli != null) {
                    System.out.println(cli.str());
                    cli.getOperations().forEach(op -> System.out.println(op.str()));
                }
            }
            else if (cmd.equals("kill")) {
                // @COM
                String name = parts[1];
                // @DROP
                agiota.kill(name);
            }
            else if (cmd.equals("give")) {
                // @COM
                String name = parts[1];
                int value = Integer.parseInt(parts[2]);
                // @DROP
                agiota.give(name, value);
            }
            else if (cmd.equals("take")) {
                // @COM
                String name = parts[1];
                int value = Integer.parseInt(parts[2]);
                // @DROP
                agiota.take(name, value);
            }
            else if (cmd.equals("plus")) {
                // @DROP
                agiota.plus();
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
