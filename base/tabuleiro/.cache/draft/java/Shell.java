import java.util.*;


class Adapter {
    // private Board board;
    public Adapter() {
        // this.board = new Board(0, 0);
    }

    public void init(int nPlayers, int size) {
        // this.board = new Board(nPlayers, size);
    }

    public void addTrap(int pos) {
        // this.board.addTrap(pos);
    }

    public void rollDice(int value) {
        // this.board.rollDice(value);
    }

    public void show() {
        // System.out.println(this.board.toString());
    }
}

public class Shell {
    public static void main(String[] args) {
        Adapter adp = new Adapter();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("$");
            String line = scanner.nextLine();
            String[] argsLine = line.split(" ");
            System.out.println(line);

            if (argsLine[0].equals("end")) {
                break;
            } else if (argsLine[0].equals("init")) {
                adp.init(Integer.parseInt(argsLine[1]), Integer.parseInt(argsLine[2]));
            } else if (argsLine[0].equals("addTrap")) {
                adp.addTrap(Integer.parseInt(argsLine[1]));
            } else if (argsLine[0].equals("roll")) {
                adp.rollDice(Integer.parseInt(argsLine[1]));
            } else if (argsLine[0].equals("show")) {
                adp.show();
            } else {
                System.out.println("comando inválido");
            }
        }
        scanner.close();
    }
}
