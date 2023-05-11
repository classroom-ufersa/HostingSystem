from models.hospede import Hospede  
from models.quarto import Quarto
from models.reserva import Reserva

from controllers.hospedeDAO import HospedeDao
from controllers.quartoDAO import QuartoDAO
from controllers.reservaDAO import ReservaDAO

def main():
        while True:
            quartodao = QuartoDAO()
            reservadao = ReservaDAO()
            hospededao = HospedeDao()
            try:
                print(" --- MENU ---\n"
                "1 - Realizar reserva\n"
                "2 - Excluir reserva\n"
                "3 - Listar reservas\n"
                "4 - Buscar reserva\n"
                "5 - Editar reserva\n"
                "6 - Consultar quartos disponiveis\n"
                "7 - Consultar quantitativo de hospedes\n"
                "Adm - Digite o código de administrador para acessar as funções de adm\n"
                "8 - Sair\n")
                
                op = input('Escolha uma opção: ')
                if op.isdigit() == False:
                    print("Digite apenas numeros!")
                else:
                    op = int(op)
                    if op == 1:
                        nome = input("Digite o seu nome: ")
                        documento = input("Digite seu documento: ")
                        estadia = input("Quantos dias de estadia: ")
                        if documento.isdigit() == True and estadia.isdigit() == True:

                            disp = quartodao.listar_quarto_disponivel()
                            print('----Quartos disponiveis----')
                            for i in disp:                   
                                print(f'Quarto {i[1]}, preço = {i[3]}R$')

                            quarto_reserva = input('Digite o número do quarto para a reserva: ')
                            
                            if quarto_reserva.isdigit() == False:
                                print('Digite apenas valores numericos')
                            else:
                                veri_quarto = quartodao.pesquisar_quarto(quarto_reserva)
                                
                                if  veri_quarto!=None and int(veri_quarto[2] ) == 1:
                                    hospede = Hospede(nome = nome,documento= documento)
                                    hospededao.cadastrar_hospede(hospede=hospede)
                                    reserva = Reserva(quarto_hospedagem=quarto_reserva, documento_hospede=documento, duracao_estadia = estadia)
                                    reservadao.cadastrar_reserva(reserva=reserva)
                                    quarto_editado = Quarto(numero = veri_quarto[1], disponibilidade = 0,preco=veri_quarto[3], localizacao=veri_quarto[4] )
                                    quartodao.editar_quarto(quarto_reserva,quarto_editado)
                                    print("Reserva cadastrada com sucesso!")

                                else:
                                    print('Quarto indiponivel/Não existente!')
    

                            
                        else:
                            print("Digite apenas valores válidos e numéricos!")

                    elif op == 2:
                        reserva_excluida = input("Qual quarto voce deseja excluir a reserva: ")
                        if reserva_excluida.isdigit() == True:
                        
                            veri_quarto_ex = quartodao.pesquisar_quarto(reserva_excluida)
                            if veri_quarto_ex!= None and veri_quarto_ex[2] == 0:
                                reservadao.excluir_reserva(numero=reserva_excluida)
                                quarto_editado = Quarto(numero = veri_quarto_ex[1], disponibilidade = 1,preco=veri_quarto_ex[3], localizacao=veri_quarto_ex[4])
                                quartodao.editar_quarto(reserva_excluida,quarto_editado)
                                print("Reserva excluida!")
                            else:
                                print("Quarto disponivel/inexistente!")

                        else:
                            print("Digite apenas valores numéricos! ")    

                    elif op == 3:
                        listar_reservas = reservadao.listar_reservas()
                        
                        print('----Reservas cadastradas----')
                        for i in listar_reservas:
                            print(f'Quarto: {i[1]} | Documento do Hospede: {i[2]} | Duração: {i[3]}')
                    
                    elif op == 4:
                        reserva_busca = input("Qual quarto voce deseja buscar a reserva: ")
                        if reserva_busca.isdigit() == True:
                            busca_reserva = reservadao.pesquisar_reserva(reserva_busca)
                            if busca_reserva != None:
                                print(f'Resultado da busca: quarto {busca_reserva[1]}, documento: {busca_reserva[2]}, duração: {busca_reserva[3]}')
                            else:
                                print("Reserva não encontrada!")
                        else:
                            print("Digite apenas valores numéricos! ")

                    elif op == 5:
                        quarto = input('Qual o quarto que deseja editar a estadia: ')
                        if quarto.isdigit() == True:
                            quarto = int(quarto)
                            pesq_reserva = reservadao.pesquisar_reserva(quarto)
                            pesq_quarto = quartodao.pesquisar_quarto(quarto)
                            if pesq_quarto!=None:
                                
                                edit_quarto= input('Para qual quarto gostaria de mudar sua estadia: ')
                                edit_tempo = input('Para quantos dias deseja alterar sua estadia: ')
                                
                                if edit_quarto.isdigit() == True and edit_tempo.isdigit() == True:
                                    
                                    edit_quarto = int(edit_quarto)
                                    edit_tempo = int(edit_tempo)
                                    pesq_quarto2 = quartodao.pesquisar_quarto(edit_quarto)
                                    
                                    if pesq_reserva!=None and pesq_quarto2 != None and pesq_quarto2[2] == 1:
                                        reserva_edit= Reserva(documento_hospede = pesq_reserva[2], quarto_hospedagem=edit_quarto, duracao_estadia=edit_tempo)
                                        reservadao.editar_reserva(quarto,reserva_edit)
                                        print("Reserva editada com sucesso!")
                                        edit1 = Quarto(numero = pesq_quarto2[1],disponibilidade=0, preco = pesq_quarto2[3], localizacao=pesq_quarto2[4])
                                        quartodao.editar_quarto(numero=edit_quarto, quarto=edit1)
                                        edit2 = Quarto(numero = pesq_quarto[1],disponibilidade=1, preco = pesq_quarto[3], localizacao=pesq_quarto[4])
                                        quartodao.editar_quarto(numero=quarto, quarto=edit2 )
                                    else:
                                        print('Quarto não encontrado ou não disponivel!')

                                else:
                                    print('Reserva não encontrada')        
                            else:
                                print('Digite apenas valores numéricos!')
                        else:
                                print('Digite apenas valores numéricos!')
                    elif op == 6:
                        disp = quartodao.listar_quarto_disponivel()
                        print('----Quartos disponiveis----')
                        for i in disp:                   
                            print(f'Quarto {i[1]}, preço = {i[3]}R$')
                    elif op == 7:
                        qtd_hospedes =reservadao.listar_reservas()

                        print('A quantidade de hospedes com reservas é:',len(qtd_hospedes))

                    elif op == 8:
                        print('Saindo do sistema!')
                        break

                    elif op == 123:
                        print(" --- MENU ---\n"
                        "1 - Cadastrar quarto\n"
                        "2 - Excluir quarto\n"
                        "3 - Listar quartos\n"
                        "4 - Buscar quarto\n"
                        "5 - Editar quarto\n"
                        "6 - sair\n")
                        opadm= input('Digite sua opção: ')

                        if opadm.isdigit() == False:
                            print("Digite apenas uma opção numérica!")
                        else:
                            opadm= int(opadm)
                            if opadm == 1:
                                numero_qrt = input("Digite o numero do quarto: ")
                                preco = input("Digite o preco do quarto: ")
                                localizacao = input("Digite a localizacao do quarto: ")
                                
                                if numero_qrt.isdigit() ==True and preco.isdigit()==True:
                                    cadastro_quarto = Quarto(numero=numero_qrt, disponibilidade=1, preco= preco, localizacao= localizacao)
                                    quartodao.cadastrar_quarto(cadastro_quarto)
                            elif opadm == 2:
                                numero_adm_ex = input('Digite o numero do quarto q ser excluido: ')
                                pesq_quarto_adm_ex = quartodao.pesquisar_quarto(numero=numero_adm_ex)
                                if pesq_quarto_adm_ex != None:
                                    if pesq_quarto_adm_ex[2]== 1:
                                        quartodao.excluir_quarto(numero=numero_adm_ex)
                                        print('Quarto excluido!')
                                    else:
                                        print('Não se pode apagar um quarto ocupado!')
                                else:
                                    print('Quarto não encontrado!')
                            elif opadm == 3:
                                listar_quarto = quartodao.listar_quarto()                        
                                print('----Quartos cadastrados----')
                                for i in listar_quarto:
                                    print(f'Quarto: {i[1]} | Disponibilidade: {i[2]} | Preco: {i[3]}R$ | Localização: {i[4]}')
                                
                            elif opadm ==4:
                                numero_qrt_busc = input("Digite o numero do quarto: ")
                                if numero_qrt_busc.isdigit()==True:
                                    numero_qrt_busc= int(numero_qrt_busc)
                                    numero_qrt_busc = quartodao.pesquisar_quarto(numero_qrt_busc)     
                                    if numero_qrt_busc != None:
                                        print(f'Quarto: {numero_qrt_busc[1]} | Disponibilidade: {numero_qrt_busc[2]} | Preco: {numero_qrt_busc[3]}R$ | Localização: {numero_qrt_busc[4]}')
                                    else:
                                        print('Quarto não encontrado!')
                                else:
                                    print('Digite apenas valores númericos!')
                            elif opadm == 5:
                                numero_qrt_edit = input("Digite o numero do quarto: ")
                                if numero_qrt_edit.isdigit() ==True:
                                    numero_qrt_edit = int(numero_qrt_edit)
                                    pesq_quarto_edit = quartodao.pesquisar_quarto(numero_qrt_edit)
                                    if pesq_quarto_edit != None:
                                        numero_edit = input("Digite o novo numero do quarto: ")
                                        preco_edit = input("Digite o novo preco do quarto: ")
                                        localizacao_edit = input("Digite a nova localizacao do quarto: ")
                                        disponibilidade = input('Digite a nova disponibilidade do quarto (0 ou 1) : ')
                                        
                                        if numero_edit.isdigit() == True and preco_edit.isdigit()==True and int(disponibilidade) == (0 or 1) :
                                            quartoedit = Quarto(numero=numero_edit, disponibilidade=disponibilidade, preco= preco_edit, localizacao= localizacao_edit)
                                            quartodao.editar_quarto(numero=numero_qrt_edit, quarto=quartoedit)
                                            print('Quarto editado!')
                                        else:
                                            print('Parametros inválidos!')
                                    else:
                                        print('Quarto não encontrado!')
                                else:
                                    print('Digite apenas valores númericos!')
                            elif opadm==6:
                                pass
                            else:
                                print('Opção inválida!')
                                pass
                    else:       
                        print('Digite uma opção valida!')

            except EOFError:
                break
