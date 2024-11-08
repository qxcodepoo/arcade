# Configurando acesso ao Github na sua máquina

## Utilizando chave SSH para acesso permanente na sua máquina pessoal

- Modo Fácil: Baixe, instale e configure pelo [Github Desktop](https://desktop.github.com/download).
- Modo normal: [Criação e instalação das chaves](https://ryan.dev.br/2023-04-17-github-ssh-pt-br/)

## Utilizando um Token para acesso temporário nas máquinas de laboratório

## Configurando o token do git para acesso temporário

### Criando token

1. Login no github
2. Configurações -> Configurações Desenvolvimento -> Token de Acesso
3. Gerar novo token(Classic) -> Coloque um nome -> Selecionar primeira caixa de permissões `repo`.
4. Gerar token

### Clone

1. Vai até o repositório
2. Clicar em Code -> HTTPS -> Copiar URL
3. No terminal, navegue até a pasta onde deseja colocar o repositório.
4. Digitar `git clone <a url que copiou do seu repositório>`
5. Digitar usuário do github
6. Copie o token de acesso e cole no terminal usando `Ctrl+Shift+V`
7. Se o clone der problema de path inválido no windows, você pode dar esse comando antes

- `git config --global core.protectNTFS false`

### Mantendo o token no cache até o reboot

- Você precisa definir algumas configurações para que o git saiba quem é você e que ele deve guardar seus dados de autenticação até o fim da sessão.
- Esses comandos não precisam ser dados na próxima vez que for utilizar a mesma máquina.

```bash
git config --global user.name "seu nome"
git config --global user.email "seu email"
git config --global credential.helper cache
```

### Trabalhando com o repositório

- Abra o vscode na pasta que você clonou
  - opção 1: `code <nome_da_pasta>`
  - opção 2: Abra o vscode e arraste a pasta pra dentro dele
  - opção 3: Abra o vscode, vá em File -> Open Folder e selecione a pasta onde está o repositório
- Altere ou adicione um arquivo
- Faça o fluxo normal para `git add, git commit -m "mensagem", git push`
- Se necessário, antes do commit, ele pode pedir que você se identifique.

### Para abrir seu repositório baixado no tko

`tko play <pasta_onde_está_repositório>`

exemplo: `tko play poo`
