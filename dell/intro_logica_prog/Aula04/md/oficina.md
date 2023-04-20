---
output: pdf_document
header-includes: |
    \usepackage{fancyhdr}
---

\pagestyle{fancy}
\fancyhf{}
\lhead{Diogo Garbinato de Fagundes}
\rhead{Oficina Aula 04}
\rfoot{Página \thepage}
\lfoot{Introdução à Lógica de Programação}


```
Algoritmo controle de notas
Variáveis:
    nome, turma, disciplina: texto
    n1, n2, n3, media: decimal
Início
    SAIDA("Nome do aluno:")
    ENTRADA(nome)

    SAIDA("Turma do aluno:")
    ENTRADA(turma)

    SAIDA("Qual é a disciplina?")
    ENTRADA(disciplina)

    SAIDA("Valor da sua primeira nota:")
    ENTRADA(n1)

    SAIDA("Valor da sua segunda nota:")
    ENTRADA(n2)

    SAIDA("Valor da sua terceira nota:")
    ENTRADA(n3)

    media = (n1 + n2 + n3) / 3

    SAIDA("Aluno: ", aluno)
    SAIDA("Turma: ", turma)
    SAIDA("Disciplina: ", disciplina)
    SAIDA("Média final: ", media)
Fim
```