import { Student } from "./student";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let stu = new Student();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if (args[0] === "show") { 
            stu.show();
        }
        else if (args[0] == "init") { 
            stu = new Student(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "set") { 
            stu.setHour(+args[1]);
            stu.setMinute(+args[2]);
            stu.setSecond(+args[3]);
        }
        else if (args[0] === "next") {
            stu.nextSecond();
        }
        else if (args[0] === "end")   {
            break;
        }
        else {
            write("fail: comando invalido");
        }
    }
}

main()