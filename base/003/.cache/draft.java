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
        sh.chain.put("show",   () -> System.out.println(motoca));
        sh.chain.put("init",   () -> motoca = new Motorcycle(getInt(1)));
        sh.chain.put("buy",    () ->              motoca.buy(getInt(1)));
        sh.chain.put("drive",  () ->            motoca.drive(getInt(1)));
        sh.chain.put("enter",  () -> motoca.enter(new Person(getStr(1), getInt(2))));
        sh.chain.put("honk",   () ->            motoca.honk());
        sh.chain.put("leave",  () ->  {
            Person person = motoca.leave();
            if(person != null) {
                System.out.println(person.toString());
            }
        });
    
        sh.execute();
    }

    static int getInt(int index) {
        return Integer.parseInt(sh.param.get(index));
    }
    static String getStr(int index) {
        return sh.param.get(index);
    }
}

class Shell {    
    public Scanner scanner = new Scanner(System.in);
    public HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String> param = new ArrayList<>();
    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }
    public void execute() {
        while(true) {
            param.clear();
            String line = scanner.nextLine();
            Collections.addAll(param, line.split(" "));
            System.out.println("$" + line);
            if(param.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(param.get(0))) {
                chain.get(param.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}

