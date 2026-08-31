import java.util.*;

// @DROP
class Person {
    private String name;
    private int age;
    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public String toString(){
        return this.name + ":" + this.age;
    }
}

class Motorcycle {
    private Person person; //agregacao
    private int power;
    private int time;
    
    public Motorcycle(int power){
        this.power = power;
        this.time = 0;
    }

    public int getPower() {
        return power;
    }

    public int getTime() {
        return time;
    }

    public Person getPerson() {
        return person;
    }

    
    //Se estiver vazio, coloca a pessoa na moto e retorna true
    public boolean enter(Person person) {
        if(this.person == null){
            this.person = person;
            return true;
        }
        return false;
    }

    public Person leave() {
        if(this.person != null){
            Person person = this.person;
            this.person = null;
            return person; 
        }else{
            return null;
        }
    }
    //Comprar mais tempo
    public void buy(int time){
        this.time += time;
    }

    public String drive(int time){
        if(this.time == 0) {
            return "fail: buy time first";
        }
        if(this.person == null) {
            return "fail: empty motorcycle";
        }
        if(this.person.getAge() > 10) {
            return "fail: too old to drive";
        }
        if(this.time < time) {
            String error = "fail: time finished after " + this.time + " minutes";
            this.time = 0;
            return error;
        }
        this.time -= time;
        return null;
    }

    public String honk(){
        String saida = "";
        for(int i = 0; i < this.power; i++) {
            saida += "e";
        }
        return ("P" + saida + "m");
    }

    public String toString(){
        var value = this.person == null ? "empty" : this.person;
        return "power:" + this.power + ", time:" + this.time + ", person:(" + value + ")";
    }

}

// @KEEP
public class Shell{
    
    public static void main(String[] args) {
        // CRIE SUA MOTO AQUI
        Motorcycle adp = new Motorcycle(1); // @DROP

        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // @COM
            else if (cmd.equals("init")) {
                // CRIE SUA MOTO AQUI
                var power = Integer.parseInt(par[1]);
                // @DROP
                adp = new Motorcycle(power);
            }
            else if (cmd.equals("show")) {
                // MOSTRE SUA MOTO AQUI
                // @DROP
                System.out.println(adp);
            }
            else if (cmd.equals("enter")) {
                // CRIE UM OBJETO PESSOA AQUI
                // DEPOIS INSIRA NA MOTO
                var name = par[1];
                var age = Integer.parseInt(par[2]);
                // @DROP
                if (!adp.enter(new Person(name, age))) {
                    System.out.println("fail: busy motorcycle");
                }
            }
            else if (cmd.equals("leave")) {
                // RETIRE A PESSOA DA MOTO
                // MOSTRE A PESSOA RETIRADA AQUI
                // @DROP
                var person = adp.leave();
                if(person != null) {
                    System.out.println(person);
                } else {
                    System.out.println("fail: empty motorcycle");
                }
            }
            else if (cmd.equals("buy")) {
                // COMPRE TEMPO
                var time = Integer.parseInt(par[1]);
                // @DROP
                adp.buy(time);
            }
            else if (cmd.equals("drive")) {
                // DIRIJA A MOTO
                var time = Integer.parseInt(par[1]);
                // @DROP
                var error = adp.drive(time);
                if (error != null) {
                    System.out.println(error);
                }
            }
            else if (cmd.equals("honk")) {
                // BUZINE
                // @DROP
                System.out.println(adp.honk());
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
