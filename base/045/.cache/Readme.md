## @045 Instalação Typescript

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/045/cover.jpg)

## 01. Instalação do Node no Windows

[FONTE](https://balta.io/blog/node-npm-instalacao-configuracao-e-primeiros-passos)

- Baixe o node em [LINK](https://nodejs.org/en/download/)
- Execute o instalador
- Verifique a instalação abrindo o terminal e digitando `node -v` e `npm -v`
- Se quando for executar algum script, o seguinte erro aparecer:
```
"O arquivo XXXX não pode ser carregado porque a execução de scripts foi desabilitada neste sistema"
```
- Execute o seguinte comando no PowerShell como administrador:
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned
```

## 02. Instalação Global do typescript
Abra o PowerShell e execute
```
npm install -g typescript
npm install -g ts-node
```
Isso vai habilitar o typescript globalmente para todos os projetos. E habilitar o comando `tsc` e `ts-node` no terminal.

## 03. Executando um arquivo typescript

- Crie o seguinte arquivo em alguma pasta:
```typescript
// hello.ts
function hello(name: string) {
    console.log(`Hello ${name}`);
}
hello();
```

- Agora abra o PowerShell na pasta onde o arquivo foi criado e execute o comando:
```
tsc hello.ts
```
- Isso deve gerar o arquivo `hello.js`. 
- Se aparecer `arquivo não encontrado`, verifique se você está na pasta correta.
- Para executar, basta digitar `node hello.js`

## 04. Executando diretamente

- Para executar o arquivo typescript diretamente sem precisar passar pela etapa de gerar o javascript, basta digitar `ts-node hello.ts`.

