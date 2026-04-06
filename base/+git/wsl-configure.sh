#!/bin/bash

NAME=$1
EMAIL=$2
DIR=~/.local/bin
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

sudo -v

echo -n "${BLUE}Atualizando repositórios e configurando o git... "
sudo apt update >> /dev/null 2>&1
git config --global user.email "${EMAIL}"
git config --global user.name "${NAME}"

echo -n "Feito!\nInstalando pipx... "
sudo apt install -y pipx >> /dev/null 2>&1

echo -n "Feito!\nInstalando TKO... "
pipx install tko >> /dev/null 2>&1

echo -n "Feito!\nAdicionando ${DIR} ao PATH... "
echo "export PATH=\"$DIR:\$PATH\"" >> ~/.bashrc

# echo -n "Feito!\nClonando repositório ${URL}... ${NC}"

# # Extrair o nome do repositório da URL
# REPO_NAME=$(basename -s .git "$URL")

# # Clonar o repositório
# cd ~/
# git clone "$URL"

# echo -n "${BLUE}Feito!\nIniciando POO em ~/${REPO_NAME}..."

# cd ~/$REPO_NAME

# tko start poo >> /dev/null 2>&1

echo "Feito!\nReiniciando terminal..."

bash

echo "Feito!\n${GREEN}WSL Configurado com sucesso!${NC}"