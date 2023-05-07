from models.quarto import Quarto

class QuartoDAO():
    """
    classe usada de controlador para os quartos
    """
    def __init__(self, quarto: Quarto) -> None:
        pass
    
    def cadastrar_quarto(self, quarto: Quarto):
        """funcao para cadastro de quartos

        Args:
            quarto (Quarto): um objeto do tipo quarto
        """

        cadastro = f"{quarto.numero};{quarto.disponibilidade};{quarto.preco};{quarto.localizacao}\n" 
        db = open('HostingSystem_python/dbs/quartos.txt','a') 
        db.write(cadastro) 
        db.close() 
    
    def listar_quarto(self): 
        """
        funcao de listar quartos
        """
        db = open('HostingSystem_python/dbs/quartos.txt','r') 
        for i in db: 
            i= i.replace(';','\t')
            print(i)
        db.close()

    def pesquisar_quarto(self, numero):
        """
        funcao de pesquisa de quartos

        Args:
            numero (int): identificador do quarto
        """
        db = open('HostingSystem_python/dbs/quartos.txt','r')
        for i in db:
            if i[0] == numero:
                return(i)
        return("numero inválido/quarto não existente")
    