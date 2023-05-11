#ifndef SISTEMA_H
#define SISTEMA_H

//#include "hospede.h"

// tipo estruturado Sistema
typedef struct sistema Sistema;


// função para carregar os dados do arquivo de texto
int carregar_dados(Sistema *sistema, char *arquivo);

// função para atualizar o arquivo de texto com as alterações feitas no sistema
void atualizar_arquivo(Sistema *sistema, char *arquivo, int edited);

// função para criar e definir os quartos do hotel
void inicializar_sistema(Sistema *sistema, int num_quartos);


#endif