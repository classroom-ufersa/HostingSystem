#include "utils.h"

int main() {
    Sistema sistema;
    if(carregar_dados(&sistema, "dados.txt") == 2){
        inicializar_sistema(&sistema, sistema.num_quartos);
        atualizar_arquivo(&sistema, "dados.txt");
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
        //scanf("%d", &opcao);
        opcao = (int)scan_de_numeros();

        if (opcao == 1) {
            if(listar_quartos_disponiveis(sistema.quartos, sistema.num_quartos) > 0){
                Hospede hospede;
                printf("Digite o numero do quarto desejado: ");
                //scanf("%d", &hospede.quarto);
                hospede.quarto = (int)scan_de_numeros();
                while((verificar_disponibilidade(sistema.quartos, sistema.num_quartos, (int)hospede.quarto) != 1)){
                    printf("[AVISO] Digite o numero do quarto desejado dentre os disponiveis: ");
                    scanf("%d", &hospede.quarto);
                }
                printf("Digite o nome: ");
                scanf(" %[^\n]", hospede.nome);
                remover_caracteres_especiais(hospede.nome);
                printf("Digite a duracao da estadia: ");
                hospede.duracao_estadia = (int)scan_de_numeros();
                //scanf("%d", &hospede.duracao_estadia);
                printf("Digite o documento: ");
                scanf(" %[^\n]", hospede.documento);
                sistema.quartos[buscar_index_quarto(sistema.quartos, hospede.quarto, sistema.num_quartos)].disponibilidade = 0;
                adicionar_reserva(&sistema, hospede);
                atualizar_arquivo(&sistema, "dados.txt");
            }
            
        } else if (opcao == 2) {
            if(sistema.num_hospedes == 0){
                printf("[AVISO] Nao ha reservas, impossivel exclir!\n");
            } else {
                char documento[20];
                printf("Digite o documento: ");
                scanf(" %[^\n]", documento);
                excluir_reserva(&sistema, documento);
                atualizar_arquivo(&sistema, "dados.txt");
            }
            
        } else if (opcao == 3) {
            listar_reservas(&sistema);
        } else if (opcao == 4) {
            char documento[20];
            printf("Digite o documento: ");
            scanf(" %[^\n]", documento);

            Hospede hospede = buscar_reserva(&sistema, documento);
            if (strlen(hospede.nome) > 0) {
                printf("- Informacoes da reserva -\nNome: %s\nDuracao: %d dia(s)\nDocumento: %s\nNo quarto: %d\n", hospede.nome, hospede.duracao_estadia, hospede.documento, hospede.quarto);
            } else {
                printf("Reserva nao encontrada.\n");
            }
        } else if (opcao == 5) {
            char documento[20];
            printf("Digite o documento: ");
            scanf(" %[^\n]", documento);

            editar_reserva(&sistema, documento);
            atualizar_arquivo(&sistema, "dados.txt");
        } else if (opcao == 6) {
            listar_quartos_disponiveis(sistema.quartos, sistema.num_quartos);
        } else if (opcao == 7) {
            int quantitativo_hospedes = consultar_quantitativo_hospedes(&sistema);
            printf("Quantitativo de hospedes: %d\n", quantitativo_hospedes);
        }
    } while (opcao != 8);

    return 0;
}