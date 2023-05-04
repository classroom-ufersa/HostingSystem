#criando o modelo de quarto

class Quarto():
    def __init__(self, numero, disponibilidade, preco, localizacao) -> None:
        self.numero = numero
        self.disponibilidade = disponibilidade
        self.preco = preco
        self.localizacao = localizacao

        #funcoes gets e sets
        def getNumero(self):
            return self.numero
        
        def setNumero(self, numero):
            self.numero = numero
        
        def getDisponibilidade(self):
            return self.disponibilidade
        
        def setDisponibilidade(self, disponibilidade):
            self.disponibilidade = disponibilidade
        
        def getPreco(self):
            return self.preco
        
        def setPreco(self, preco):
            self.preco = preco
        
        def getLocalizacao(self):
            return self.localizacao
        
        def setLocalizacao(self,localizacao):
            self.localizacao = localizacao

        #encapsulando
        numero = property(fget=getNumero, fset=setNumero)
        disponibilidade = property(fget=getDisponibilidade, fset=setDisponibilidade)
        preco = property(fget=getPreco, fset=setPreco)
        localizacao = property(fget=getLocalizacao, fset=setLocalizacao)
