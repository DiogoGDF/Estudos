#language:pt

Funcionalidade: promocao do dia!
    Queremos saber qual a promocao do dia na loja XYZ

Cenário: Hoje é dia de descontos em artigos esportivos
    Dado que hoje é "sexta-feira"
    Quando eu pergunto qual é a promocao do dia
    Então a resposta deve ser "desconto de 30% em artigos esportivos"
