#ifndef QUARTO_H
#define QUARTO_H

typedef struct quarto Quarto;

// função para verificar a disponibilidade de um quarto específico
int verificar_disponibilidade(Quarto *quartos, int num_quartos, int numero);

// função para alterar o preço de um quarto específico
void alterar_preco(Quarto *quartos, int num_quartos, int numero, float novo_preco);

// função para consultar os quartos disponíveis no sistema que retorna a quantidade
int listar_quartos_disponiveis(Quarto *quartos, int num_quartos);

int buscar_index_quarto(Quarto *quartos, int num_quarto, int num_quartos);

#endif