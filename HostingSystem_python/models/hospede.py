
class Hospede():
    """
    classe usada de modelo de hospedes
    """
    def __init__(self, nome, documento) -> None:
        self.nome = nome
        self.documento = documento

        def getNome(self):
            return self.nome
        
        def setNome(self, nome):
            self.nome = nome
        
        def getDocumento(self):
            return self.documento
        
        def setDocumento(self, documento):
            self.documento = documento
        

        nome = property(fget=getNome, fset=setNome)
        documento = property(fget=getDocumento, fset=setDocumento)
        
        