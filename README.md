# Get_Next_Line

get_next_line é uma função que lê e retorna uma linha de um arquivo a cada chamada, guardando os dados num espaço dinâmico chamado 'stash'.


## Sumário

- [Protótipo](#Protótipo)
- [Retorno](#Retorno)
- [Regras do Projecto](#Regras_do_Projecto)
- [Arquivos do Projeto](#Arquivos_do_Projeto)
- [Compilar e Executar](#Compilar_e_Executar)


## Protótipo

```
char	*get_next_line(int fd);
```


## Retorno

- A próxima linha do arquivo terminado por ```'\n'``` ou ```'\0'```, incluindo sempre um ```'\n'``` no final.
- ```'NULL'``` em caso de erro ou quando chegou ao fim do arquivo.


## Regras do Projecto

1. O comportamento deve ser consistente independente do valor do ```'BUFFER_SIZE'```.
2. É proibido o uso de funções da biblioteca standard, excerto ```'read'```, ```'malloc'``` e ```free'```.
4. O código deve garantir que não haja vazamento de memória (leaks).


## Arquivos do Projeto

1. get_next_line.h
 - Declaração do protótipo da função ```get_next_line```.
 - Prototipa as funções auxiliares.
 - Define macros, como ```BUFFER_SIZE```.
2. get_next_line.c
 - Implementa a lógica principal para ler e retornar uma linha de um arquivo.
3. get_next_line_utils.c
 - Implementa funções auxiliares, como manipuladores de strings e memória, usadas na funçao principal.


## Compilar e Executar

1. Compilação:
   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
   ```
2. Execução:
   ```bash
   ./gnl
   ```
