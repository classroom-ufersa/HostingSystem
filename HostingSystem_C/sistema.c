#include "utils.h"
#include "sistema.h"
#include "quarto.c"

//#define MAX_QUARTOS 10;

struct sistema {
    Quarto *quartos;
    int num_quartos;
    Hospede *hospedes;
    int num_hospedes;
};

struct hospede { 
    char nome[50]; 
    int duracao_estadia; 
    char documento[20]; 
    int quarto; 
    Hospede *proximo; 
};

int carregar_dados(Sistema *sistema, char *arquivo) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return 0;
    }
    int first_run = 0;
    fscanf(fp, "%d;%d\n", &sistema->num_quartos, &first_run);
    if(first_run == 0){
        int new_nq = 0;
        printf("[AVISO] Primeira execucao do sistema ou arquivo de dados corrompido!\n");
        printf("Em caso de primeira execucao, digite o numero de quartos a cadastrar: ");
        new_nq = (int)scan_de_numeros();
        sistema->num_quartos = new_nq;
        return 2;
    }
    sistema->quartos = (Quarto *)malloc(sistema->num_quartos * sizeof(Quarto));
    int i;
    for (i = 0; i < sistema->num_quartos; i++) {
        fscanf(fp, "%d;%d;%f;%[^\n]\n", &sistema->quartos[i].numero, &sistema->quartos[i].disponibilidade, &sistema->quartos[i].preco, sistema->quartos[i].localizacao);
    }
    fscanf(fp, "%d\n", &sistema->num_hospedes);
    sistema->hospedes = NULL;
    Hospede *ultimo_hospede = NULL;
    for (int i = 0; i < sistema->num_hospedes; i++) {
        Hospede *novo_hospede = (Hospede*) malloc(sizeof(Hospede));
        fscanf(fp, " %[^;];%d;%[^;];%d\n", novo_hospede->nome, &novo_hospede->duracao_estadia, novo_hospede->documento, &novo_hospede->quarto);
        novo_hospede->proximo = NULL;
        if (sistema->hospedes == NULL) {
            sistema->hospedes = novo_hospede;
        } else {
            ultimo_hospede->proximo = novo_hospede;
        }
        ultimo_hospede = novo_hospede;
    }
    fclose(fp);
    return 1;
}

void atualizar_arquivo(Sistema *sistema, char *arquivo, int edited) { 
    FILE *fp = fopen(arquivo, "w"); 
    int i; 
    if (fp == NULL) { 
        printf("Erro ao abrir o arquivo %s\n", arquivo); 
        return; 
    } 
    if(edited) ordenar_hospedes(sistema);
    
    fprintf(fp, "%d;%d\n", sistema->num_quartos, 1); 
    for (i = 0; i < sistema->num_quartos; i++) { 
        fprintf(fp, "%d;%d;%.2f;%s\n", sistema->quartos[i].numero, sistema->quartos[i].disponibilidade, sistema->quartos[i].preco, sistema->quartos[i].localizacao); 
    } 
    fprintf(fp, "%d\n", sistema->num_hospedes); 
    Hospede *atual = sistema->hospedes; 
    while (atual != NULL) { 
        int ii = 0; 
        while(atual->nome[ii]) { 
            atual->nome[ii] = toupper(atual->nome[ii]); ii++; 
        } 
        fprintf(fp, "%s;%d;%s;%d\n", atual->nome, atual->duracao_estadia, atual->documento, atual->quarto); 
        atual = atual->proximo; 
    } 
    fclose(fp); 
}

void inicializar_sistema(Sistema *sistema, int num_quartos) {
    sistema->quartos = (Quarto *)malloc(sistema->num_quartos * sizeof(Quarto));
    int i;
    for (i = 0; i < num_quartos; i++){
        sistema->quartos[i].disponibilidade = 1;
        printf("Digite o numero do %do quarto a ser criado: ", i+1);
        sistema->quartos[i].numero = (int)scan_de_numeros();
        printf("Digite a localizacao do %do quarto: ", i+1);
        scanf(" %[^\n]", sistema->quartos[i].localizacao);
        printf("Digite o preço da reserva do %do quarto: R$ ", i+1);
        sistema->quartos[i].preco = scan_de_numeros();
        }
    sistema->num_hospedes = 0;

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
    Hospede *atual = sistema->hospedes; 
    Hospede *anterior = NULL; 
    while (atual != NULL && strcmp(atual->documento, documento) != 0) { 
        anterior = atual; atual = atual->proximo; 
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
    while (atual != NULL) {
        if (strcmp(atual->documento, documento) == 0) {
            return *atual;
        }
        atual = atual->proximo;
    }

    Hospede hospede_vazio;
    memset(&hospede_vazio, 0, sizeof(Hospede));
    return hospede_vazio;
}


Hospede criar_hospede(Sistema *sistema){
    Hospede hospede;
    printf("Digite o numero do quarto desejado: ");
    hospede.quarto = (int)scan_de_numeros();
    while((verificar_disponibilidade(sistema->quartos, sistema->num_quartos, (int)hospede.quarto) != 1)){
        printf("[AVISO] Digite o numero do quarto desejado dentre os disponiveis: ");
        scanf("%d", &hospede.quarto);
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

int editar_reserva(Sistema *sistema, char *documento) { 
    Hospede *atual = sistema->hospedes; 
    Hospede *anterior = NULL; 
    int ii;
    while (atual != NULL && strcmp(atual->documento, documento) != 0) { 
        anterior = atual; 
        atual = atual->proximo; 
    } 
    if (atual == NULL) { 
        printf("[AVISO] Reserva não encontrada.\n"); 
        return -1; 
    } 
    printf("- Nome atual: %s\nDigite o novo nome: ", atual->nome); 
    scanf(" %[^\n]", atual->nome); 
    remover_caracteres_especiais(atual->nome);
    while(atual->nome[ii]) { 
            atual->nome[ii] = toupper(atual->nome[ii]); ii++; 
        } 
    printf("- Duracao atual: %d\nDigite a nova duração da estadia: ", atual->duracao_estadia); 
    scanf("%d", &atual->duracao_estadia); 
    printf("- Documento atual: %s\nDigite o novo documento: ", atual->documento); 
    scanf(" %[^\n]", atual->documento); 
    int new_n; 
    printf("- Quarto atual: %d\nDigite o numero do novo quarto: ", atual->quarto); 
    scanf("%d", &new_n); 
    while(verificar_disponibilidade(sistema->quartos, sistema->num_quartos, new_n) <= 0){ 
        if(new_n == atual->quarto){ 
            atual->quarto = new_n; 
            printf("[AVISO] Reserva editada com sucesso!\n"); 
            return 1; 
        } 
        printf("[AVISO] Quarto indisponivel, digite o numero de um quarto disponivel ou o numero do quarto atual.\n"); 
        listar_quartos_disponiveis(sistema->quartos, sistema->num_quartos); 
        printf("Escolha um quarto: "); 
        scanf("%d", &new_n); 
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