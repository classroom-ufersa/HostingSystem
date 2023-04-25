#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"

struct sistema {
    Quarto *quartos;
    int num_quartos;
    Hospede *hospedes;
    int num_hospedes;
};

void carregar_dados(Sistema *sistema, char *arquivo) {
    // função para carregar os dados do arquivo de texto
}

void atualizar_arquivo(Sistema *sistema, char *arquivo) {
    // função para atualizar o arquivo de texto com as alterações feitas no sistema
}

void adicionar_reserva(Sistema *sistema, Hospede hospede) {
    // função para adicionar uma nova reserva ao sistema
}

void excluir_reserva(Sistema *sistema, char *documento) {
    // função para excluir uma reserva existente do sistema
}

void listar_reservas(Sistema *sistema) {
    // função para listar todas as reservas do sistema
}

Hospede buscar_reserva(Sistema *sistema, char *documento) {
    // função para buscar uma reserva específica no sistema
}

void editar_reserva(Sistema *sistema, char *documento) {
    // função para editar uma reserva existente no sistema
}

void consultar_quartos_disponiveis(Sistema *sistema) {
    // função para consultar os quartos disponíveis no sistema
}

int consultar_quantitativo_hospedes(Sistema *sistema) {
    // função para consultar o quantitativo de hóspedes no sistema
}