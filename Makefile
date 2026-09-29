.PHONY: all clean
.DEFAULT_GOAL := all

index:
	@echo "Atualizando indexer"
	tko build index README.md --from labs --from wiki

save:
	@echo "Atualizando indexer"
	tko build index README.md --from labs --from wiki --save

all: index
	@find . -type d -name "__pycache__" -exec rm -rf {} +
	@echo "Atualizando wiki"
	@find wiki -type f -name "*.md" -exec tko tool mdpp {} \;
	@echo "Atualizando Readmes"
	tko build task labs/*
	@echo "Fim"

clean:
	@find . -depth -name ".cache" -exec rm -rf {} +
	@find . -type f -name "README.md" -exec tko tool mdpp --clean {} \;
