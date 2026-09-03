# Relatório da revisão

As atividades foram organizadas por carga conceitual, mantendo Python como
implementação canônica, domínio separado do Shell, testes progressivos e
descrições com objetivo, conceitos, técnicas e pré-requisitos.

Foram revisados os blocos de polimorfismo, mapas, exceções, mensagens,
composição e coleções. Foram adicionados ou corrigidos testes, diagramas e
implementações Python para Zoo, Pagamento, Shapes, Estacionamento, Cofre,
Cadastro, Twitter, Salário, Mensagem, Comunicador, Paciente, WhatsApp, Grupo,
Vetores, Anotações, Trem, Produto e Tarifas.

`TS Install` foi removida conforme solicitado. A progressão de mensagens ficou
`Mensagem → Comunicador → WhatsApp → Grupo`; a progressão de polimorfismo ficou
`Zoo → Pagamento → Shapes → Estacionamento → Cofre → Cadastro`.

Foram executados testes unitários, `mypy --strict` nas implementações Python e
`git diff --check`. Permanecem apenas eventuais ajustes de mensagens de Shell
caso uma avaliação automática antiga exija exatamente o contrato legado.
