from models.reserva import Reserva
import sqlite3
class ReservaDAO():
    """
    classe usada como controlador de reservas
    """
    def __init__(self) -> None:
        self.db = sqlite3.connect("D:/Documents/UFERSA/cfiles/HostingSystem-1/HostingSystem_python/dbs/db.db")
        pass
    
    def cadastrar_reserva(self, reserva: Reserva):
        """funcao para cadastro de reserva

        Args:
            reserva (Reserva): um objeto do tipo reserva
        """
        sql = """
        insert into reserva
        (quarto_hospede,documento_hospede,duracao_estadia)
        values
        (?, ?, ?);
        """
  
        cursor = self.db.cursor()
        cursor.execute(sql, (
            reserva.quarto_hospedagem,
            reserva.documento_hospede,
            reserva.duracao_estadia
        )
        )
        self.db.commit()

        return cursor.lastrowid
    
    def listar_reservas(self):
        """
        funcao para listar as reservas
        """    
        sql = """
        select * from reserva;
        """

        cursor = self.db.cursor()
        cursor.execute(sql)

        return cursor.fetchall()
    
    def pesquisar_reserva(self, numero):
        """
        funcao de pesquisa de reservas

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        select * from reserva
        where quarto_hospede= ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (numero,))
        return cursor.fetchone()


    def excluir_reserva(self, numero):
        """
        funcao de exclusao de reservas

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        delete from reserva
        where quarto_hospede = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (numero))

        self.db.commit()

        return cursor.rowcount 
    
    def editar_reserva(self, numero,reserva: Reserva):
        """
        funcao de exclusao de reservas

        Args:
            numero (int): identificador do quarto
        """
        sql = """
        update reserva
        set quarto_hospede = ?, documento_hospede = ?, duracao_estadia = ?
        where quarto_hospede = ?;
        """

        cursor = self.db.cursor()
        cursor.execute(sql, (
            reserva.quarto_hospedagem,
            reserva.documento_hospede,
            reserva.duracao_estadia,
            numero
            )
        )

        self.db.commit()

        return cursor.rowcount