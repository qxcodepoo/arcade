import java.util.LinkedList;
import java.util.Scanner;


class Kid { //todo
    private int age;
    private String name;

    public Kid(String name, int age) { //todo
    }
    public int getAge() { //todo
    }
    public String getName() { //todo
    }
    public void setAge(int age) { //todo
    }
    public void setName(String name) { //todo
    }
    public String toString() { //todo
    }
}

class Trampoline{
    private LinkedList<Kid> waiting;
    private LinkedList<Kid> playing;
    
    public Trampoline() { //todo
    }
    //procura nas lista passada por parametro a criança
    //utilizando o nome
    //se encontrar, remove a criança da lista e retorna
    //retorna null se não encontrar
    private Kid remove_kid(String name, LinkedList<Kid> list) { //todo
    }
    //insere na lista de espera
    public void arrive(Kid kid) { //todo
    }
    //se existir alguém na lista de espera
    //remove o que estiver na frente da lista
    //e insere na no fim da lista de playing
    public void enter() { //todo
    }
    //se existir alguém em playing, remove o primeiro da lista
    //e insere no final da lista de espera
    public void leave() { //todo
    }
    //procura a criança no parquinho e remove
    //utilize a função privada remove_kid passando
    //as listas waiting e playing uma por vez
    //para procurar e remover a criança
    public Kid remove(String name) { //todo
    }
    public String toString() {
        String saida = "=> ";
        for(Kid kid : waiting)
            saida += kid + " ";
        saida += "=> [ ";
        for(Kid kid : playing)
            saida += kid + " ";
        return saida + "]";
    }
}


class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Trampoline tramp = new Trampoline();
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$"+ line);
            String[] ui = line.split(" ");
            if(ui[0].equals("end")) {
                break;
            } else if(ui[0].equals("arrive")) { // name age
                tramp.arrive(new Kid(ui[1], Integer.parseInt(ui[2]))) ;
            } else if(ui[0].equals("enter")) {
                tramp.enter();
            } else if(ui[0].equals("leave")) {
                tramp.leave();
            } else if(ui[0].equals("remove")) {//name
                tramp.remove(ui[1]);
            } else if(ui[0].equals("show")) {
                System.out.println(tramp);
            } else {
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}

