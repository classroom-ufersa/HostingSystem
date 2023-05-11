#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX_LINHA 1024

//Pede um numero e verifica se o numero foi inserido corretamente
float scan_de_numeros(void)
{
    char line[TAM_MAX_LINHA];
    char resto[50] = "Codigo Verificador &*()";
    float result;
    while (1) {
       if (fgets(line, TAM_MAX_LINHA, stdin) == NULL) {
           /* EOF or Error */
           return 1;
       }
       if (sscanf(line, "%f%s", &result, resto) != 1) {
           printf("\nSomente numeros, por favor: ");
           continue; 
       } 
       break;
    }
    return result;
}

void remover_caracteres_especiais(char *str) {
    int i = 0, j = 0;
    char c;
    while ((c = str[i++]) != '\0') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
            str[j++] = c;
        }
    }
    str[j] = '\0';
}