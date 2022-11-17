import { readFileSync } from "fs";
let lines = readFileSync(0).toString().split("\n");
let input = () => lines[0] == undefined ? "" : lines.shift()!;
let write = (text: any, end="\n") => process.stdout.write("" + text + end);

let a = input();
let b = input();
write((a + b), "");