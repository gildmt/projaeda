#include "Menus.h"


int verfica_fich(string fich_veri, string tipo_fich){

	ifstream ficheiro;

	//Verificar ficheiro

	cout << "\nIntroduza o nome do ficheiro de " << tipo_fich << "(ou control+z para sair): ";


	while (true){
		try{
			if (!getline(cin, fich_veri)){
				return 1;                          //control+z logo sai
			} 
			ficheiro.open(fich_veri);
			if (ficheiro)
			{
				string tipo_fich_teste;                          //verfica 1 linha ficheiro
				getline(ficheiro, tipo_fich_teste, ':');
				if (tipo_fich_teste != tipo_fich)
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
	//if (verfica_fich(fichOrdensVenda, "Ordens de Venda"))
	//	return 1;
	//if (verfica_fich(fichOrdensCompra, "Ordens de Compra"))
	//	return 1;
	
	clearScreen(); //limpa ecra
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
	cout << TAB << "4 - Consultar transações efetuadas por clientes." << endl;
	cout << TAB << "5 - Consultar transações efetuadas por título." << endl;
	cout << TAB << "6 - Consultar transações efetuadas num dia." << endl;
	cout << TAB << "7 - Consultar transações efetuadas entre 2 datas." << endl;
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
		case 4: bolsa_de_valores.listar_transacoes_cli();
			break;
		case 5:  bolsa_de_valores.listar_transacoes_titulo();
			break;
		case 6: bolsa_de_valores.listar_transacoes_dia();
			break;
		case 7: bolsa_de_valores.listar_transacoes_intervalo_de_tempo();
			break;
	}

}




/*  Apagar???



unsigned short int menuGestaoClientes(){
	int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Gestao Clientes" << endl;
	cout << endl;
	cout << TAB << "1 - Listar clientes" << endl;
	cout << TAB << "2 - Ver informacao cliente" << endl;
	cout << TAB << "3 - Criar cliente" << endl;                                    //faltava criar cliente!!!
	cout << TAB << "4 - Editar cliente" << endl;
	cout << TAB << "5 - Remover cliente" << endl;
	cout << TAB << "6 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 6);

	if (opcao == 6)
		return 0;

	return opcao;
}


void opcoesGestaoClientes(VendeMaisMais & supermercado){
	unsigned int opcao;
	string nome;

	while ((opcao = menuGestaoClientes()))
		switch (opcao){
		case 1: supermercado.listarClientesOrdemAlfa();
			break;
		case 2: cout << "Qual o nome do cliente: ";
			getline(cin, nome);
			supermercado.mostraInformacaoCliente(nome);
			break;
		case 3: supermercado.criar_cliente();
			break;
		case 4: supermercado.editar_cliente();
			break;
		case 5: supermercado.remover_cliente();
			break;
	}
}


unsigned short int menuGestaoTransacoes(){
	int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Gestao Transacoes" << endl;
	cout << endl;
	cout << TAB << "1 - Listar por ordem cronologica as transacoes de um cliente" << endl;
	cout << TAB << "2 - Listar todas as transacoes num dia" << endl;
	cout << TAB << "3 - Listar todas as transacoes num intervalo de tempo" << endl;
	cout << TAB << "4 - Listar todas as transacoes" << endl;
	cout << TAB << "5 - Adicionar transacoes" << endl;
	cout << TAB << "6 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 6);

	if (opcao == 6)
		return 0;

	return opcao;
}

void opcoesGestaoTransacoes(VendeMaisMais & supermercado){
	unsigned int opcao;

	while ((opcao = menuGestaoTransacoes()))
		switch (opcao){
		case 1: supermercado.listar_Transacoes_Cliente();
			break;
		case 2:supermercado.listar_Transacoes_dia();
			break;
		case 3:supermercado.listar_Transacoes_intervalo_de_tempo();
			break;
		case 4: supermercado.listar_Transacoes();
			break;
		case 5:supermercado.adiciona_transacao();
			break;
	}
}


unsigned short int menuRecomendacao(){
	int opcao;

	clearScreen();
	cout << TAB_BIG << "Menu Gestao Transacoes" << endl;
	cout << endl;
	cout << TAB << "1 - Recomendar um cliente" << endl;
	cout << TAB << "2 - Campanha Bottom 10" << endl;
	cout << TAB << "3 - Voltar ao menu inicial" << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 3);

	if (opcao == 3)
		return 0;

	return opcao;
}

void opcoesRecomendacao(VendeMaisMais & supermercado){
	unsigned int opcao;

	while ((opcao = menuRecomendacao()))
		switch (opcao){
		case 1: recomendar(supermercado);
			break;
		case 2: bottom10(supermercado);
			break;

	}

}
*/