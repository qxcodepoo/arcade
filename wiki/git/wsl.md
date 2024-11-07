# Script para instalação do tko e dependencias no WSL

WSL significa Windows Subsystem for Linux, é um ambiente de execução de aplicativos Linux no Windows.

```bash

# instalando o wsl, digite sim para as perguntar, depois de instalar, reinicie a máquina
wsl --install

```

Abra o aplicativo Ubuntu no Windows para ter acesso ao terminal do WSL.

```bash
sudo apt update
git config --global user.email "seu email"
git config --global user.name "seu nome"

# instalando o pipx
sudo apt install -y pipx build-essential python3-dev python3-venv python3-pip

# instalando o tko
pipx install tko

# adicionando o path
echo "export PATH=\"$HOME/.local/bin:\$PATH\"" >> ~/.bashrc

#reiniciando o terminal para aplicar as mudanças
bash
```

## Ferramentas do typescript

```bash
sudo apt install -y nodejs
npm install esbuild typescript ts-node readline-sync
```

## Antes de começar a editar

Abra o VSCode e instale a extensão `WSL` do Windows, com aproximadamente 30 milhões de downloads.

## Usando o VSCode

Abra o terminal do Ubunto, navegue até onde está seu repositório, digite `code <pasta>` para abrir o vscode na pasta.
