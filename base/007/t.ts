import { readFileSync } from "fs";
let _cin_ = readFileSync(0).toString().split(/\r?\n/);
let input = () => lines[0] == undefined ? "" : lines.shift()!;
let write = (text: any, end="\n") => process.stdout.write("" + text + end);

let a = input();
let b = input();
write((a + b), "");