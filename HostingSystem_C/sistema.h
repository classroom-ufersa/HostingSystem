#ifndef SISTEMA_H
#define SISTEMA_H

//#include "quarto.h"
//#include "hospede.h"

typedef struct sistema Sistema;
typedef struct hospede Hospede;

// função para carregar os dados do arquivo de texto
int carregar_dados(Sistema *sistema, char *arquivo);

// função para atualizar o arquivo de texto com as alterações feitas no sistema
void atualizar_arquivo(Sistema *sistema, char *arquivo);

// função para criar e definir os quartos do hotel
void inicializar_sistema(Sistema *sistema, int num_quartos);

// função para adicionar uma nova reserva ao sistema
void adicionar_reserva(Sistema *sistema, Hospede hospede);

 // função para excluir uma reserva existente do sistema
void excluir_reserva(Sistema *sistema, char *documento);

// função para listar todas as reservas do sistema
void listar_reservas(Sistema *sistema);

// função para buscar uma reserva específica no sistema
Hospede buscar_reserva(Sistema *sistema, char *documento);

// função para editar uma reserva existente no sistema
void editar_reserva(Sistema *sistema, char *documento);

// função que retorna o quantitativo de hóspedes no sistema
int consultar_quantitativo_hospedes(Sistema *sistema);

#endif