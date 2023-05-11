#ifndef HOSPEDE_H
#define HOSPEDE_H

// definição do tipo estruturado do sistema
typedef struct sistema Sistema;

// tipo estruturado Hospede
typedef struct hospede Hospede;

struct hospede { 
    char nome[50]; 
    int duracao_estadia; 
    char documento[20]; 
    int quarto; 
    Hospede *proximo; 
};

//função para criar um novo hospede
Hospede criar_hospede(Sistema *sistema);

// função para adicionar uma nova reserva ao sistema
void adicionar_reserva(Sistema *sistema, Hospede hospede);

// função para excluir uma reserva existente do sistema
void excluir_reserva(Sistema *sistema, char *documento);

// função para listar todas as reservas do sistema
void listar_reservas(Sistema *sistema);

// função para buscar uma reserva específica no sistema
Hospede buscar_reserva(Sistema *sistema, char *documento);

// função para editar uma reserva existente no sistema
int editar_reserva(Sistema *sistema, char *documento);

// função que retorna o quantitativo de hóspedes no sistema
int consultar_quantitativo_hospedes(Sistema *sistema);

// função para ordenar os hospedes em ordem alfabetica
void ordenar_hospedes(Sistema *sistema);

#endif