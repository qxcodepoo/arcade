import java.util.LinkedList;
import java.util.Scanner;
import java.util.stream.Collectors;



class Kid {
    private int age;
    private String name;

    public Kid(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public int getAge() {
        return age;
    }
    public String getName() {
        return name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String toString() {
        return name + ":" + age;
    }
}

class Trampoline{
    private LinkedList<Kid> waiting;
    private LinkedList<Kid> playing;
    
    public Trampoline() {
    }

    private Kid removeFromList(String name, LinkedList<Kid> list) {
    }

    public void arrive(Kid kid) {
    }

    public void enter() {
    }

    public void leave() {
    }

    public Kid remoteKid(String name) {
    }
    public String toString() {
        return   "[" + waiting.stream().map(Kid::toString).collect(Collectors.joining(", ")) + "]" + " => "
               + "[" + playing.stream().map(Kid::toString).collect(Collectors.joining(", ")) + "]";
    }
}


class Solver {
    public static void main(String[] _args) {
        Trampoline tr = new Trampoline();
        while(true) {
            var line = input();
            var args = line.split(" ");
            write("$"+ line);
            if(args[0].equals("end")) {
                break;
            } else if(args[0].equals("arrive")) { // name age
                tr.arrive(new Kid(args[1],(int) number(args[2]))) ;
            } else if(args[0].equals("enter")) {
                tr.enter();
            } else if(args[0].equals("leave")) {
                tr.leave();
            } else if(args[0].equals("remove")) {//name
                tr.remoteKid(args[1]);
            } else if(args[0].equals("show")) {
                write(tr.toString());
            } else {
                write("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}

