

class Hospede():
    """
    classe usada de modelo de hospedes
    """
    def __init__(self, nome, duracao_estadia, documento) -> None:
        self.nome = nome
        self.duracao_estadia = duracao_estadia
        self.documento = documento



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
        

        nome = property(fget=getNome, fset=setNome)
        duracao_estadia = property(fget=getDuracao_estadia, fset=setDuracao_estadia)
        documento = property(fget=getDocumento, fset=setDocumento)
        
        