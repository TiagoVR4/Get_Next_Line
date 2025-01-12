# Get_Next_Line

get_next_line é uma função que lê e retorna uma linha de um arquivo a cada chamada, guardando os dados num espaço dinâmico chamado 'stash'.


## Sumário

- [Protótipo](#Protótipo)



## Protótipo

```
char	*get_next_line(int fd);
```


## Retorno

- A próxima linha do arquivo terminado por '\n' ou '\0', incluindo sempre um '\n' no final.
- 'NULL' em caso de erro ou quando chegou ao fim do arquivo.


## Regras do Projecto(passar este titulo para cima do protótipo)

1. O comportamento deve ser consistente independente do valor do 'BUFFER_SIZE'.
2. É proibido o uso de funções da biblioteca standard, excerto 'read', 'malloc', 'free'.
4. Não deve haver leaks de memória.


## Arquivos do Projeto

1. get_next_line.h
 - Declaração do protótipo da função get_next_line.
 - Prototipa as funções auxiliares.
 - Define macros, como BUFFER_SIZE.
