# Configuração

<!-- toc -->
- [bash](#bash)
- [vscode](#vscode)
- [node](#node)
  - [node: Windows](#node-windows)
  - [node: Debian](#node-debian)
<!-- toc -->

## bash

O interpretador de comandos que você vai usar para executar seus programas. Nos sistemas Linux e Mac, ele já vem instalado. No Windows, você precisa instalar o Git for Windows. O Windows já possui um interpretador de comandos, mas ele é muito limitado.

- Instalando e entendendo o bash: [link](https://github.com/senapk/fupisfun/blob/master/wiki/configure_bash_and_git_bash.md)
- Windows: Instalar o [Git for Windows](https://gitforwindows.org/)
- Para copiar do terminal use o atalho `ctrl+shift+c`
- Para colar no terminal use o atalho `ctrl+shift+v`

## vscode

A IDE onde você vai escrever seu código.

- Instalando e entendendo o vscode: [link](https://github.com/senapk/fupisfun/blob/master/wiki/configure_vscode.md)
- Instalação:
  - Debian: `sudo snap install code --classic`
  - Windows: [link](https://code.visualstudio.com/download)
- Plugin importantes:
  - Error Lens: Ver os erros ao lado do código
  - Code Runner: Cria um botão para executar o código
  - Escrever código markdown
    - Markdown All in One
    - markdownlint
    - Markdown Preview Enhanced
- Configuração importante:
  - Vá nas configurações do vscode Ctrl + , ou vá pelo menu:
    - Inglês: File -> Preferences -> Settings
    - Português: Arquivo -> Preferências -> Configurações.
  - No campo de busca de configuração digite auto save.
  - Na opção do auto save escolha after delay.

- Para testar se a instalação está correta, vá no gerenciador de arquivos, clique com o botão direito e abra o terminal bash na pasta. No terminal escreva para abrir o vscode na pasta atual:

```bash
code .
```

- Se você instalou, mas está com problemas de acesso verifique se o vscode não está marcado como "executar como administrador". Se estiver, desmarque e reinicie o vscode.

## node

- O node é composto de duas ferramentas principais:
  - node: que executa programas javascript
  - npm: que instala pacotes javascript

### node: Windows

Instale manualmente [nodejs](https://nodejs.org/en/download/)

### node: Debian

```bash
# habilitar uma versão mais recente do nodejs
sudo apt install -y curl 
curl -sL https://deb.nodesource.com/setup_19.x | sudo -E bash - 

# Instalar o nodejs e npm
sudo apt install -y nodejs

# para testar a instalação
node -v
npm -v
```
