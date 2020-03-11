/*
declare function require(name:string);
var readline = require('readline-sync');
function cin(text: string): string{
    return readline.question(text);
}
function cout(text: string){
    return console.log(text);
}
*/
function cin(text) {
    return prompt(text);
}
function cout(text) {
    return alert(text);
}
var Operacao = (function () {
    function Operacao(descricao, value, saldo) {
        if (descricao === void 0) { descricao = ""; }
        if (value === void 0) { value = 0.0; }
        if (saldo === void 0) { saldo = 0.0; }
        this.value = value;
        this.descricao = descricao;
        this.saldoParcial = saldo;
    }
    Operacao.prototype.toString = function () {
        return "[" + this.descricao + ", " + this.value + ", saldo: " + this.saldoParcial + "]";
    };
    return Operacao;
}());
var Conta = (function () {
    function Conta(id) {
        if (id === void 0) { id = 0; }
        this.id = id;
        this.saldo = 0;
        this.extrato = [];
    }
    Conta.prototype.sacar = function (value) {
        if (value <= 0)
            return false;
        if (this.saldo > value) {
            this.saldo -= value;
            this.extrato.push(new Operacao("saque", -value, this.saldo));
            return true;
        }
        return false;
    };
    Conta.prototype.depositar = function (value) {
        if (value <= 0)
            return false;
        this.saldo += value;
        this.extrato.push(new Operacao("deposito", value, this.saldo));
        return true;
    };
    Conta.prototype.getSaldo = function () {
        return this.saldo;
    };
    Conta.prototype.getId = function () {
        return this.id;
    };
    Conta.prototype.getExtrato = function (qtd) {
        var last = [];
        var size = this.extrato.length;
        if (!qtd || (qtd > size))
            qtd = size;
        for (var i = (size - qtd); i < size; i++)
            last.push(this.extrato[i]);
        return last;
    };
    return Conta;
}());
var Controller = (function () {
    function Controller() {
        this.conta = new Conta(5);
        this.conta.depositar(40);
        this.conta.sacar(5);
        this.conta.sacar(10);
        this.conta.depositar(30);
    }
    Controller.prototype.commandLine = function () {
        var ui = [""]; //user input
        while (ui[0] != "fim") {
            ui = cin("digite comando ou help: ").split(" ");
            if (ui[0] == "help") {
                cout("help\n" +
                    "iniciar $id\n" +
                    "saldo\n" +
                    "saque $value\n" +
                    "deposito $value\n" +
                    "extrato\n" +
                    "extratoLast $qtd\n" +
                    "fim");
            }
            if (ui[0] == "iniciar") {
                this.conta = new Conta(Number(ui[1]));
                cout("Conta " + this.conta.getId() + " criada");
            }
            if (ui[0] == "saldo") {
                cout("Conta: " + this.conta.getId() + ", Saldo: " + this.conta.getSaldo());
            }
            if (ui[0] == "saque") {
                if (this.conta.sacar(Number(ui[1])))
                    cout("Saque efetuado");
                else
                    cout("Erro no saque");
            }
            if (ui[0] == "deposito") {
                if (this.conta.depositar(Number(ui[1])))
                    cout("Deposito Efetuado");
                else
                    cout("Erro");
            }
            if (ui[0] == "extrato") {
                var output = "Extrato:\n";
                //of anda nos valores
                //in nas chaves
                for (var _i = 0, _a = this.conta.getExtrato(); _i < _a.length; _i++) {
                    var e = _a[_i];
                    output += "" + e + "\n";
                }
                cout(output);
            }
            if (ui[0] == "extratoLast") {
                var output = "Extrato:\n";
                //of anda nos valores
                //in nas chaves
                for (var _b = 0, _c = this.conta.getExtrato(Number(ui[1])); _b < _c.length; _b++) {
                    var e = _c[_b];
                    output += "" + e + "\n";
                }
                cout(output);
            }
        }
    };
    return Controller;
}());
var controller = new Controller();
controller.commandLine();
//# sourceMappingURL=main.js.map