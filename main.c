#include <stdio.h>
#include <stdlib.h>
#include "sistema.c"
#include "hospede.c"
#include "quarto.c"

int main() {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1- Realizar reserva\n");
        printf("2- Excluir reserva\n");
        printf("3- Listar reservas\n");
        printf("4- Buscar reserva\n");
        printf("5- Editar reserva\n");
        printf("6- Consultar quartos disponiveis\n");
        printf("7- Consultar quantitativo de hospedes\n");
        printf("8- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // Realizar reserva
                break;
            case 2:
                // Excluir reserva
                break;
            case 3:
                // Listar reservas
                break;
            case 4:
                // Buscar reserva
                break;
            case 5:
                // Editar reserva
                break;
            case 6:
                // Consultar quartos disponiveis
                break;
            case 7:
                // Consultar quantitativo de hospedes
                break;
            case 8:
                // Sair
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 8);

    return 0;
}