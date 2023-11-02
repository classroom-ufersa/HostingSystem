# Sistema de Hospedagem

Este é um projeto de sistema de hospedagem em python para cadastrar hóspedes e manipular quartos.

## Funcionalidades

- Os quartos têm número/código, disponibilidade, preço e localização.
- Os hóspedes têm nome, documento e quarto.
- As reservas têm o documento do hospede da reserva, o quarto que ele esta hospedada, e a duração da estadia.
- O menu permite realizar reserva, excluir reserva, listar reservas, buscar reserva, editar reserva, consultar quartos disponíveis, consultar quantitativo de hóspedes e sair.
- A opção sair é a única que permite sair do programa. Após cada operação, o programa volta ao menu.
- A cada execução do programa, os dados são carregados de um arquivo de texto. Cada nova reserva cadastrada é inserida em ordem alfabética. O arquivo de texto é atualizado para refletir o estado atual dos dados em virtude da adição ou remoção.

## Como usar

Basta instalar o Python na sua maquina e executar o run.py.

## Desenvolvimento

Este projeto foi desenvolvido utilizando orientação a objetos e conceitos de bancos de dados.
