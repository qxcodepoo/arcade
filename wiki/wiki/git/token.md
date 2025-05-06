# Configuração de Token para acesso temporário

## Instalando o TKO

Se o tko não está instalado na sua máquina, siga as instruções em [tko](https://github.com/senapk/tko?tab=readme-ov-file#instala%C3%A7%C3%A3o)

## Configurando o token do git para acesso temporário

### Criando token

1. Login no github
2. Configurações -> Configurações Desenvolvimento -> Token de Acesso
3. Gerar novo token(Classic) -> Coloque um nome -> Selecionar primeira caixa de permissões `repo`.
4. Gerar token

### Clone

1. Vai até o repositório
2. Clicar em Code -> HTTPS -> Copiar URL
3. No terminal, digitar `git clone <a url que copiou do seu repositório>`
4. Digitar usuário e cola o token de acesso
5. Se o clone der problema de path inválido no windows, você pode dar esse comando antes

- `git config --global core.protectNTFS false`

### Mantendo o token no cache até o reboot

Por padrão, o git não salva o token em cache, então você precisa ficar digitando toda vez que for fazer um push. Para salvar o token no cache até o logout do SO, você pode usar o comando:

- `git config --global credential.helper cache`

### Trabalhando com o repositório

- Abra o vscode na pasta que você clonou
  - opção 1: `code <nome_da_pasta>`
  - opção 2: Abra o vscode e arraste a pasta pra dentro dele
  - opção 3: Abra o vscode, vá em File -> Open Folder e selecione a pasta onde está o repositório
- Altere ou adicione um arquivo
- Faça o fluxo normal para `git add, git commit -m "mensagem", git push`
- Se necessário, antes do commit, ele pode pedir que você se identifique.
git config --global user.name "seu nome"
git config --global user.email "seu email"

### Para abrir seu repositório baixado no tko

`tko open poo`
