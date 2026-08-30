import java.util.*;

// @DROP
class Player {
    private int label;  // índice do jogador
    private int pos;    // posição no tabuleiro
    private boolean free;

    public Player(int label) {
        this.label = label;
        this.free = true;
        this.pos = 0;
    }

    public int getLabel() {
        return this.label;
    }

    public int getPos() {
        return this.pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public void setFree(boolean free) {
        this.free = free;
    }

    public boolean isFree() {
        return this.free;
    }

    @Override
    public String toString() {
        return "Player " + this.label + " at " + this.pos + " is " + (this.free ? "free" : "trapped");
    }
}// @COM

class Board {
    private int[] trapList;   // posições das armadilhas
    private boolean running;  // se o jogo está em andamento
    private int size;         // tamanho do tabuleiro
    private List<Player> players; // lista de jogadores

    public Board(int nPlayers, int size) {
        this.size = size + 1;
        this.trapList = new int[0];
        this.running = true;
        this.players = new ArrayList<>();
        for (int i = 1; i <= nPlayers; i++) {
            this.players.add(new Player(i));
        }
    }

    public void addTrap(int pos) {
        this.trapList = Arrays.copyOf(this.trapList, this.trapList.length + 1);
        this.trapList[this.trapList.length - 1] = pos;
    }

    public void rollDice(int value) {
        if (!this.running) {
            System.out.println("game is over");
            return;
        }

        int finish = this.size - 1;
        Player player = this.players.remove(0);

        if (!player.isFree()) {
            if (value % 2 == 0) {
                player.setFree(true);
                System.out.println("player" + player.getLabel() + " se libertou");
            }
            else {
                System.out.println("player" + player.getLabel() + " continua preso");
            }
        } else if (player.getPos() + value >= finish) {
            System.out.println("player" + player.getLabel() + " ganhou");
            player.setPos(finish);
            this.running = false;
        } else {
            player.setPos(player.getPos() + value);
            System.out.println("player" + player.getLabel() + " andou para " + player.getPos());
            for (int trap : this.trapList) {
                if (trap == player.getPos()) {
                    player.setFree(false);
                    System.out.println("player" + player.getLabel() + " caiu em uma armadilha");
                    break;
                }
            }
        }
        this.players.add(player);
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (Player p : this.players) {
            String[] line = new String[this.size];
            Arrays.fill(line, ".");
            line[p.getPos()] = String.valueOf(p.getLabel());
            str.append("player").append(p.getLabel()).append(": ").append(String.join("", line)).append("\n");
        }

        String[] traps = new String[this.size];
        Arrays.fill(traps, ".");
        for (int t : this.trapList) {
            traps[t] = "x";
        }
        str.append("traps__: ").append(String.join("", traps));
        return str.toString();
    }
}
// @KEEP

public class Shell {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        // @DROP
        Board adp = new Board(2, 10);
        // @KEEP

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];
            

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // @COM
                var nPlayers = Integer.parseInt(par[1]);
                var size = Integer.parseInt(par[2]);
                // @DROP
                adp = new Board(nPlayers, size);
            }
            else if (cmd.equals("addTrap")) {
                // @COM
                var pos = Integer.parseInt(par[1]);
                // @DROP
                adp.addTrap(pos);
            }
            else if (cmd.equals("roll")) {
                // @COM
                var value = Integer.parseInt(par[1]);
                // @DROP
                adp.rollDice(value);
            }
            else if (cmd.equals("show")) {
                // @DROP
                System.out.println(adp);
            }
            else {
                System.out.println("invalid command");
            }
        }
        scanner.close();
    }
}
