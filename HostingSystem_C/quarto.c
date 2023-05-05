#include <stdio.h>
#include <stdlib.h>
#include "quarto.h"

struct quarto {
    int numero;
    int disponibilidade;
    float preco;
    char localizacao[50];
};

int verificar_disponibilidade(Quarto *quartos, int num_quartos, int numero) {
    for (int i = 0; i < num_quartos; i++) {
        if (quartos[i].numero == numero) {
            return quartos[i].disponibilidade;
        }
    }

    return -1;
}

void alterar_preco(Quarto *quartos, int num_quartos, int numero, float novo_preco) {
    for (int i = 0; i < num_quartos; i++) {
        if (quartos[i].numero == numero) {
            quartos[i].preco = novo_preco;
            break;
        }
    }
}

int listar_quartos_disponiveis(Quarto *quartos, int num_quartos) {
    int i, disponiveis = 0;
    for (i = 0; i < num_quartos; i++) {
        if (quartos[i].disponibilidade == 1) {
            disponiveis++;
        }
    }
    if(disponiveis >0){
        printf("- Lista de quartos disponiveis -\n");
        for (i = 0; i < num_quartos; i++) {
            if (quartos[i].disponibilidade == 1) {
                printf("Numero: %d\nPreco: R$ %.2f\nLocal: %s\n", quartos[i].numero, quartos[i].preco, quartos[i].localizacao);
            }
        }
    } else printf("[AVISO] Sem quartos disponiveis!\n");
    
    return disponiveis;
}

int buscar_index_quarto(Quarto *quartos, int num_quarto, int num_quartos) {
    int i;
    for (i = 0; i < num_quartos; i++) {
        if (quartos[i].numero == num_quarto) {
            return i;
        }
    }
    printf("[ERRO] Nao foi possivel achar o quarto %d", num_quarto);
    return -1;
}