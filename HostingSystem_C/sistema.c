#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"
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
};

int carregar_dados(Sistema *sistema, char *arquivo) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return 0;
    }
    int first_run = 0;
    fscanf(fp, "%d;%d\n", &sistema->num_quartos, &first_run);
    printf("fr: %d\n", first_run);
    if(first_run == 0){
        int new_nq = 0;
        printf("[AVISO] Primeira execucao do sistema ou arquivo de dados corrompido!\n");
        printf("Em caso de primeira execucao, digite o numero de quartos a cadastrar: ");
        scanf("%d", &new_nq);
        sistema->num_quartos = new_nq;
        return 2;
    };

    sistema->quartos = (Quarto *)malloc(sistema->num_quartos * sizeof(Quarto));
    int i;
    for (i = 0; i < sistema->num_quartos; i++) {
        fscanf(fp, "%d;%d;%f;%[^\n]\n", &sistema->quartos[i].numero, &sistema->quartos[i].disponibilidade, &sistema->quartos[i].preco, sistema->quartos[i].localizacao);
    }

    fscanf(fp, "%d\n", &sistema->num_hospedes);
    sistema->hospedes = (Hospede *)malloc(sistema->num_hospedes * sizeof(Hospede));
    for (int i = 0; i < sistema->num_hospedes; i++) {
        fscanf(fp, " %[^;];%d;%[^;];%d\n", sistema->hospedes[i].nome, &sistema->hospedes[i].duracao_estadia, sistema->hospedes[i].documento, &sistema->hospedes[i].quarto);
    }

    fclose(fp);
    return 1;
}

void atualizar_arquivo(Sistema *sistema, char *arquivo) {
    FILE *fp = fopen(arquivo, "w");
    int i;
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    fprintf(fp, "%d;%d\n", sistema->num_quartos, 1);
    for (i = 0; i < sistema->num_quartos; i++) {
        fprintf(fp, "%d;%d;%.2f;%s\n", sistema->quartos[i].numero, sistema->quartos[i].disponibilidade, sistema->quartos[i].preco, sistema->quartos[i].localizacao);
    }

    fprintf(fp, "%d\n", sistema->num_hospedes);
    for (i = 0; i < sistema->num_hospedes; i++) {
        int ii = 0;
        while(sistema->hospedes[i].nome[ii]) {
            sistema->hospedes[i].nome[ii] = toupper(sistema->hospedes[i].nome[ii]);
            ii++;
        }
        fprintf(fp, "%s;%d;%s;%d\n", sistema->hospedes[i].nome, sistema->hospedes[i].duracao_estadia, sistema->hospedes[i].documento, sistema->hospedes[i].quarto);
    }

    fclose(fp);
}

void inicializar_sistema(Sistema *sistema, int num_quartos) {
    sistema->quartos = (Quarto *)malloc(sistema->num_quartos * sizeof(Quarto));
    int i;
    for (i = 0; i < num_quartos; i++){
        sistema->quartos[i].disponibilidade = 1;
        printf("Digite o numero do %do quarto a ser criado: ", i+1);
        scanf("%d", &sistema->quartos[i].numero);
        printf("Digite a localizacao do %do quarto: ", i+1);
        scanf(" %[^\n]", sistema->quartos[i].localizacao);
        printf("Digite o preço da reserva do %do quarto: R$ ", i+1);
        scanf("%f", &sistema->quartos[i].preco);
        }
    sistema->num_hospedes = 0;

}

void adicionar_reserva(Sistema *sistema, Hospede hospede) {
    if(sistema->num_hospedes >= sistema->num_quartos){
        printf("[AVISO] Todos os quartos do hotel estao reservados!\n");
        return;
    }
    
    int posicao_inserir = 0, i;
    while (posicao_inserir < sistema->num_hospedes && strcmp(sistema->hospedes[posicao_inserir].nome, hospede.nome) < 0) {
        posicao_inserir++;
    }

    sistema->hospedes = (Hospede *)realloc(sistema->hospedes, (sistema->num_hospedes + 1) * sizeof(Hospede));
    for (i = sistema->num_hospedes; i > posicao_inserir; i--) {
        memcpy(&sistema->hospedes[i], &sistema->hospedes[i - 1], sizeof(Hospede));
    }
    memcpy(&sistema->hospedes[posicao_inserir], &hospede, sizeof(Hospede));
    sistema->num_hospedes++;
}


void excluir_reserva(Sistema *sistema, char *documento) {
    int posicao_excluir = -1, i;
    for (i = 0; i < sistema->num_hospedes; i++) {
        if (strcmp(sistema->hospedes[i].documento, documento) == 0) {
            posicao_excluir = i;
            break;
        }
    }

    if (posicao_excluir == -1) {
        printf("Reserva não encontrada.\n");
        return;
    }
    int qrt = buscar_index_quarto(sistema->quartos, sistema->hospedes[i].quarto ,sistema->num_quartos);
    //printf("Index quarto teste: %d\n", qrt); 
    //sistema->hospedes[i].quarto
    char resp = 'n';
    printf("Excluir hospede '%s'? (s/n): ", sistema->hospedes[posicao_excluir].nome);
    scanf(" %c", &resp);
    if(resp == 's'){
        for (i = posicao_excluir; i < sistema->num_hospedes - 1; i++) {
            memcpy(&sistema->hospedes[i], &sistema->hospedes[i + 1], sizeof(Hospede));
        }
        sistema->num_hospedes--;
        sistema->hospedes = (Hospede *) realloc(sistema->hospedes, sistema->num_hospedes * sizeof(Hospede));
        sistema->quartos[qrt].disponibilidade = 1;
        printf("Hospede excluido com sucesso!\n\n");
    } else printf("[AVISO] Processo ignorado.\n");
   
}


void listar_reservas(Sistema *sistema) {
    if(sistema->num_hospedes == 0){
        printf("Sem reservas cadastrados");
        return;
    }
    int i;
    printf("- Reservas cadastradas -");
    for (i = 0; i < sistema->num_hospedes; i++) {
        printf("\nNome: %s\nDuracao: %d dia(s)\nDocumento: %s\nNo quarto: %d\n", sistema->hospedes[i].nome, sistema->hospedes[i].duracao_estadia, sistema->hospedes[i].documento, sistema->hospedes[i].quarto);
    }
}

Hospede buscar_reserva(Sistema *sistema, char *documento) {
    for (int i = 0; i < sistema->num_hospedes; i++) {
        if (strcmp(sistema->hospedes[i].documento, documento) == 0) {
            return sistema->hospedes[i];
        }
    }

    Hospede hospede_vazio;
    memset(&hospede_vazio, 0, sizeof(Hospede));
    return hospede_vazio;
}

void editar_reserva(Sistema *sistema, char *documento) {
    int posicao_editar = -1, i;
    for (i = 0; i < sistema->num_hospedes; i++) {
        if (strcmp(sistema->hospedes[i].documento, documento) == 0) {
            posicao_editar = i;
            break;
        }
    }

    if (posicao_editar == -1) {
        printf("Reserva não encontrada.\n");
        return;
    }
    //adicionar_reserva
    printf("- Nome atual: %s\nDigite o novo nome: ", sistema->hospedes[posicao_editar].nome);
    scanf(" %[^\n]", sistema->hospedes[posicao_editar].nome);
    printf("- Duracao atual: %d\nDigite a nova duração da estadia: ", sistema->hospedes[posicao_editar].duracao_estadia);
    scanf("%d", &sistema->hospedes[posicao_editar].duracao_estadia);
    printf("- Documento atual: %s\nDigite o novo documento: ", sistema->hospedes[posicao_editar].documento);
    scanf(" %[^\n]", sistema->hospedes[posicao_editar].documento);
    int new_n;
    do{
        printf("- Quarto atual: %d\nDigite o numero do novo quarto: ", sistema->hospedes[posicao_editar].quarto);
        scanf("%d", &new_n);
        //new_n = (int)scan_de_numeros();
        if(new_n == sistema->hospedes[posicao_editar].quarto){
            break;
        }
    } while(verificar_disponibilidade(sistema->quartos, sistema->num_quartos, new_n) > 0);
    sistema->hospedes[posicao_editar].quarto = new_n;
    
}

int consultar_quantitativo_hospedes(Sistema *sistema) {
    return sistema->num_hospedes;
}

