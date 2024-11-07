import java.util.LinkedList;
import java.util.stream.Collectors;

public class Trampoline{
    private LinkedList<Kid> waiting;
    private LinkedList<Kid> playing;
    
    public Trampoline() {
        waiting = new LinkedList<>();
        playing = new LinkedList<>();
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