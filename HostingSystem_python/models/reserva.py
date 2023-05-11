#criando a classe reserva

class Reserva():
    """
    classe modelo para reservas
    """
    def __init__(self, quarto_hospedagem, documento_hospede,duracao_estadia)-> None:
        self.quarto_hospedagem = quarto_hospedagem
        self.documento_hospede = documento_hospede
        self.duracao_estadia = duracao_estadia
         
        def getQuarto_hospedagem(self):
            return(self.quarto_hospedagem)
        
        def setQuarto_hospedagem(self,quarto_hospedagem):
            self.quarto_hospedagem = quarto_hospedagem
        
        def getDocumento_hospede(self):
            return self.documento_hospede
        
        def setDocumento_hospede(self,documento_hospede):
            self.documento_hospede = documento_hospede
        
        def getDuracao_estadia(self):
            return self.duracao_estadia
        
        def setDuracao_estadia(self, duracao_estadia):
            self.duracao_estadia = duracao_estadia
        
        duracao_estadia = property(fget=getDuracao_estadia, fset=setDuracao_estadia)
        quarto_hospedagem = property(fget=getQuarto_hospedagem, fset=setQuarto_hospedagem)
        documento_hospede = property(fget= getDocumento_hospede, fset=setDocumento_hospede)
        