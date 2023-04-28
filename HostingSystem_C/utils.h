#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.c"
#include "sistema.c"

//Pede um numero e verifica se o numero foi inserido corretamente
int scan_de_inteiros(void)
{
    char *line = NULL;
    size_t len = 0;
    int result;
    while (1) {
       if (getline(&line, &len, stdin) == -1) {
           /* eof or error, do whatever is sensible in your case */
           return 1;
       }
       if (sscanf(line, "%d", &result) != 1) {
           printf("Somente numeros, por favor: ");
           continue; 
       } 
       break;
    }
    printf("Numero digitado: %d\n", result);
    return result;
}