import java.util.LinkedList;
import java.util.Scanner;

class Kid{
    private int age;
    private String name;

    public Kid(int age, String name){
        this.age = age;
        this.name = name;
    }
    public int getAge(){
        return age;
    }
    public String getName(){
        return name;
    }
    public String toString(){
        return name + ":" + age;
    }
}

class Trampoline{
    private LinkedList<Kid> waiting;
    private LinkedList<Kid> playing;
    
    private Kid remove_kid(String name, LinkedList<Kid> _list){
        for(int i = 0; i < _list.size(); i++)
            if(_list.get(i).getName().equals(name))
                return _list.remove(i);
        return null;
    }

    public Trampoline(){
        waiting = new LinkedList<>();
        playing = new LinkedList<>();
    }

    
    public void arrive(Kid kid){
        waiting.addFirst(kid);
    }

    public void in(){
        playing.addFirst(waiting.getLast());
        waiting.removeLast();
    }

    public void out(){
        waiting.addFirst(playing.getLast());
        playing.removeLast();
    }

    public Kid remove(String name){
        Kid kid = remove_kid(name, waiting);
        if(kid != null)
            return kid;
        kid = remove_kid(name, playing);
        if(kid != null)
            return kid;
        return null;
    }

    public String toString(){
        String saida = "=> ";
        for(Kid kid : waiting)
            saida += kid + " ";
        saida += "=> ";
        for(Kid kid : playing)
            saida += kid + " ";
        return saida;
    }



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Trampoline tramp = new Trampoline();
        while(true){
            String line = scanner.nextLine();
            String[] ui = line.split(" ");
            if(ui[0].equals("end"))
                break;
            else if(ui[0].equals("arrive")){ // age name
                tramp.arrive(new Kid(Integer.parseInt(ui[1]), ui[2]));
            }else if(ui[0].equals("in"))
                tramp.in();
            else if(ui[0].equals("out"))
                tramp.out();
            else if(ui[0].equals("remove")) //name
                tramp.remove(ui[1]);
            else if(ui[0].equals("show")) //name
                System.out.println(tramp);
            else
                System.out.println("fail: comando invalido");
        }

        scanner.close();
    }
}

/*
arrive 4 bia
arrive 1 miguel
arrive 6 luana
arrive 10 tadeu
in
in
remove tadeu
remove luana
remove bia
*/