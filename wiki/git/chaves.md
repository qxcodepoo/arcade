# Configurando acesso ao Github na sua máquina

## WINDOWS e MAC

- Modo Fácil: Baixe, instale e configure pelo [Github Desktop](https://desktop.github.com/download).
- Modo normal: [Criação e instalação das chaves](https://ryan.dev.br/2023-04-17-github-ssh-pt-br/)

## LINUX

Para configurar uma chave RSA no Linux para acessar o GitHub, siga estas etapas:

### Gerar a chave RSA

- Abra o terminal e digite o seguinte comando:

```bash
ssh-keygen -t rsa -b 4096 -C "seu_email@exemplo.com"
```

- O parâmetro `-t rsa` indica o tipo de chave, e `-b 4096` define o comprimento (4096 bits para mais segurança).
- Substitua `"seu_email@exemplo.com"` pelo e-mail que você usa no GitHub.

### Salvar a chave

- Após o comando, será solicitado o local para salvar a chave. Pressione Enter para aceitar o local padrão (`~/.ssh/id_rsa`).
- Se desejar, defina uma senha para proteger a chave. Isso ajuda na segurança, especialmente em máquinas compartilhadas.

### Iniciar o agente SSH

- No terminal, inicie o agente SSH com o comando:

```bash
eval "$(ssh-agent -s)"
```

### Adicionar a chave privada ao agente

- Use o seguinte comando para adicionar a chave ao SSH Agent:

```bash
ssh-add ~/.ssh/id_rsa
```

### Copiar a chave pública

- Copie a chave pública com o comando:

```bash
cat ~/.ssh/id_rsa.pub
```

- O conteúdo exibido no terminal é sua chave pública. Copie-o para usar no GitHub.

### Adicionar a chave pública ao GitHub

- Acesse o [GitHub](https://github.com/) e faça login.
- Vá para **Settings** > **SSH and GPG keys** > **New SSH key**.
- Dê um nome para a chave (por exemplo, "Meu computador") e cole o conteúdo da chave pública.
- Clique em **Add SSH key**.

### Testar a conexã

- No terminal, use o comando abaixo para testar a conexão:

```bash
ssh -T git@github.com
```

- A primeira conexão pode pedir que você confirme a identidade do GitHub. Digite "yes" para prosseguir.
- Se tudo estiver correto, você verá uma mensagem de sucesso.

Após esses passos, seu sistema estará configurado para acessar o GitHub com a chave SSH.
