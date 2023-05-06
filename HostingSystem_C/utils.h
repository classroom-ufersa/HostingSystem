#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Pede um numero e verifica se o numero foi inserido corretamente
float scan_de_numeros(void)
{
    char *line = NULL;
    char resto[50] = "Codigo Verificador &*()";
    //printf("'%s'\n", resto);
    size_t len = 0;
    float result;
    printf("\nDigite somente numeros: ");
    while (1) {
       if (getline(&line, &len, stdin) == -1) {
           /* EOF or Error */
           return 1;
       }
       if (sscanf(line, "%f%s", &result, resto) != 1) {
           printf("\nSomente numeros, por favor: ");
           continue; 
       } 
       break;
    }
    //printf("Numero digitado: %.2f\n", result);
    //printf("Caracteres restantes: %s", resto);
    return result;
}

void remover_caracteres_especiais(char *str) {
  int i = 0, ii = 0;

  // loop para percorrer toda a string
  while (str[i] != '\0') {
    if (isalpha(str[i])) {
      // Salvando na propria string os valores que são somente caracteres 
      str[ii] = str[i];
      ++ii;
    }
    ++i;
  }
  str[ii] = '\0'; // Definindo final da string
}

#endif