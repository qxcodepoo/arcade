import java.util.Scanner;
import java.util.LinkedList;

// @DROP
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
        waiting = new LinkedList<>();
        playing = new LinkedList<>();
    }


    private Kid removeFromList(String name, LinkedList<Kid> list) {
        for(int i = 0; i < list.size(); i++)
            if(list.get(i).getName().equals(name))
                return list.remove(i);
        return null;
    }

    public void arrive(Kid kid) {
        waiting.addFirst(kid);
    }

    public void enter() {
        if (waiting.size() > 0) {
            playing.addFirst(waiting.getLast());
            waiting.removeLast();
        }
    }

    public void leave() {
        if (playing.size() > 0) {
            waiting.addFirst(playing.getLast());
            playing.removeLast();
        }
    }

    public Kid removeKid(String name) {
        Kid kid = removeFromList(name, waiting);
        if(kid != null)
            return kid;
        kid = removeFromList(name, playing);
        if(kid != null)
            return kid;
        return null;
    }

    public String toString() {
        return   "[" + waiting.stream().map(Kid::toString).collect(Collectors.joining(", ")) + "]" + " => "
               + "[" + playing.stream().map(Kid::toString).collect(Collectors.joining(", ")) + "]";
    }
}

// @KEEP
public class Shell {
    public static void main(String[] args) {
        // @DROP
        var adp = new Trampoline();
        // @KEEP
        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(adp);
            }
            else if (cmd.equals("arrive")) {
                // @COM
                var name = par[1];
                var age = Integer.parseInt(par[2]);
                // @DROP
                adp.arrive(new Kid(name, age));
            }
            else if (cmd.equals("enter")) {
                // @DROP
                adp.enter();
            }
            else if (cmd.equals("leave")) {
                // @DROP
                adp.leave();
            }
            else if (cmd.equals("remove")) {
                // @COM
                var name = par[1];
                // @DROP
                var kid = adp.removeKid(name);
                if (kid == null) {
                    System.out.println("fail: " + name+ " nao esta no pula-pula");
                }
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
