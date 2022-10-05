import java.util.*;

class Time {
    private int hour   = 0;
    private int minute = 0;
    private int second = 0;

    public Time(int hour, int minute, int second) {
        this.setHour(hour);
        this.setMinute(minute);
        this.setSecond(second);
    }

    public void setHour(int hour) {
        if (hour < 0 || hour > 23) {
            System.out.println("fail: hora invalida");
        } else {
            this.hour = hour;
        }
    }
    public void setMinute(int minute) {
        if (minute < 0 || minute > 59) {
            System.out.println("fail: minuto invalido");
        } else {
            this.minute = minute;
        }
    }
    public void setSecond(int second) {
        if (second < 0 || second > 59) {
            System.out.println("fail: segundo invalido");
        } else {
            this.second = second;
        }
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

class Solver {
    static Shell sh = new Shell();
    static Time time = new Time(0, 0, 0);
    public static void main(String[] args) {
        sh.chain.put("init", () -> time = new Time(getInt(1), getInt(2), getInt(3)));
        sh.chain.put("set", () -> {
            time.setHour(getInt(1));
            time.setMinute(getInt(2));
            time.setSecond(getInt(3));
        });
        sh.chain.put("show", () -> {
            System.out.println(time.toString());
        });
        sh.chain.put("next", () -> {
            time.nextSecond();
        });
        sh.execute();
    }

    static int getInt(int index) {
        return Integer.parseInt(sh.param.get(index));
    }
}

class Shell {    
    public Scanner scanner = new Scanner(System.in);
    public HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String> param = new ArrayList<>();
    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }
    public void execute() {
        while(true) {
            param.clear();
            String line = scanner.nextLine();
            Collections.addAll(param, line.split(" "));
            System.out.println("$" + line);
            if(param.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(param.get(0))) {
                chain.get(param.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
