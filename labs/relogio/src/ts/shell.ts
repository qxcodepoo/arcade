const input = () => ""; // MODO_TESTE
export {};
// @DROP

class Time {
    private hour: number;
    private minute: number;
    private second: number;

    constructor(hour: number, minute: number, second: number) {
        this.hour = 0;
        this.minute = 0;
        this.second = 0;
        this.setHour(hour);
        this.setMinute(minute);
        this.setSecond(second);
    }

    setHour(hour: number): void {
        if (hour < 0 || hour > 23) {
            console.log("fail: hora invalida");
            return;
        }
        this.hour = hour;
        
    }
    setMinute(minute: number): void {
        if (minute >= 0 && minute <= 59) {
            this.minute = minute;
        } else {
            console.log("fail: minuto invalido");
        }
    }

    setSecond(second: number): void {
        if (second >= 0 && second <= 59) {
            this.second = second;
        } else {
            console.log("fail: segundo invalido");
        }
    }

    getHour(): number {
        return this.hour;
    }        

    getMinute(): number {
        return this.minute;
    }

    getSecond(): number {
        return this.second;
    }       

    nextSecond(): void {
        this.second++;
        if (this.second > 59) {
            this.second = 0;
            this.minute++;
            if (this.minute > 59) {
                this.minute = 0;
                this.hour++;
                if (this.hour > 23) {
                    this.hour = 0;
                }
            }
        }
    }

    toString() {
        let p2 = (n: number) => ("" + n).padStart(2, "0");
        return p2(this.hour) + ":" + p2(this.minute) + ":" + p2(this.second);
    }
}

// @KEEP
function main() {
    // CRIE SEU RELÓGIO AQUI
    // @DROP
    let time = new Time(0, 0, 0);
    // @KEEP
    while (true) {
        let line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            // MOSTRE SEU RELÓGIO AQUI
            // @DROP
            console.log(time.toString());
        } else if (cmd == "init") {
            // INICIE SEU RELÓGIO AQUI UTILIZANDO O CONSTRUTOR
            // @COM
            const hour = parseInt(args[1]);
            const minute = parseInt(args[2]);
            const second = parseInt(args[3]);
            // @DROP
            time = new Time(hour, minute, second);
        } else if (cmd == "set") {
            // AJUSTE SEU RELÓGIO AQUI CHAMANDO OS MÉTODOS setHour, setMinute e setSecond
            // @COM
            const hour = parseInt(args[1]);
            const minute = parseInt(args[2]);
            const second = parseInt(args[3]);
            // @DROP
            time.setHour(hour);
            time.setMinute(minute);
            time.setSecond(second);
        } else if (cmd == "next") {
            // AVANCE SEU RELÓGIO AQUI CHAMANDO O MÉTODO nextSecond
            // @DROP
            time.nextSecond();
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main()
