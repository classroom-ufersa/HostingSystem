from models.hospede import Hospede
import sqlite3
class HospedeDao():
    """
    classe usada para controlador de hospedes
    """
    def __init__(self) -> None:
        self.db = sqlite3.connect("HostingSystem_python\dbs\db.db")
        pass

    def cadastrar_hospede(self, hospede: Hospede):
        """
        funcao para cadastrar um hospede
        args:
        hospede(Hospede): recebe um hospede
        """
        sql = """
        insert into hospede
        (nome,documento)
        values
        (?, ?);
        """
  
        cursor = self.db.cursor()
        cursor.execute(sql, (
            hospede.nome,
            hospede.documento
        )
        )
        self.db.commit()

        return cursor.lastrowid
    
    def listar_hospede(self): #arrumar direitinho depois 
        """
        funcao de listar hospedes
        """
        sql = """
        select * from hospede;
        """

        cursor = self.db.cursor()
        cursor.execute(sql)

        return cursor.fetchall()
    
    def pesquisar_hospede(self, documento):
        """
        funcao de pesquisa de hospedes

        Args:
            documento (int): identificador do hospede
        """
        sql = """
        select * from hospede
        where documento = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (documento,))
        return cursor.fetchone()

