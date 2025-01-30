var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toCommonJS = (mod) => __copyProps(__defProp({}, "__esModule", { value: true }), mod);
var shell_exports = {};
module.exports = __toCommonJS(shell_exports);
function input() {
  let X = input;
  X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/);
  return X.L.shift();
}
class Bateria {
  capacity;
  charge;
  constructor(capacity) {
    this.capacity = capacity;
    this.charge = capacity;
  }
  getCapacity() {
    return this.capacity;
  }
  getCharge() {
    return this.charge;
  }
  setCharge(value) {
    if (value <= 0) {
      this.charge = 0;
    } else if (value >= this.capacity) {
      this.charge = this.capacity;
    } else {
      this.charge = value;
    }
  }
  toString() {
    return `${this.charge}/${this.capacity}`;
  }
}
class Charger {
  power;
  constructor(power) {
    this.power = power;
  }
  getPower() {
    return this.power;
  }
  toString() {
    return `${this.power}W`;
  }
}
class Notebook {
  inUse = false;
  usage = 0;
  battery = null;
  charger = null;
  toString() {
    let status = `Notebook: `;
    if (!this.inUse) {
      status += "desligado";
    } else {
      status += `ligado por ${this.usage} min`;
    }
    if (this.charger) {
      status += `, Carregador ${this.charger}`;
    }
    if (this.battery) {
      status += `, Bateria ${this.battery}`;
    }
    return status;
  }
  turnOn() {
    if (this.charger || this.battery && this.battery.getCharge() > 0) {
      this.inUse = true;
    } else {
      console.log("fail: n\xE3o foi poss\xEDvel ligar");
    }
  }
  turnOff() {
    this.inUse = false;
    this.usage = 0;
  }
  use(minutes) {
    if (!this.inUse) {
      console.log("fail: desligado");
      return;
    }
    if (this.charger && !this.battery) {
      this.usage += minutes;
      return;
    }
    if (!this.charger && this.battery) {
      if (this.battery.getCharge() > minutes) {
        this.battery.setCharge(this.battery.getCharge() - minutes);
        this.usage += minutes;
      } else {
        this.battery.setCharge(this.battery.getCharge() - minutes);
        this.inUse = false;
        console.log("fail: descarregou");
      }
      return;
    }
    if (this.charger && this.battery) {
      this.usage += minutes;
      this.battery.setCharge(this.battery.getCharge() + this.charger.getPower() * minutes);
      return;
    }
  }
  setBattery(newBattery) {
    this.battery = newBattery;
  }
  removeBattery() {
    if (!this.battery) {
      console.log("fail: Sem bateria");
      return null;
    }
    if (!this.charger && this.inUse) {
      this.inUse = false;
    }
    const removedBattery = this.battery;
    this.battery = null;
    return removedBattery;
  }
  setCharger(newCharger) {
    if (this.charger) {
      console.log("fail: carregador j\xE1 conectado");
      return;
    }
    this.charger = newCharger;
  }
  removeCharger() {
    if (!this.charger) {
      console.log("fail: Sem carregador");
      return null;
    }
    if (!this.battery || this.battery.getCharge() === 0) {
      this.inUse = false;
    }
    const removedCharger = this.charger;
    this.charger = null;
    return removedCharger;
  }
}
function main() {
  let notebook = new Notebook();
  while (true) {
    let line = input();
    console.log("$" + line);
    var par = line.split(" ");
    var cmd = par[0];
    if (cmd == "end") {
      break;
    } else if (cmd == "show") {
      console.log(notebook.toString());
    } else if (cmd == "turn_on") {
      notebook.turnOn();
    } else if (cmd == "turn_off") {
      notebook.turnOff();
    } else if (cmd == "use") {
      const minutes = parseInt(par[1]);
      notebook.use(minutes);
    } else if (cmd == "set_charger") {
      const power = parseInt(par[1]);
      notebook.setCharger(new Charger(power));
    } else if (cmd == "rm_charger") {
      const removedCharger = notebook.removeCharger();
      if (removedCharger) {
        console.log(`Removido ${removedCharger}`);
      }
    } else if (cmd == "set_battery") {
      const capacity = parseInt(par[1]);
      notebook.setBattery(new Bateria(capacity));
    } else if (cmd == "rm_battery") {
      const removedBattery = notebook.removeBattery();
      if (removedBattery) {
        console.log(`Removido ${removedBattery}`);
      }
    } else {
      console.log("fail: comando inv\xE1lido");
    }
  }
}
main();
