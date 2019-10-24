## Hospital #nxn #repositorios
### Cadastrar Pacientes, Médicos e Plantões.
![](figura.jpg)


Na UTI do nosso hospital existem vários pacientes. Cada paciente é atendico por médicos de várias especialidades. Pacientes e médicos podem se comunicar via mensagens. O sistema deve ser capaz de: 

- cadastrar pacientes e médicos.
- informar quais os médicos que atendem determinado paciente.
- informar quais pacientes que são atendidos por um médico.
- enviar mensagens de um paciente para seus médicos.
- enviar mensagens de um médicos para seus pacientes.

---
## Funcionalidades

- **Repositórios Individuais - 3.0 P**
    - Adicionar pacientes.
        - Cada paciente tem um id(nome) e uma diagnóstico.
    - Adicionar médicos.
        - Cada médico tem um id(nome) e uma especialidade.


```
addPacs fred-fratura alvis-avc goku-hemorragia silva-sinusite
  done
addMeds bisturi-cirurgia snif-alergologia facada-cirurgia
  done
seeAll
  Pac: fred:fratura     Meds: []
  Pac: alvis:avc        Meds: []
  Pac: goku:hemorragia  Meds: []
  Pac: silva:sinusite   Meds: []
  Med: bisturi:cirurgia Pacs: []
  Med: snif:alergologia Pacs: []
  Med: facada:cirurgia  Pacs: []
```

- **Vinculos - 3.0 P**
    - Vincular pacientes e médicos.
        - Dois médicos da mesma especialidade não podem ser responsáveis pelo mesmo paciente.
        - O paciente não deve entrar duas vezes na lista do médico e vice-versa.

```
# tie _med _pac _pac ...
tie bisturi fred alvis goku
  done
tie snif silva alvis
  done
tie facada goku
  fail: ja existe outro medico da especialidade cirurgia

seeAll
  Pac: fred:fratura     Meds: [bisturi]
  Pac: alvis:avc        Meds: [bisturi snif]
  Pac: goku:hemorragia  Meds: [bisturi]
  Pac: silva:sinusite   Meds: [snif]
  Med: bisturi:cirurgia Pacs: [fred alvis goku]
  Med: snif:alergologia Pacs: [silva alvis]
  Med: facada:cirurgia  Pacs: []
```

- **Mensagens - 3.0 P**
    - Pacientes podem enviar mensagens para seus medicos.
    - Médicos podem enviar mensagens para seus pacientes.
    - Qualquer pessoa pode olhar suas mensagens.
    - Depois de ver as mensagens elas são apagadas automaticamente.

```
msg alvis bisturi posso tomar homeprazol?
  done
msg goku bisturi coceira no reto eh normal?
  done
inbox bisturi
  [alvis: posso tomar homeprazol?]
  [goku: coceira no reto eh normal?]
msg bisturi alvis chupe limao que passa
  done
msg bisturi goku venha na minha sala pra eu olhar
  done
inbox goku
  [bisturi: venha na minha sala pra eu olhar]
msg goku facada
  fail: goku nao conhece facada
```

## Diagrama de Classes

