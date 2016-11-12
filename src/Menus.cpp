/*
* Menus.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Menus.h"


int verfica_fich(string & fich_veri, string tipo_fich){

	fstream ficheiro;

	//Verificar ficheiro

	cout << "\nIntroduza o nome do ficheiro de " << tipo_fich << "(ou control+z para sair): ";



	while (true){
		try{
			if (!getline(cin, fich_veri)){
				return 1;                          //control+z logo sai
			}
			acabatxt(fich_veri);
			ficheiro.open(fich_veri);
			if (ficheiro)
			{
				bool fichVazio = fich_vazio(ficheiro);
				string tipo_fich_teste;                          //verfica 1 linha ficheiro
				getline(ficheiro, tipo_fich_teste, ':');
				if (tipo_fich_teste != tipo_fich || !fichVazio)  // aceita ficheiros vazio 
				{
					ficheiro.close();
					throw FicheiroInvalido(tipo_fich);      
					
				}

				ficheiro.close();
				break;
			}
			else throw FicheiroInexistente(tipo_fich);
		}
		catch (FicheiroInexistente fich_inex){
			
			cout << fich_inex;
			break;
		}
		catch (FicheiroInvalido fich_inva){
			cout << fich_inva;
		}
	}
	return 0;
}


int infoInicial(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){

	ifstream ficheiro;
	string tipo_fich;
	

	if (verfica_fich(fichClientes, "Clientes"))
		return 1;
	if (verfica_fich(fichTransacoes, "Transacoes"))
		return 1;
	if (verfica_fich(fichOrdensVenda, "Ordens de Venda"))
		return 1;
	if (verfica_fich(fichOrdensCompra, "Ordens de Compra"))
		return 1;
	
	espera_input();

		clearScreen(); //limpa ecra
		return 0;
}



/******************************************
 * Menu Inicial
 ******************************************/
unsigned short int menuInicial(){
	int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Inicial" << endl;
	cout << endl;
	cout << TAB << "1 - Adicionar Ordem de Compra." << endl;
	cout << TAB << "2 - Adicionar Ordem de Venda." << endl;
	cout << TAB << "3 - Adicionar Cliente" << endl;
	cout << TAB << "4 - Consultar Transacoes." << endl;
	cout << TAB << "5 - Consultar Ordens de compra." << endl;
	cout << TAB << "6 - Consultar Ordens de venda." << endl;
	cout << TAB << "7 - Consultar Lista de Clientes." << endl;
	cout << TAB << "8 - Sair do programa" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 8);

	if (opcao == 8)
		return 0;

	return opcao;
}

void opcoesIniciais(Bolsa & bolsa_de_valores){
	unsigned int opcao;


	while ((opcao = menuInicial()))
		switch (opcao){
		case 1:  bolsa_de_valores.ad_ordem_compra();
			break;
		case 2: bolsa_de_valores.ad_ordem_venda();
			break;
		case 3: bolsa_de_valores.ad_cli();
			break;
		case 4: menuTransacoes(bolsa_de_valores);
			break;
		case 5:  bolsa_de_valores.listar_ordensCompra();
			break;
		case 6: bolsa_de_valores.listar_ordensVenda();
			break;
		case 7: bolsa_de_valores.listar_clientes();
			break;
	}

}

void menuTransacoes(Bolsa & bolsa_de_valores){
	int opcao;

	cout << endl;
	cout << TAB << "1 - Consultar Transacoes efetuadas por clientes." << endl;
	cout << TAB << "2 - Consultar Transacoes efetuadas por titulo." << endl;
	cout << TAB << "3 - Consultar Transacoes efetuadas por data." << endl;
	cout << TAB << "4 - Voltar ao menu inicial." << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 4);

	if (opcao == 4)
		return;
	
	switch (opcao) {
	case 1: bolsa_de_valores.listar_transacoes_cli();
		break;
	case 2:  bolsa_de_valores.listar_transacoes_titulo();
		break;
	case 3: bolsa_de_valores.listar_transacoes_intervalo_de_tempo();
		break;
	}
}