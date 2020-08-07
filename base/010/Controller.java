import java.util.ArrayList;
import java.util.Scanner;

class Cliente{
    public String id;
    public String fone;
    public Cliente(String id, String fone){
        this.id = id;
        this.fone = fone;
    }

    @Override
    public String toString() {
        return id + ":" + fone;
    }
}

class Sala{
    ArrayList<Cliente> cadeiras;

    public Sala(int capacidade){
        cadeiras = new ArrayList<Cliente>();
        for(int i = 0; i < capacidade; i++)
            cadeiras.add(null);
    }

    boolean reservar(String id, String fone, int ind){
        if((ind >= this.cadeiras.size()) ||(ind < 0)){
            System.out.println("fail: indice invalido");
            return false;
        }
        if(this.cadeiras.get(ind) != null){
            System.out.println("fail: cadeira ja esta ocupada");
            return false;
        }
        for(Cliente cliente : this.cadeiras) {
            if ((cliente != null) && (cliente.id.equals(id))) {
                System.out.println("fail: cliente ja esta no cinema");
                return false;
            }
        }

        this.cadeiras.set(ind, new Cliente(id, fone));
        return true;
    }

    void cancelar(String id){
        for(int i = 0; i < this.cadeiras.size(); i += 1){
            Cliente cliente = this.cadeiras.get(i);
            if((cliente != null) && (cliente.id.equals(id))){
                this.cadeiras.set(i, null);
                return;
            }
        }
        System.out.println("fail: cliente nao esta no cinema");
    }


    @Override
    public String toString() {
        String saida = "[ ";
        for (Cliente cliente : cadeiras){
            if(cliente == null)
                saida += "- ";
            else
                saida += cliente + " ";
        }
        saida += "]";
        return saida;
    }
}

public class Controller {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Sala sala = new Sala(0);

        while(true){
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String[] ui = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else if(ui[0].equals("init")){
                sala = new Sala(Integer.parseInt(ui[1]));
            }else if(ui[0].equals("show")){
                System.out.println(sala);
            }else if(ui[0].equals("reservar")){
                sala.reservar(ui[1], ui[2], Integer.parseInt(ui[3]));
            }else if(ui[0].equals("cancelar")){
                sala.cancelar(ui[1]);
            }else{
                System.out.println("fail: comando invalido");
            }
        }
    }
}
