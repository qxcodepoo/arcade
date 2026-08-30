import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

// @DROP
class Client {
    private String id;
    private String phone;
    public Client(String id, String phone) {
        this.id = id;
        this.phone = phone;
    }

    @Override
    public String toString() {
        return id + ":" + phone;
    }

    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPhone() {
        return this.phone;
    }

    public void setPhone(String fone) {
        this.phone = fone;
    }
}


class Theater{
    private List<Client> seats;

    public Theater(int capacity) {
        seats = new ArrayList<Client>();
        for(int i = 0; i < capacity; i++)
            seats.add(null);
    }

    public List<Client> getSeats() {
        return this.seats;
    }
    
    public boolean reserve(String id, String phone, int index) {
        if((index >= this.seats.size()) ||(index < 0)) {
            System.out.println("fail: cadeira nao existe");
            return false;
        }
        if(this.seats.get(index) != null) {
            System.out.println("fail: cadeira ja esta ocupada");
            return false;
        }
        for(Client cliente : this.seats) {
            if ((cliente != null) && (cliente.getId().equals(id))) {
                System.out.println("fail: cliente ja esta no cinema");
                return false;
            }
        }

        this.seats.set(index, new Client(id, phone));
        return true;
    }

    public void cancel(String id) {
        for(int i = 0; i < this.seats.size(); i += 1) {
            Client cliente = this.seats.get(i);
            if((cliente != null) && (cliente.getId().equals(id))) {
                this.seats.set(i, null);
                return;
            }
        }
        System.out.println("fail: cliente nao esta no cinema");
    }

    @Override
    public String toString() {
        return "[" + this.seats.stream().map(c -> (c == null) ? "-" : c.toString()).collect(Collectors.joining(" ")) + "]";
    }
}

// @KEEP

public class Shell {
    public static void main(String[] _args) {
        // @DROP
        Theater adp = new Theater(0);
        // @KEEP
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var args = line.split(" ");
            var cmd = args[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(adp);
            }
            else if (cmd.equals("init")) {
                // @COM
                var seats = Integer.parseInt(args[1]);
                // @DROP
                adp = new Theater(seats);
            }
            else if (cmd.equals("reserve")) {
                // @COM
                var id = args[1];
                var phone = args[2];
                var index = Integer.parseInt(args[3]);
                // @DROP
                adp.reserve(id, phone, index);
            }
            else if (cmd.equals("cancel")) {
                // @COM
                var id = args[1];
                // @DROP
                adp.cancel(id);
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);

}
