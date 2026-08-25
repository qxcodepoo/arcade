BLUE='\033[0;34m'
GREEN='\033[0;32m'
NC='\033[0m'

echo -n "${BLUE}Instalando esbuild... "
sudo apt install -y esbuild >> /dev/null 2>&1

echo -n "Feito!\nInstalando nodejs... "
sudo apt install -y nodejs >> /dev/null 2>&1

echo "Feito!\n${GREEN} Extensão para TS instalado com sucesso!${NC}"