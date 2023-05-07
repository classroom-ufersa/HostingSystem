from models.hospede import Hospede

class HospedeDao():
    """
    classe usada para controlador de hospedes
    """
    def __init__(self, hospede: Hospede) -> None:
        pass

    def cadastrar_hospede(self, hospede: Hospede):
        """
        funcao para cadastrar um hospede
        args:
        hospede(Hospede): recebe um hospede
        """
        cadastro = f"{hospede.nome};{hospede.duracao_estadia};{hospede.documento}\n"
        db = open('HostingSystem_python/dbs/hospedes.txt','a')
        db.write(cadastro) 
        db.close() 
    
    def listar_hospede(self): #arrumar direitinho depois 
        """
        funcao de listar hospedes
        """
        db = open('HostingSystem_python/dbs/hospedes.txt','r') 
        for i in db: 
            i= i.replace(';','\t')
            print(i)
        db.close()
    
    def pesquisar_hospede(self, documento):
        """
        funcao de pesquisa de hospedes

        Args:
            documento (int): identificador do hospede
        """
        db = open('HostingSystem_python/dbs/hospedes.txt','r')
        for i in db:
            if i[2] == documento:
                return(i)
        return("Documento inválido/hospede não existente")

