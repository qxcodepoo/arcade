import java.util.*;

// @DROP

class Pet {
    private int energyMax;
    private int cleanMax;

    private int energy;
    private int clean;

    private int age;
    private boolean alive;

    public Pet(int energy, int clean) {
        this.energyMax = energy;
        this.cleanMax = clean;

        this.energy = energy;
        this.clean = clean;

        this.age = 0;
        this.alive = true;
    }

    public String setEnergy(int value) {
        if (value <= 0) {
            this.alive = false;
            this.energy = 0;
            return "fail: pet morreu de fraqueza";
        }
        if (value > this.energyMax) {
            this.energy = this.energyMax;
            return null;
        }
        this.energy = value;
        return null;
    }

    public String setClean(int value) {
        if (value <= 0) {
            this.alive = false;
            this.clean = 0;
            return "fail: pet morreu de sujeira";
        }
        if (value > this.cleanMax) {
            this.clean = this.cleanMax;
            return null;
        }
        this.clean = value;
        return null;
    }

    public void setAge(int value) {
        this.age = value;
    }

    public String toString() {
        return "E:" + this.energy + "/" + this.energyMax +
               ", L:" + this.clean + "/" + this.cleanMax +
               ", I:" + this.age;
    }

    public int getClean() {
        return this.clean;
    }

    public int getEnergy() {
        return this.energy;
    }

    public int getCleanMax() {
        return this.cleanMax;
    }

    public int getEnergyMax() {
        return this.energyMax;
    }

    public int getAge() {
        return this.age;
    }

    public boolean isAlive() {
        return this.alive;
    }
}

class Game {
    private Pet pet;

    public Game(Pet pet) {
        this.pet = pet;
    }

    private String testAlive() {
        if (!this.pet.isAlive()) {
            return "fail: pet esta morto";
        }
        return null;
    }

    public String play() {
        var error = this.testAlive();
        if (error != null) return error;
        error = this.pet.setEnergy(this.pet.getEnergy() - 2);
        var cleanError = this.pet.setClean(this.pet.getClean() - 3);
        this.pet.setAge(this.pet.getAge() + 1);
        return error != null ? error : cleanError;
    }

    public String shower() {
        var error = this.testAlive();
        if (error != null) return error;
        error = this.pet.setEnergy(this.pet.getEnergy() - 3);
        this.pet.setClean(this.pet.getCleanMax());
        this.pet.setAge(this.pet.getAge() + 2);
        return error;
    }

    public String sleep() {
        var error = this.testAlive();
        if (error != null) return error;
        if (this.pet.getEnergyMax() - this.pet.getEnergy() < 5) {
            return "fail: nao esta com sono";
        }
        this.pet.setAge(this.pet.getAge() + (this.pet.getEnergyMax() - this.pet.getEnergy()));
        this.pet.setEnergy(this.pet.getEnergyMax());
        return null;
    }

    public String toString() {
        return this.pet.toString();
    }
}

// @KEEP
public class Shell {
    public static void main(String[] a) {
        // @DROP
        Game game = new Game(new Pet(0, 0));
        // @KEEP
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // @COM
            else if (cmd.equals("init")) {
                // CRIE UM NOVO JOGO COM UM NOVO PET
                var energy = Integer.parseInt(par[1]);
                var clean = Integer.parseInt(par[2]);
                // @DROP
                game = new Game(new Pet(energy, clean));
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(game);
            }
            else if (cmd.equals("play")) { 
                // @DROP
                var error = game.play();
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("shower")) { 
                // @DROP
                var error = game.shower();
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("sleep")) { 
                // @DROP
                var error = game.sleep();
                if (error != null) System.out.println(error);
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
