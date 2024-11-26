# Criando repositórios local em máquina pessoal ou pública

## Instale o WSL (Windows Subsystem for Linux) no windows

Abra o powershell como administrador e cole o seguinte comando:

```bash
wsl --install
```

Após isso, reinicie o computador, abra o terminal do windows e digite `wsl` para abrir o terminal linux.

## Utilizando chave SSH para acesso permanente na sua máquina pessoal

- Modo normal: [Criação e instalação das chaves](https://ryan.dev.br/2023-04-17-github-ssh-pt-br/)

## Utilizando um Token para acesso temporário nas máquinas de laboratório

## Configurando o token do git para acesso temporário

### Criando token

1. Login no github
2. Configurações -> Configurações Desenvolvimento -> Token de Acesso
3. Gerar novo token(Classic) -> Coloque um nome para o token -> Selecionar primeira caixa de permissões `repo`.
4. No prazo de expiração, selecione o tempo que deseja que o token dure. Se for para utilizar na sua máquina pessoal, coloque indefinido, se for para utilizar nas máquinas do laboratório, coloque 7 dias. Sempre que desejar, você pode gerar um novo token, ou invalidar o token atual.
5. Clique em gerar token

### Definindo configurações para o git

- Você precisa definir algumas configurações para que o git saiba quem é você.
- Esses comandos não precisam ser dados na próxima vez que for utilizar a mesma máquina.

```bash
git config --global user.name "seu nome"
git config --global user.email "seu email"
```

- Defina quanto tempo deseja que o token fique salvo em cache, escolha uma das opções abaixo:

```bash
git config --global credential.helper --unset # toda operação de clone ou push vai pedir o token
git config --global credential.helper "cache --timeout=10000"  # salva o token por 10000 seg (3 horas) ou até desligar
git config --global credential.helper store   # Salva o token permanentemente
```

### Clonando seu repositório

1. Vai até o repositório
2. Clicar em Code -> HTTPS -> Copiar URL
3. No terminal, navegue até a pasta onde deseja colocar o repositório.
4. Digitar `git clone <a url que copiou do seu repositório>`
5. Digitar usuário do github
6. Copie o token de acesso e cole no terminal usando `Ctrl+Shift+V`
7. Se o clone der problema de path inválido no windows, você pode dar esse comando antes

- `git config --global core.protectNTFS false`

### Trabalhando com o repositório

- Abra o vscode na pasta que você clonou
  - opção 1: `code <nome_da_pasta>`
  - opção 2: Abra o vscode e arraste a pasta pra dentro dele
  - opção 3: Abra o vscode, vá em File -> Open Folder e selecione a pasta onde está o repositório
- Altere ou adicione um arquivo
- Faça o fluxo normal para `git add, git commit -m "mensagem", git push`
- Se necessário, antes do commit, ele pode pedir que você se identifique.

### Para abrir seu repositório baixado no tko

`tko open <pasta_onde_está_repositório>`

exemplo: `tko open poo`

### Se quiser limpando o cache do git manualmente, caso tenha escolhido a opção de salvar o token permanentemente

```bash
git credential-cache exit
```
