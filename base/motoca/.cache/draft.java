
//Falta no rascunho buzinhar, comprarTempo e dirigir

import java.util.*;

class Person {
    private String name;
    private int age;
    public Person(String name, int age){
    }
    public String getName() {
    }
    public int getAge() {
    }
    public String toString(){
    }
}

class Motorcycle {
    private Person person; //agregacao
    private int power;
    private int time;
    
    //Inicia o atributo power, time com zero e person com null
    public Motorcycle(int power){
    }
    public int getPower() {
    }
    public int getTime() {
    }
    public Person getPerson() {
    }

    
    //Se estiver vazio, coloca a pessoa na moto e retorna true
    public boolean enter(Person person) {
    }
    public Person leave() {
    }
    //Comprar mais tempo
    public void buy(int time){
    }
    public void drive(int time){
    }
    //buzinar
    public void honk(){
    }
    public String toString(){
        var value = this.person == null ? "empty" : this.person;
        return "power:" + this.power + ", time:" + this.time + ", person:(" + value + ")";
    }
}
class Solver{
    static Motorcycle motoca = new Motorcycle(1);

    public static void main(String[] args) {    
        while(true) {
            String line = input();
            args = line.split(" ");
            write('$' + line);

            if      (args[0].equals("show"))     { System.out.println(motoca);                         }
            else if (args[0].equals("init"))     { motoca = new Motorcycle(number(args[1]));           }  
            else if (args[0].equals("enter"))    { motoca.enter(new Person(args[1], number(args[2]))); }
            else if (args[0].equals("buy"))      { motoca.buy(number(args[1]));                        }
            else if (args[0].equals("drive"))    { motoca.drive(number(args[1]));                      }
            else if (args[0].equals("honk"))     { motoca.honk();                                      }
            else if (args[0].equals("end"))      { break;                                              }
            else if (args[0].equals("leave"))    {
                Person person = motoca.leave();
                if(person != null) {
                    System.out.println(person.toString());
                }
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static int number(String str)   { return Integer.parseInt(str); }
}
