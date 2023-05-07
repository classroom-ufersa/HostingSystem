from models.hospede import Hospede  
from models.quarto import Quarto
from models.reserva import Reserva

from controllers.hospedeDAO import HospedeDao
from controllers.quartoDAO import QuartoDAO
from controllers.reservaDAO import ReservaDAO

def main():
        while True:
            try:
                print(" --- MENU ---\n"
                "1 - Realizar reserva\n"
                "2 - Excluir reserva\n"
                "3 - Listar reservas\n"
                "4 - Buscar reserva\n"
                "5 - Editar reserva\n"
                "6 - Consultar quartos disponiveis\n"
                "7 - Consultar quantitativo de hospedes\n"
                "8 - Sair\n")
                
                op = input('Escolha uma opção: ')
                
                op = int(op)

                if op == 8:
                    print('Saindo do sistema!')
                    break

            except EOFError:
                break
