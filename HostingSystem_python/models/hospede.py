#criando o modelo de hospede

class Hospede():
    def __init__(self, nome, duracao_estadia, documento, quarto) -> None:
        self.nome = nome
        self.duracao_estadia = duracao_estadia
        self.documento = documento
        self.quarto = quarto

        #definindo gets e sets

        def getNome(self):
            return self.nome
        
        def setNome(self, nome):
            self.nome = nome
        
        def getDuracao_estadia(self):
            return self.duracao_estadia
        
        def setDuracao_estadia(self, duracao_estadia):
            self.duracao_estadia = duracao_estadia
        
        def getDocumento(self):
            return self.documento
        
        def setDocumento(self, documento):
            self.documento = documento
        
        def getquarto(self):
            return self.quarto
        
        def setQuarto(self,quarto):
            self.quarto = quarto

        #encapsulando
        nome = property(fget=getNome, fset=setNome)
        duracao_estadia = property(fget=getDuracao_estadia, fset=setDuracao_estadia)
        documento = property(fget=getDocumento, fset=setDocumento)
        quarto = property(fget=getquarto, fset=setQuarto)
        