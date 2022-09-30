import java.util.*;

class Person { //todo
    private String name;
    private int age;
    public Person(String name, int age){
    }
    public String getName() { //todo
    }
    public int getAge() { //todo
    }
    public String toString(){
    }
}

class Motorcycle { //todo
    private Person person; //agregacao
    private int power;
    private int time;
    
    //Inicia o atributo power, time com zero e person com null
    public Motorcycle(int power){
    }
    public int getPower() { //todo
    }
    public int getTime() { //todo
    }
    public Person getPerson() { //todo
    }
    //Comprar mais tempo
    public void buy(int time){
    }
    
    //Se estiver vazio, coloca a pessoa na moto e retorna true
    public boolean enter(Person person) { //todo
    }
    public Person leave() { //todo
    }
    public void drive(int time){
    }
    //buzinar
    public void honk(){
    }
    
    public String toString(){
    }
}

class Solver{
    static Shell sh = new Shell();
    static Motorcycle motoca  = new Motorcycle(1);

    public static void main(String[] args) {    
        sh.addCmd("show",   () -> System.out.println(motoca));
        sh.addCmd("init",   () -> motoca = new Motorcycle(sh.getInt(1)));
        sh.addCmd("buy",    () ->              motoca.buy(sh.getInt(1)));
        sh.addCmd("drive",  () ->            motoca.drive(sh.getInt(1)));
        sh.addCmd("enter",  () -> motoca.enter(new Person(sh.getStr(1), sh.getInt(2))));
        sh.addCmd("honk",   () ->            motoca.honk());
        sh.addCmd("leave",  () ->  {
            Person person = motoca.leave();
            if(person != null) {
                System.out.println(person.toString());
            }
        });
    
        sh.evaluate();
    }
}
