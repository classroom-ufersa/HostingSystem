#include "utils.h"
#include "sistema.h"
#include "quarto.c"
#include "hospede.h"

struct sistema {
    Quarto *quartos;
    int num_quartos;
    Hospede *hospedes;
    int num_hospedes;
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