import java.util.*;

// @DROP
class Time {
    private int hour   = 0;
    private int minute = 0;
    private int second = 0;

    public Time(int hour, int minute, int second) {
        this.setHour(hour);
        this.setMinute(minute);
        this.setSecond(second);
    }

    public boolean setHour(int hour) {
        if (hour < 0 || hour > 23) {
            return false;
        }
        this.hour = hour;
        return true;
    }
    public boolean setMinute(int minute) {
        if (minute < 0 || minute > 59) {
            return false;
        }
        this.minute = minute;
        return true;
    }
    public boolean setSecond(int second) {
        if (second < 0 || second > 59) {
            return false;
        }
        this.second = second;
        return true;
    }
    public int getHour() {
        return hour;
    }
    public int getMinute() {
        return minute;
    }
    public int getSecond() {
        return second;
    }
    public void nextSecond() {
        second++;
        if (second > 59) {
            second = 0;
            minute++;
            if (minute > 59) {
                minute = 0;
                hour++;
                if (hour > 23) {
                    hour = 0;
                }
            }
        }
    }

    public String toString() {
        return String.format("%02d:%02d:%02d", hour, minute, second);
    }
}

// @KEEP

public class Shell {
    public static void main(String[] a) {
        // CRIE SEU RELÓGIO AQUI
        // @DROP
        Time time = new Time(0, 0, 0);
        // @KEEP
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // MOSTRE O RELÓGIO AQUI
                // @DROP
                System.out.println(time);
            }
            else if (cmd.equals("init")) {
                // INICIE O RELÓGIO AQUI utilizando o construtor
                // @COM
                int hour = Integer.parseInt(par[1]);
                int minute = Integer.parseInt(par[2]);
                int second = Integer.parseInt(par[3]);
                // @DROP
                Time newTime = new Time(hour, minute, second);
                if (newTime.getHour() != hour) {
                    System.out.println("fail: hora invalida");
                }
                if (newTime.getMinute() != minute) {
                    System.out.println("fail: minuto invalido");
                }
                if (newTime.getSecond() != second) {
                    System.out.println("fail: segundo invalido");
                }
                time = newTime;
                // @KEEP
            }
            else if (cmd.equals("set")) {
                // CHAME OS MÉTODOS SET AQUI
                // @COM
                int hour = Integer.parseInt(par[1]);
                int minute = Integer.parseInt(par[2]);
                int second = Integer.parseInt(par[3]);
                // @DROP
                if (!time.setHour(hour)) {
                    System.out.println("fail: hora invalida");
                }
                if (!time.setMinute(minute)) {
                    System.out.println("fail: minuto invalido");
                }
                if (!time.setSecond(second)) {
                    System.out.println("fail: segundo invalido");
                }
            }
            else if (cmd.equals("next")) {
                // CHAME O MÉTODO nextSecond AQUI
                // @DROP
                time.nextSecond();
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
