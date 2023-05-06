#include "sistema.c"

int main() {
    Sistema sistema;
    if(carregar_dados(&sistema, "dados.txt") == 2){
        inicializar_sistema(&sistema, sistema.num_quartos);
        atualizar_arquivo(&sistema, "dados.txt", 0);
    };
    int opcao;
    do {
        printf(" --- MENU ---\n");
        printf("1 - Realizar reserva\n");
        printf("2 - Excluir reserva\n");
        printf("3 - Listar reservas\n");
        printf("4 - Buscar reserva\n");
        printf("5 - Editar reserva\n");
        printf("6 - Consultar quartos disponiveis\n");
        printf("7 - Consultar quantitativo de hospedes\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");
        opcao = (int)scan_de_numeros();
        char documento[20];
        switch(opcao){
            case 1:
                if(listar_quartos_disponiveis(sistema.quartos, sistema.num_quartos) > 0){
                    Hospede hospede = criar_hospede(&sistema);
                    adicionar_reserva(&sistema, hospede);
                    atualizar_arquivo(&sistema, "dados.txt", 0);
                }
                break;
            case 2:
                if(sistema.num_hospedes == 0){
                    printf("[AVISO] Nao ha reservas, impossivel excluir!\n");
                } else {
                    printf("Digite o documento: ");
                    scanf(" %[^\n]", documento);
                    excluir_reserva(&sistema, documento);
                    atualizar_arquivo(&sistema, "dados.txt", 0);
                }
                break;
            case 3:
                if(sistema.num_hospedes == 0){
                    printf("[AVISO] Sem reservas cadastrados");
                    break;
                }
                listar_reservas(&sistema);
                break;
            case 4:
                if(sistema.num_hospedes == 0){
                    printf("[AVISO] Sem reservas cadastrados");
                    break;
                }
                printf("Digite o documento: ");
                scanf(" %[^\n]", documento);

                Hospede hospede = buscar_reserva(&sistema, documento);
                if (strlen(hospede.nome) > 0) {
                    printf("- Informacoes da reserva -\nNome: %s\nDuracao: %d dia(s)\nDocumento: %s\nNo quarto: %d\n", hospede.nome, hospede.duracao_estadia, hospede.documento, hospede.quarto);
                } else {
                    printf("Reserva nao encontrada.\n");
                }
                break;
            case 5:
                if(sistema.num_hospedes == 0){
                    printf("[AVISO] Sem reservas cadastrados");
                    break;
                }
                printf("Digite o documento: ");
                scanf(" %[^\n]", documento);
                if(editar_reserva(&sistema, documento)){
                    atualizar_arquivo(&sistema, "dados.txt", 1);
                }
                break;
            case 6:
                listar_quartos_disponiveis(sistema.quartos, sistema.num_quartos);
                break;
            case 7:
                printf("Quantitativo de hospedes: %d\n", consultar_quantitativo_hospedes(&sistema));
                break;
            default:
                break;
        }
    } while (opcao != 8);

    return 0;
}