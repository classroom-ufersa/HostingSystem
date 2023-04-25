# Sistema de Hospedagem

Este é um projeto de sistema de hospedagem em C para cadastrar hóspedes e manipular quartos.

## Funcionalidades

- Os quartos têm número/código, disponibilidade, preço e localização.
- Os hóspedes têm nome, duração da estadia, documento e quarto.
- O menu permite realizar reserva, excluir reserva, listar reservas, buscar reserva, editar reserva, consultar quartos disponíveis, consultar quantitativo de hóspedes e sair.
- A opção sair é a única que permite sair do programa. Após cada operação, o programa volta ao menu.
- A cada execução do programa, os dados são carregados de um arquivo de texto. Cada nova reserva cadastrada é inserida em ordem alfabética. O arquivo de texto é atualizado para refletir o estado atual dos dados em virtude da adição ou remoção.

## Como usar

### Windows

1. Abra o Prompt de Comando e navegue até o diretório onde o código fonte está localizado.
2. Compile o código fonte com o comando `gcc main.c sistema.c quarto.c hospede.c -o sistema.exe`.
3. Execute o programa com o comando `sistema.exe`.
4. Siga as instruções na tela para utilizar as funcionalidades do sistema.

### Linux

1. Abra o Terminal e navegue até o diretório onde o código fonte está localizado.
2. Compile o código fonte com o comando `gcc main.c sistema.c quarto.c hospede.c -o sistema`.
3. Execute o programa com o comando `./sistema`.
4. Siga as instruções na tela para utilizar as funcionalidades do sistema.

## Desenvolvimento

Este projeto foi desenvolvido utilizando TADs (Tipos Abstratos de Dados) para representar os quartos e os hóspedes e para gerenciar o sistema de hospedagem como um todo.





