# Prática git

Essa prática tem 10 pontos. Pontue a atividade ao final de acordo com o que foi realizado.

Faça um relatório de um parágrafo explicando o que foi feito, o que foi aprendido e as dificuldades encontradas.

## Manipulando localmente (1 ponto)

- Criar um nova pasta: `mkdir nome-da-pasta`
- Entrar na pasta criada: `cd nome-da-pasta`
- Criar um repositório vazio: `git init`
- Abrir o vscode na pasta criada: `code .`
- Saber o estado do repositório: `git status`
- Criar um arquivo `code nome-do-arquivo.extensão`
- Adicione conteúdo ao arquivo e salvar
  - Coloque o vscode para salvar automaticamente na opção auto save
  - Control , e escolher auto save (after delay)

## Primeiro fluxo de trabalho (1 ponto)

- Adicionar o arquivo ao stage: `git add nome-do-arquivo.extensão`
- Fazer um commit: `git commit -m "Mensagem do commit"`
- Se o commit der erro, ele pode pedir pra identificar o usuário:
  - `git config --global user.name "Seu Nome"`
  - `git config --global user.email "email"`
- Faça também o add e o commit pela interface do vscode

## Desfazendo mudanças (1 ponto)

- Fazer uma mudança no arquivo e voltar para versão do commit
  - `git restore nome-do-arquivo.extensão`
- Faça o restore também pela interface do vscode
  - Clicando no botão `Discard Changes` no vscode

## Olhando o histórico (1 ponto)

- Fazer uma alteração e salvar via vscode
- Ver histórico de commits: `git log`
- Saber onde ficam as versões dos arquivos alterados pelo vscode
- Conseguir pular o repositório para uma versão anterior
  - `git checkout id-do-commit`
- Voltar para a versão mais recente
  - `git checkout main`

## Trabalhando remotamente (1 ponto)

- Criar um repositório novo no github, inicializando ele com um readme.md
- Clicar em criar codespace
- No codespace, alterar algo, e fazer o add, commit, push
- Verificar mudanças no github
- Alterar algo no repositório via interface web do github
- Puxar as modificações para o codespace utilizando `git pull`

## Criando um conflito (2 pontos)

- Alterar um arquivo pela interface web do github e fazer commit
- Alterar o mesmo arquivo no codespace
- Tentar fazer o push no codespace
- Tentar fazer o pull no codespace
- Definir que a estratégia padrão para conflitos é fazer o merge
  - `git config --global pull.rebase false`
- Fazer o pull novamente
- Usar o git status para ver os arquivos em conflito
- Abrir cada um dos arquivos marcados como conflito (!)
- Resolver o conflito, removendo as marcações do git
- Fazer o add, commit e push
- Verificar o resultado no github

## Usando máquina local (3 pontos)

- Instalar o git, o vscode e as ferramentas de compilação na sua máquina local.
- Configurar acesso ao git via chaves ssh ou token de acesso pessoal.
- Conseguir clonar na máquina local o repositório do github.
- Fazer algum commit, push e pull na máquina local e enviar para o github.

```sh
>>>>>>>>
1
========
1
<<<<<<<<
```
