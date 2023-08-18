## @038 Introdução ao git

<!-- toc -->
- [Instalação](#instalação)
- [Configuração Inicial](#configuração-inicial)
- [Fluxo de trabalho](#fluxo-de-trabalho)
- [Trabalhando com o repositório git do professor](#trabalhando-com-o-repositório-git-do-professor)
- [Trabalhando com seu repositório Git](#trabalhando-com-seu-repositório-git)
- [Adicionar & Confirmar & Enviar pra nuvem](#adicionar--confirmar--enviar-pra-nuvem)
- [Conflitos](#conflitos)
- [Ignorando arquivos](#ignorando-arquivos)
- [Desfazendo alterações e vendo diferenças](#desfazendo-alterações-e-vendo-diferenças)
- [Desafio](#desafio)
- [Guia rápida](#guia-rápida)
<!-- toc -->

- [Link para instalação e orientações iniciais](https://www.webdevdrops.com/git-no-windows-github/)


___
- [Guia Rápido](https://rogerdudler.github.io/git-guide/index.pt_BR.html)
- [Git book](https://pt.wikiversity.org/wiki/Git_B%C3%A1sico)
- [Vídeo Aulas](https://www.youtube.com/playlist?list=PLInBAd9OZCzzHBJjLFZzRl6DgUmOeG3H0) Assista dos vídeos de 1 até o 4.
- [Curso com certificado](https://www.schoolofnet.com/curso/git)
- [Tutorial com branchs](https://medium.com/trainingcenter/plano-para-estudar-git-e-github-enquanto-aprende-programa%C3%A7%C3%A3o-f5d5f986f459)



## Instalação
- Windows
    - Aplicativo de linha de comando
        - [Git for Windows](https://gitforwindows.org/)
        - Utilize o aplicativo `Git Bash` que será instalado.
    - Aplicativo visual
        - [Git Desktop](https://desktop.github.com/)
- Ubuntu
    - sudo apt install git

## Configuração Inicial
- `git config --global user.name "seu nome"`
- `git config --global user.email "seu email"`
- Para reduzir a quantidade de vezes que vocês digitam usuário e senha, você pode orientar o git a armazenar suas credenciais no cache:
    - `git config credential.helper cache`

Se estiver utilizando a máquina do laboratório, lembre de configurar pelo menos o email.

## Fluxo de trabalho

Seus repositórios **locais** consistem em três "árvores" mantidas pelo git. 
- A primeira delas é sua `Working Directory` que contém os arquivos vigentes. 
- A segunda `Index` (stage) que funciona como uma área temporária.
- A terceira a `HEAD` (repositório local) que aponta para o último `commit` (confirmação) que você fez.

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/038/trees.png)

![https://www.cureffi.org/2014/08/27/git-tutorial](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/038/diagrama.png)

## Trabalhando com o repositório git do professor

No repositório da disciplina, você não tem direito de `escrita`, você pode apenas `baixar` e `atualizar`.

- **Baixar**: Clonar um repositório externo. Essa operação de clone cria um vínculo entre a pasta local que será criada e a `pasta` remota que está no repositório do Github.
    - `git clone <url_do_repositório_do_professor>`
    - Ex: `git clone github.com/senapk/poo_2020_2`
- **Atualizar**: Sempre que o professor fizer uma alteração no repositório externo, você pode atualizar a sua pasta do repositório local **entrando na pasta** e digitando:
    - `git pull origin main`


## Trabalhando com seu repositório Git
- Crie seu repositório no github. 
    - Marque a opção Iniciar com Readme.
    - Copie o link do repositório
- No seu computador
    - Entre na pasta que você quer que fique o seu repositório.
    - Clique com o botão direito do mouse e escolha `abrir com git bash` ou `Git Bash here`
    - Dentro da pasta digite:
        - `git clone <url_do_seu_repositório>`


## Adicionar & Confirmar & Enviar pra nuvem
- Você pode ver o estado atual do repositório com
    - `git status`
- Você pode marcar os arquivos que deseja salvar (adicioná-las ao Index) usando algum dos seguintes comandos:
    - Para adicionar um arquivo específico
        - `git add <arquivo>`
    - Para adicionar todos os arquivos da pasta local
        - `git add .`
- Para salvar os arquivos que você _marcou_ em uma versão, você precisa fazer um _commit_:
    - `git commit -m "comentários das alterações"`
- Agora o arquivo é enviado para o HEAD, ou seja, ele é salvo e versionado localmente, mas ainda não foi enviado para o repositório remoto.
- Para visualizar seus "saves" no repositório local use:
    - `git log`
    - O log vai mostrar o "id", o horário, o usuário e a mensagem do commit.
- Se você já vinculou os repositórios (usando o clone ou o init), já pode enviar seus commits para o repositório remoto utilizando:
    - `git push origin main`
    - Você só pode enviar pushs para repositórios que você tem direito de escrita, como por exemplo o seu repositório.


## Conflitos
- Se estiver trabalhando com várias máquinas, ao acessar uma máquina e tentar dar o commit, o git vai avisar que já existem atualizações remotas. Lembre de sempre dar o `git pull origin master` antes de trabalhar numa nova pasta.
- Se existem conflitos e você quer sobrescrever o repositório remoto com o que existe no repositório local você pode fazer um `git push origin main --force`.

## Ignorando arquivos
- Crie um arquivo `.gitignore` no root no repositório e adicione quais tipos de arquivos você não quer que sejam rastreados pelo git.

## Desfazendo alterações e vendo diferenças
- Pode pode ver as diferenças com o comando `git diff nome_do_arquivo`.
- Pode desfazer as últimas alterações utilizando `git checkout -- nome_do_arquivo`.


## Desafio
- Clone seu repositório em duas pastas distintas do seu computador. 
- Utilize os comandos de push e pull para enviar comandos de uma pasta para a outra.

## Guia rápida

- `git init`: inicializar um repositório na pasta local
- `git add remote origin url`: vincula o repositório local no repositório remoto
- `git clone url`: copia o repositório remoto para pasta local
- `git add path`: marcar os arquivos que serão versionados
- `git commit -m "msg"`: salva uma versão com todos os arquivos marcados
- `git push origin main`: envia os commits para o servidor remoto
- `git pull origin main`: obtém as novidades do repositório remoto para o rep local
- `git log`: vê o histórico de commits
