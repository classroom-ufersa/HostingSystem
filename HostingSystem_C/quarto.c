#include <stdio.h>
#include <stdlib.h>
#include "quarto.h"

typedef struct quarto {
    int numero;
    int disponibilidade;
    float preco;
    char localizacao[50];
};

int verificar_disponibilidade(Quarto *quartos, int num_quartos, int numero) {
    // função para verificar a disponibilidade de um quarto específico
}

void alterar_preco(Quarto *quartos, int num_quartos, int numero, float novo_preco) {
    // função para alterar o preço de um quarto específico
}

void listar_quartos_disponiveis(Quarto *quartos, int num_quartos) {
    // função para listar todos os quartos disponíveis
}