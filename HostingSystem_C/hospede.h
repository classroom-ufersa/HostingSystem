#ifndef HOSPEDE_H
#define HOSPEDE_H

typedef struct hospede Hospede;

// função para adicionar uma nova reserva
void adicionar_reserva(Hospede *hospedes, int *num_hospedes, Hospede hospede);

// função para excluir uma reserva existente
void excluir_reserva(Hospede *hospedes, int *num_hospedes, char *documento);

// função para listar todas as reservas
void listar_reservas(Hospede *hospedes, int num_hospedes);

// função para buscar uma reserva específica
Hospede buscar_reserva(Hospede *hospedes, int num_hospedes, char *documento);

// função para editar uma reserva existente
void editar_reserva(Hospede *hospedes, int num_hospedes, char *documento);

#endif