from models.reserva import Reserva

class ReservaDAO():
    """
    classe usada como controlador de reservas
    """
    def __init__(self, reserva: Reserva) -> None:
        pass
    
    def cadastrar_reserva(self, reserva: Reserva):
        """funcao para cadastro de reserva

        Args:
            reserva (Reserva): um objeto do tipo reserva
        """

        cadastro = f"{reserva.numero};{reserva.documento_hospede}\n" 
        db = open('HostingSystem_python/dbs/reservas.txt','a') 
        db.write(cadastro) 
        db.close() 
    
    def listar_reservas(self):
        """
        funcao para listar as reservas
        """    
        db = open('HostingSystem_python/dbs/reservas.txt','a') 
        for i in db: 
            i= i.replace(';','\t')
            print(i)
        db.close()
    
    def pesquisar_quarto(self, numero):
        """
        funcao de pesquisa de reservas

        Args:
            numero (int): identificador do quarto
        """
        db = open('HostingSystem_python/dbs/reservas.txt','r')
        for i in db:
            if i[0] == numero:
                return(i)
        return("reserva inválida/quarto não reservado/existente")


