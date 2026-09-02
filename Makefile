.PHONY: all clean

index:
	@echo "Atualizando indexer"
	tko build index README.md labs

save:
	@echo "Atualizando indexer"
	tko build index README.md labs --save

all: index
	@find . -type d -name "__pycache__" -exec rm -rf {} +
	@echo "Atualizando wiki"
	@find wiki -type f -name "*.md" -exec tko util mdpp {} \;
	@echo "Atualizando Readmes"
	tko build all labs/* -mc
	@echo "Fim"

clean:
	@find . -depth -name ".cache" -exec rm -rf {} +
	@find . -type f -name "README.md" -exec tko util mdpp --clean {} \;
