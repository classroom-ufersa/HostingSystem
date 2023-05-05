#criando a classe reserva

class Reserva():
    def __init__(self, quarto, documento_hospede):
        self.quarto = quarto
        self.documento_hospede = documento_hospede

    def getQuarto(self):
        return(self.quarto)
    
    def setQuarto(self,quarto):
        self.quarto = quarto
    
    def getDocumento_hospede(self):
        return self.documento_hospede
    
    def setDocumento_hospede(self,documento_hospede):
        self.documento_hospede = documento_hospede

    #definindo property

    quarto = property(fget=getQuarto, fset= setQuarto)
    documento_hospede = property(fget= getDocumento_hospede, fset=setDocumento_hospede)
    