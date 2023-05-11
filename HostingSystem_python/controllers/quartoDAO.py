from models.quarto import Quarto
import sqlite3

class QuartoDAO():
    """
    classe usada de controlador para os quartos
    """
    def __init__(self) -> None:
        self.db = sqlite3.connect("/Users/gusti/Documents/codigos/Trabalhos/host_system/HostingSystem_python/dbs/db.db")
        pass
    
    def cadastrar_quarto(self, quarto: Quarto):
        """funcao para cadastro de quartos

        Args:
            quarto (Quarto): um objeto do tipo quarto
        """
        sql = """
        insert into quarto
        (numero,disponibilidade,preco,localizacao)
        values
        (?, ?, ?, ?);
        """
  
        cursor = self.db.cursor()
        cursor.execute(sql, (
            quarto.numero,
            quarto.disponibilidade,
            quarto.preco,
            quarto.localizacao
        )
        )
        self.db.commit()

        return cursor.lastrowid 
    
    def listar_quarto(self): 
        """
        funcao de listar quartos
        """
        sql = """
        select * from quarto;
        """

        cursor = self.db.cursor()
        cursor.execute(sql)

        return cursor.fetchall()

    def pesquisar_quarto(self, numero):
        """
        funcao de pesquisa de quartos

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        select * from quarto
        where numero = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (numero,))
        return cursor.fetchone()
    

    def listar_quarto_disponivel(self): 
        """
        funcao de listar quartos disponiveis
        """
        sql = """
        select * from quarto
        where disponibilidade = 1 ;
        """

        cursor = self.db.cursor()
        cursor.execute(sql)

        return cursor.fetchall()
   
    
    def editar_quarto(self, numero,quarto:Quarto):
        """
        funcao de exclusao de quartos

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        update quarto
        set numero = ?, disponibilidade = ?, preco = ?, localizacao = ?
        where numero = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (
            quarto.numero,
            quarto.disponibilidade,
            quarto.preco,
            quarto.localizacao,
            numero
            )
        )

        self.db.commit()

        return cursor.rowcount
    
    def excluir_quarto(self, numero):
        """
        funcao de exclusao de quartos

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        delete from quarto
        where numero = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (numero,))

        self.db.commit()

        return cursor.rowcount 