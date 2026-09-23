# Orientações do repositório

As regras para criar, revisar ou manter o README.md de uma atividade e seus artefatos associados estão na skill [`activity-readme`](.codex/skills/activity-readme/SKILL.md).

Para o README.md do índice geral, use a skill [`general-index-formatting`](.codex/skills/general-index-formatting/SKILL.md).

Kotlin é a linguagem de referência do repositório. Descrições de APIs, assinaturas, tipos e diagramas de atividades devem usar a notação Kotlin; novas soluções executáveis devem ficar em `src/kt` e ser executadas com `tko run . -l kt`. Em diagramas, marque membros estáticos com `$` no fim da linha. Não introduza padrões de TypeScript ou Python nas descrições e soluções de referência.

Ao trabalhar neste repositório, preserve alterações preexistentes no worktree e evite mudanças não relacionadas ao pedido atual.
