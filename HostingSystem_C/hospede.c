#include "hospede.h"
#include "sistema.h"

struct hospede { 
    char nome[50]; 
    int duracao_estadia; 
    char documento[20]; 
    int quarto; 
    Hospede *proximo; 
};

Hospede criar_hospede(Sistema *sistema){
    Hospede hospede;
    printf("Digite o numero do quarto desejado: ");
    hospede.quarto = (int)scan_de_numeros();
    while((verificar_disponibilidade(sistema->quartos, sistema->num_quartos, (int)hospede.quarto) != 1)){
        printf("[AVISO] Digite o numero do quarto desejado dentre os disponiveis: ");
        hospede.quarto = (int)scan_de_numeros();
    }
    printf("Digite o nome: ");
    scanf(" %[^\n]", hospede.nome);
    remover_caracteres_especiais(hospede.nome);
    int ii = 0; 
    while(hospede.nome[ii]) { 
        hospede.nome[ii] = toupper(hospede.nome[ii]); ii++; 
    }
    printf("Digite a duracao da estadia: ");
    hospede.duracao_estadia = (int)scan_de_numeros();
    printf("Digite o documento: ");
    scanf(" %[^\n]", hospede.documento);
    sistema->quartos[buscar_index_quarto(sistema->quartos, hospede.quarto, sistema->num_quartos)].disponibilidade = 0;
    return hospede;
}

void adicionar_reserva(Sistema *sistema, Hospede hospede) { 
    Hospede *novo_hospede = (Hospede *)malloc(sizeof(Hospede)); 
    *novo_hospede = hospede; 
    novo_hospede->proximo = NULL; 
    if (sistema->hospedes == NULL) { 
        sistema->hospedes = novo_hospede; 
    } else { 
        Hospede *atual = sistema->hospedes; 
        Hospede *anterior = NULL; 
        while (atual != NULL && strcmp(atual->nome, novo_hospede->nome) < 0) { 
            anterior = atual; atual = atual->proximo; 
        } 
        if (anterior == NULL) { 
            novo_hospede->proximo = sistema->hospedes; 
            sistema->hospedes = novo_hospede; 
        } else { 
            novo_hospede->proximo = atual; 
            anterior->proximo = novo_hospede; 
        } 
    } 
    sistema->num_hospedes++; 
} 

void excluir_reserva(Sistema *sistema, char *documento) { 
    Hospede hospede_a_excluir = buscar_reserva(sistema, documento);
    
    if (hospede_a_excluir.nome[0] == '\0') {
        printf("Reserva não encontrada.\n"); 
        return; 
    }
    
    Hospede *atual = sistema->hospedes;
    Hospede *anterior = NULL;
    while (atual != NULL && atual->quarto != hospede_a_excluir.quarto) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("Reserva não encontrada.\n"); 
        return; 
    }
    
    if (anterior == NULL) { 
        sistema->hospedes = atual->proximo; 
    } else { 
        anterior->proximo = atual->proximo; 
    } 
    int qrt = buscar_index_quarto(sistema->quartos, atual->quarto, sistema->num_quartos); 
    sistema->quartos[qrt].disponibilidade = 1; 
    free(atual); 
    sistema->num_hospedes--; 
    printf("Hospede excluido com sucesso!\n\n"); 
} 

void listar_reservas(Sistema *sistema) {
    Hospede *atual = sistema->hospedes;
    printf("- Reservas cadastradas -");

    while (atual != NULL) {
        printf("\nNome: %s\nDuracao: %d dia(s)\nDocumento: %s\nNo quarto: %d\n", atual->nome, atual->duracao_estadia, atual->documento, atual->quarto);
        atual = atual->proximo;
    }
}

Hospede buscar_reserva(Sistema *sistema, char *documento) {
    Hospede *atual = sistema->hospedes;
    Hospede *hospedes_com_mesmo_documento = NULL;
    int num_hospedes_com_mesmo_documento = 0;
    
    while (atual != NULL) {
        if (strcmp(atual->documento, documento) == 0) {
            num_hospedes_com_mesmo_documento++;
            hospedes_com_mesmo_documento = realloc(hospedes_com_mesmo_documento, num_hospedes_com_mesmo_documento * sizeof(Hospede));
            hospedes_com_mesmo_documento[num_hospedes_com_mesmo_documento - 1] = *atual;
        }
        atual = atual->proximo;
    }
    
    if (num_hospedes_com_mesmo_documento == 0) {
        Hospede hospede_vazio;
        memset(&hospede_vazio, 0, sizeof(Hospede));
        return hospede_vazio;
    }
    
    if (num_hospedes_com_mesmo_documento > 1) {
        printf("Foram encontrados %d hospedes com o mesmo documento. Qual deles você deseja selecionar?\n", num_hospedes_com_mesmo_documento);
        for (int i = 0; i < num_hospedes_com_mesmo_documento; i++) {
            printf("%d - %s\nNo quarto: %d\n", i + 1, hospedes_com_mesmo_documento[i].nome, hospedes_com_mesmo_documento[i].quarto);
        }
        int opcao;
        opcao = (int)scan_de_numeros();
        while (opcao < 1 || opcao > num_hospedes_com_mesmo_documento) {
            printf("Opção inválida. Digite novamente: ");
            opcao = (int)scan_de_numeros();
        }
        Hospede hospede_selecionado = hospedes_com_mesmo_documento[opcao - 1];
        free(hospedes_com_mesmo_documento);
        return hospede_selecionado;
        
    } else {
        Hospede hospede_encontrado = hospedes_com_mesmo_documento[0];
        free(hospedes_com_mesmo_documento);
        return hospede_encontrado;
    }
}


int editar_reserva(Sistema *sistema, char *documento) { 
    Hospede hospede_a_editar = buscar_reserva(sistema, documento);
    
    if (hospede_a_editar.nome[0] == '\0') {
        printf("[AVISO] Reserva não encontrada.\n"); 
        return -1; 
    }
    
    Hospede *atual = sistema->hospedes;
    while (atual != NULL && atual->quarto != hospede_a_editar.quarto) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("[AVISO] Reserva não encontrada.\n"); 
        return -1; 
    }
    
    printf("- Nome atual: %s\nDigite o novo nome: ", atual->nome); 
    scanf(" %[^\n]", atual->nome); 
    remover_caracteres_especiais(atual->nome);
    int ii = 0; 
    while(atual->nome[ii]) { 
        atual->nome[ii] = toupper(atual->nome[ii]); 
        ii++; 
    } 
    printf("- Duracao atual: %d\nDigite a nova duração da estadia: ", atual->duracao_estadia); 
    atual->duracao_estadia = (int)scan_de_numeros();
    printf("- Documento atual: %s\nDigite o novo documento: ", atual->documento); 
    scanf(" %[^\n]", atual->documento); 
    int new_n; 
    printf("- Quarto atual: %d\nDigite o numero do novo quarto: ", atual->quarto); 
    new_n = (int)scan_de_numeros();
    while(verificar_disponibilidade(sistema->quartos, sistema->num_quartos, new_n) <= 0){ 
        if(new_n == atual->quarto){ 
            atual->quarto = new_n; 
            printf("[AVISO] Reserva editada com sucesso!\n"); 
            return 1; 
        } 
        printf("[AVISO] Quarto indisponivel, digite o numero de um quarto disponivel ou o numero do quarto atual.\n"); 
        listar_quartos_disponiveis(sistema->quartos, sistema->num_quartos); 
        printf("Escolha um quarto: "); 
        new_n = (int)scan_de_numeros();
    } 
    int index_anterior = buscar_index_quarto(sistema->quartos, atual->quarto, sistema->num_quartos); 
    sistema->quartos[index_anterior].disponibilidade = 1; 
    atual->quarto = new_n; 
    int index_atual = buscar_index_quarto(sistema->quartos, atual->quarto, sistema->num_quartos); 
    sistema->quartos[index_atual].disponibilidade = 0; 
    return 1; 
}

int consultar_quantitativo_hospedes(Sistema *sistema) {
    return sistema->num_hospedes;
}

void ordenar_hospedes(Sistema *sistema) {
    Hospede *atual, *proximo;
    Hospede temp;

    if (sistema->hospedes == NULL) {
        return;
    }

    for (atual = sistema->hospedes; atual != NULL; atual = atual->proximo) {
        for (proximo = atual->proximo; proximo != NULL; proximo = proximo->proximo) {
            if (strcmp(atual->nome, proximo->nome) > 0) {
                temp = *atual;
                *atual = *proximo;
                *proximo = temp;
                Hospede *tempProximo = atual->proximo;
                atual->proximo = proximo->proximo;
                proximo->proximo = tempProximo;
            }
        }
    }
}