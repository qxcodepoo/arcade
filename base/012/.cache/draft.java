import java.util.*;
import java.util.stream.*;

class Pass {
    private String name;
    private int age;

    public Pass(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public boolean isPriority() {
        return age >= 65;
    }

    public String getName() {
        return this.name;
    }
    public String toString(){
        return this.name + ":" + this.age;
    }

}

class Topic { //todo
    private List<Pass> prioritySeats;
    private List<Pass> normalSeats;
    public Topic(int capacity, int qtdPriority) { //todo
    }
    //return the first free pos or -1
    private static int findFirstFreePos(List<Pass> list) { //todo
    }
    
    //search in list using name and return position or return -1
    private static int findByName(String name, List<Pass> list) { //todo
    }
    
    //use the findFirstFreePos to search a free position
    //if exists, insert the pass and return true
    //else return false
    private static boolean insertOnList(Pass pass, List<Pass> list) { //todo
    }
    //use the findByName method to locate pos in list, if found, remore the person
    //setting the pos location to null
    private static boolean removeFromList(String name, List<Pass> list) { //todo
    }

    //use findByName to test if the pass is already in the topic
    //use the insertOnList method to insert in the right list based in
    //the pass.isPriority result
    public boolean insert(Pass pass) { //todo
    }
    //use the removeFromList method to try to remove from both lists
    public boolean remove(String name) { //todo
    }
    public String toString() {
        return "[" + Stream.concat(
            this.prioritySeats.stream().map(p -> ("@" + ((p == null)?(""):("" + p)))), 
            this.normalSeats.stream().map(p -> ("=" + ((p == null)?(""):("" + p)))))
            .collect(Collectors.joining(" ")) + "]";
    }
}

class Solver{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Topic topic = new Topic(0, 0);
        while(true){
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            if(line.equals("end")) {
                break;
            } else if(ui[0].equals("init")) { //capacity qtdPriority
                topic = new Topic(Integer.parseInt(ui[1]), Integer.parseInt(ui[2]));
            } else if(ui[0].equals("show")) {
                System.out.println(topic);
            } else if(ui[0].equals("in")) {
                topic.insert(new Pass(ui[1], Integer.parseInt(ui[2])));
            } else if(ui[0].equals("out")) {//value value
                topic.remove(ui[1]);
            } else {
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}

