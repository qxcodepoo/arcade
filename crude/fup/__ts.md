---
layout: post
title: "Fup em ts"
---

```typescript

class Pessoa {
    nome: string;
    idade: number;
    constructor(nome: string = "", idade: number = 0) {
        this.nome = nome;
        this.idade = idade;
    }
    toString() {
        return this.nome + ":" + this.idade;
    }
}

// 1
let vet: Array<Pessoa> = new Array<Pessoa>();
//ou apenas
//let vet= new Array<Pesssoa>();
//########################################################
// 2
vet.push(new Pessoa("bruno", 18));
vet.push(new Pessoa("maria", 13));
vet.unshift(new Pessoa("diana", 12));

//########################################################
// 3 expandido
let saida = "(";
for(let pessoa of vet)
    saida += pessoa + " - ";
//a ultima pessoa vai adicionar um " - " extra, temos que retirar
saida = saida.substr(0, saida.length - 3);
saida += ")";
console.log(saida);

// 3 compacto
console.log("(" + vet.join(" - ") + ")")

//########################################################
// 4 expandido
let ind = -1;
for(let i in vet) {
    if(vet[Number(i)].nome == "bruno") {
        ind = Number(i);
        break;
    }
}
if (ind != -1)
    console.log("Nao encontrado");
else
    console.log("O indice eh " + ind);

// 4 compacto
let indice = vet.findIndex(x => x.nome == "bruno");
console.log(indice != -1 ? "Nao encontrado" : "O indice eh " + indice);

//########################################################

// 5 expandido
for(let pessoa of vet) {
    if(pessoa.nome == "maria") {
        pessoa.idade = 14;
        break;
    }
}

// 5 compacto
vet.forEach(x => {
    if(x.nome == "maria")
        x.idade = 14;
});

//########################################################
// 6
for(let i in vet) {
    if(vet[Number(i)].idade > 10) {
        vet.splice(Number(i), 1);
        break;
    }
}

//########################################################
// 7
vet.push(new Pessoa("diana", 11), new Pessoa("diana", 14), new Pessoa("diana", 10));

//########################################################
// 8 expandido
for(let i = vet.length - 1; i >= 0; i--)
    if(vet[i].nome == "diana")
        vet.splice(i, 1);

// 8 compacto
vet = vet.filter(x => x.nome != "diana");

//########################################################
// 9

vet = new Array<Pessoa>(new Pessoa("ana", 10), new Pessoa("bia", 12), 
                        new Pessoa("cid", 15), new Pessoa("deb", 8), 
                        new Pessoa("eva", 19));
vet.reverse();

//########################################################
// 10 expandido

let maiores11 = new Array<Pessoa>();
for(let pessoa of vet)
    if(pessoa.idade > 11)
        maiores11.push(pessoa);
    
// 10 compacto
let maiores11b = vet.filter(x => x.idade > 11);

//########################################################
// 11 expandido

let idades = new Array<number>();
for(let pessoa of vet)
    idades.push(pessoa.idade);
    
// 11 compacto
let idades2 = vet.map(x => x.idade);

//########################################################
// 12 expandido
for(let pessoa of vet)
    pessoa.idade += 2;

// 12 compacto
vet.forEach(x => x.idade += 2);

//########################################################
// 13 expandido
for(let pessoa of vet)
    if(pessoa.nome.indexOf("a") != -1)
        pessoa.idade += 2;

// 13 compacto
vet.filter(x => x.nome.indexOf("a") != -1).forEach(x => x.idade += 2);
    
```
