# Trabalhos futuros

Este documento registra competências intermediárias que podem ampliar o curso
sem depender de web, banco de dados ou frameworks específicos.

## Prioridade alta

### Modularização e pacotes

Separar domínio, serviços, interface e testes em módulos; controlar imports,
evitar dependências circulares e organizar um projeto Python como pacote.

### Persistência em arquivos

Ler e gravar JSON, CSV e texto estruturado; serializar objetos; tratar arquivo
inexistente ou corrompido; separar armazenamento de regras de domínio.

### Testes intermediários

Adicionar `setUp`, testes parametrizados, testes de integração, mocks, fakes,
testes de regressão, cobertura e testes de contrato para implementações
polimórficas.

### Tipagem avançada

Explorar `Protocol`, genéricos, `TypeVar`, `TypeAlias`, `Callable`, `TypedDict`
e contratos mais expressivos com `mypy --strict`.

### Iteradores e geradores

Trabalhar `__iter__`, `__next__`, `yield`, iteráveis, iteradores e os protocolos
de `collections.abc`, sem expor coleções internas desnecessariamente.

## Prioridade média

### Context managers

Usar `with`, `__enter__` e `__exit__` para fechar arquivos, agrupar operações e
restaurar estado após falhas.

### Datas e relógios injetáveis

Usar `datetime`, durações e relógios controláveis em testes, especialmente nas
atividades Relógio, Estacionamento e Tarifas.

### Algoritmos e complexidade

Comparar listas, mapas, conjuntos, deques, heaps, ordenação e busca, discutindo
complexidade temporal e espacial.

### Dependências e empacotamento

Usar `pyproject.toml`, ambientes virtuais, dependências de desenvolvimento,
comandos padronizados e configuração reprodutível de ferramentas.

### Depuração e diagnóstico

Praticar leitura de stack traces, debugger, logging, níveis de log e criação de
casos mínimos para reproduzir defeitos.

## Tópico avançado opcional

Introduzir concorrência básica com threads, processos, locks, filas de trabalho,
condições de corrida e segurança de estruturas compartilhadas. Esse conteúdo
deve aparecer apenas depois de os alunos dominarem estado, composição, testes e
tratamento de erros.

## Possíveis evoluções de atividades existentes

- `Anotações`: persistência em JSON e modularização.
- `Tarifas`: context manager para agrupar operações e extornos.
- `Estacionamento`: relógio injetável e uso de `datetime`.
- `Cadastro`: testes de contrato para diferentes tipos de conta.
- `Twitter` e `WhatsApp`: repositórios em arquivo e testes de integração.
- `Vetores` e `Trem`: iteradores, deques e análise de complexidade.
- `Produto`: genéricos e composição de catálogos em módulos.
