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

    public void setEnergy(int value) {
        if (value <= 0) {
            this.alive = false;
            this.energy = 0;
            System.out.println("fail: pet morreu de fraqueza");
            return;
        }
        if (value > this.energyMax) {
            this.energy = this.energyMax;
            return;
        }
        this.energy = value;
    }

    public void setClean(int value) {
        if (value <= 0) {
            this.alive = false;
            this.clean = 0;
            System.out.println("fail: pet morreu de sujeira");
            return;
        }
        if (value > this.cleanMax) {
            this.clean = this.cleanMax;
            return;
        }
        this.clean = value;
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

    private boolean testAlive() {
        if (!this.pet.isAlive()) {
            System.out.println("fail: pet esta morto");
            return false;
        }
        return true;
    }

    public void play() {
        if (!this.testAlive())
            return;
        this.pet.setEnergy(this.pet.getEnergy() - 2);
        this.pet.setClean(this.pet.getClean() - 3);
        this.pet.setAge(this.pet.getAge() + 1);
    }

    public void shower() {
        if (!this.testAlive())
            return;
        this.pet.setEnergy(this.pet.getEnergy() - 3);
        this.pet.setClean(this.pet.getCleanMax());
        this.pet.setAge(this.pet.getAge() + 2);
    }

    public void sleep() {
        if (!this.testAlive())
            return;
        if (this.pet.getEnergyMax() - this.pet.getEnergy() < 5) {
            System.out.println("fail: nao esta com sono");
            return;
        }
        this.pet.setAge(this.pet.getAge() + (this.pet.getEnergyMax() - this.pet.getEnergy()));
        this.pet.setEnergy(this.pet.getEnergyMax());
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
                game.play();
            }
            else if (cmd.equals("shower")) { 
                // @DROP
                game.shower();
            }
            else if (cmd.equals("sleep")) { 
                // @DROP
                game.sleep();
            }
            // @KEEP
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
