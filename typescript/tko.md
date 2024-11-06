# TKO

Para rodar os testes localmente ou no replit você precisará do `tko` instalado.

## Instalação via replit

1. Crie um projeto `typescript` em [replit.com](https://replit.com)
2. Abra o `Shell` e copie a seguinte linha de comando:

```bash
curl -sSL https://raw.githubusercontent.com/senapk/tko/master/replit/ts/update.sh | bash
```

Após instalar, aperte o botão `Run` para iniciar o `habilitar` os comandos.

## Instalação local no Windows

### 1. Instale o python

- Instale o `python` utilizando o instalador do [site oficial](https://www.python.org/downloads/)
  - Marque a opção `Add Python to PATH` durante a instalação.
- Para verificar se a instalação foi bem sucedida, abra o `powershell` e digite:

```bash
python --version
```

Se não tiver dado certo, se der comando não encontrado, execute o instalador de novo e certifique-se de marcar a opção `Add Python to PATH`.

### 2. Instale o esbuild e o tko

- Abra o powershell e digite as seguintes linhas, uma por vez:

```bash

# para instalar o tko
pip install tko

# reabra o powershell como admin antes e dar o próximo comando
# para habilitar a execução de scripts
Set-ExecutionPolicy Unrestricted
```
