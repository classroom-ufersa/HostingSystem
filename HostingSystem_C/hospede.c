#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospede.h"

struct hospede {
    char nome[50];
    int duracao_estadia;
    char documento[20];
    int quarto;
};

void adicionar_reserva(Hospede *hospedes, int *num_hospedes, Hospede hospede) {
    // função para adicionar uma nova reserva
}

void excluir_reserva(Hospede *hospedes, int *num_hospedes, char *documento) {
    // função para excluir uma reserva existente
}

void listar_reservas(Hospede *hospedes, int num_hospedes) {
    // função para listar todas as reservas
}

Hospede buscar_reserva(Hospede *hospedes, int num_hospedes, char *documento) {
    // função para buscar uma reserva específica
}

void editar_reserva(Hospede *hospedes, int num_hospedes, char *documento) {
    // função para editar uma reserva existente
}