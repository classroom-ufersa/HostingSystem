from models.hospede import Hospede

class HospedeDao():
    def __init__(self, hospede: Hospede)

    def cadastrar_hospede(self, hospede: Hospede):
        """
        função para cadastrar um hospede
        args:
        hospede(Hospede)
        """
        cadastro = f"{hospede.nome};{hospede.duracao_estadia};{hospede.documento}\n" #pegando o aluno a ser cadastrado
        db = open('HostingSystem_python/dbs/hospedes.txt','a') #abrindo arquivo 
        db.write(cadastro) #cadastrando 
        db.close() #fechando
    
    def listar_hospede(self): #arrumar direitinho depois 
    """
    função para imprimir hospedes
    """
        db = open('HostingSystem_python/dbs/hospedes.txt','r') #abrindo o arquivo pra leitura
        for i in db: #for que vai passar por todo o arquivo e imprimir linha por linhas
            print(i)
        db.close()
    
    def pesquisar_hospede(self, documento):
        """
        Função para fazer a pesquisa de um hospede pelo documento
        args: 
        documento(int)
        return(retorna um hospede/uma mensagem de erro)
        """
        db = open('HostingSystem_python/dbs/hospedes.txt','r')
        for i in db:
            if i[2] == documento:
                return(i)
        return("Documento inválido/hospede não existente")

