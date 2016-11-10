/*
* OrdemVenda.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/


#include "Bolsa.h"
#include "insertionSort.h"


const vector<Cliente>& Bolsa::getClientes() const {
	return clientes;
}

void Bolsa::setClientes(const vector<Cliente>& clientes) {
	this->clientes = clientes;
}

const vector<OrdemCompra>& Bolsa::getOrdensCompra() const {
	return ordensCompra;
}

void Bolsa::setOrdensCompra(const vector<OrdemCompra>& ordensCompra) {
	this->ordensCompra = ordensCompra;
}

const vector<OrdemVenda>& Bolsa::getOrdensVenda() const {
	return ordensVenda;
}

void Bolsa::setOrdensVenda(const vector<OrdemVenda>& ordensVenda) {
	this->ordensVenda = ordensVenda;
}




void Bolsa::le_ficheiros_cli(string & fichClientes){
	string aux;
	int num_cli;
	ifstream f_clientes;

	f_clientes.open(fichClientes);
	getline(f_clientes, aux, ':');  //retira Clientes, nao interesasa
	f_clientes >> num_cli; f_clientes.ignore(); //retira num de iteracoes
	
	
	for (int i = 0; i < num_cli; i++)
	{
		Cliente cliente_lido(f_clientes);
		clientes.push_back(cliente_lido);
	}

	f_clientes.close();
}

void Bolsa::le_ficheiros_tran(string & fichTransacoes){
	string aux;
	int num_tran;
	ifstream f_transacoes;

	f_transacoes.open(fichTransacoes);
	getline(f_transacoes, aux, ':');  //retira "Transacoes", nao interesasa
	f_transacoes >> num_tran; f_transacoes.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_tran; i++)
	{
		Transacao transacao_lida(f_transacoes);
		transacoes.push_back(transacao_lida);
	}

	f_transacoes.close();

}
void Bolsa::le_ficheiros_ordv(string & fichOrdensVenda){
	string aux;
	int num_ov;
	ifstream f_OrdensVenda;

	f_OrdensVenda.open(fichOrdensVenda);
	getline(f_OrdensVenda, aux, ':');  //retira "Ordens de Venda", nao interesasa
	f_OrdensVenda >> num_ov; f_OrdensVenda.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_ov; i++)
	{
		string titulo_aux, data_str;
		float preco_acao_aux;
		int num_acoes_aux;
		long nif_aux;


		//le ficheiro
		f_OrdensVenda >> nif_aux;
		f_OrdensVenda.ignore(3); //anda 3 espaco
		getline(f_OrdensVenda, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
		f_OrdensVenda.ignore(); //anda 1 espaco
		getline(f_OrdensVenda, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
		f_OrdensVenda >> preco_acao_aux;
		f_OrdensVenda.ignore(3); //anda 3 espaco
		f_OrdensVenda >> num_acoes_aux;

		
	
		OrdemVenda ordemVenda_lida(titulo_aux, Data(data_str), nif_aux, num_acoes_aux, preco_acao_aux);
		ordensVenda.push_back(ordemVenda_lida);
	}

	f_OrdensVenda.close();
}
void Bolsa::le_ficheiros_ordc(string & fichOrdensCompra){
	string aux;
	int num_oc;
	ifstream f_OrdensCompra;

	f_OrdensCompra.open(fichOrdensCompra);
	getline(f_OrdensCompra, aux, ':');  //retira "Ordens de Compra", nao interesasa
	f_OrdensCompra >> num_oc; f_OrdensCompra.ignore(); //retira num de iteracoes


	for (int i = 0; i < num_oc; i++)
	{
		string titulo_aux, data_str;
		float preco_acao_aux;
		float valorMaxGastar_aux;
		long nif_aux;


		//le ficheiro
		f_OrdensCompra >> nif_aux;
		f_OrdensCompra.ignore(3); //anda 3 espaco
		getline(f_OrdensCompra, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
		f_OrdensCompra.ignore(); //anda 1 espaco
		getline(f_OrdensCompra, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
		f_OrdensCompra >> preco_acao_aux;
		f_OrdensCompra.ignore(3); //anda 3 espaco
		f_OrdensCompra >> valorMaxGastar_aux;


	OrdemCompra ordemCompra_lida(titulo_aux, Data(data_str), nif_aux, preco_acao_aux, valorMaxGastar_aux);
		ordensCompra.push_back(ordemCompra_lida);
	}
	f_OrdensCompra.close();
}


void Bolsa::le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){
	le_ficheiros_cli(fichClientes);
	le_ficheiros_tran(fichTransacoes);
	le_ficheiros_ordv(fichOrdensVenda);
	le_ficheiros_ordc(fichOrdensCompra);
}

void Bolsa::guarda_alteracoes(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){

}


void Bolsa::ad_ordem_compra(){
	string titulo;
	long nif;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();
	
	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif()) {
			cout << TAB << "Titulo da acao: ";
			titulo = leTitulo();

			if (titulo.empty()) {
				espera_input();
				return;
			}
			
			float pMax, vMaxGastar;
			cout << TAB << "Preco maximo por acao: ";
			pMax = le_float();
			
			cout << TAB << "Valor Maximo a Gastar: ";
			vMaxGastar = le_float();

			Data data = getData();

			for (size_t j = 0; j < ordensVenda.size(); j++) {
				if (ordensVenda.at(j).getTitulo() == titulo) {
					if (ordensVenda.at(j).getPrecoMin() <= pMax) {
						if (ordensVenda.at(j).getPrecoMin() * ordensVenda.at(j).getQuantidade() <= vMaxGastar) {
							Transacao t(titulo, ordensVenda.at(j).getPrecoMin(), ordensVenda.at(j).getQuantidade(), data, ordensVenda.at(i).getNif(), clientes.at(i).getNif());
							transacoes.push_back(t);
							vMaxGastar = vMaxGastar - ordensVenda.at(j).getPrecoMin() * ordensVenda.at(j).getQuantidade();
							cout << TAB << "Comprou " << ordensVenda.at(j).getQuantidade() << " acoes a " << ordensVenda.at(j).getPrecoMin() << " euros cada uma." << endl;
							ordensVenda.erase(ordensVenda.begin() + j);
							espera_input();
						}
						else if (ordensVenda.at(j).getPrecoMin() * ordensVenda.at(j).getQuantidade() > vMaxGastar) {
							int nQuantidade = floor(vMaxGastar / ordensVenda.at(j).getPrecoMin() + 0.5);
							Transacao t(titulo, ordensVenda.at(j).getPrecoMin(), nQuantidade, data, ordensVenda.at(i).getNif(), clientes.at(i).getNif());
							transacoes.push_back(t);
							OrdemVenda actualizada(titulo, ordensVenda.at(j).getData(), ordensVenda.at(j).getNif(), ordensVenda.at(j).getQuantidade() - nQuantidade, ordensVenda.at(j).getPrecoMin());
							ordensVenda.push_back(actualizada);
							cout << TAB << "Comprou " << nQuantidade << " acoes a " << ordensVenda.at(j).getPrecoMin() << " euros cada uma." << endl;
							ordensVenda.erase(ordensVenda.begin() + j);		
							espera_input();
							return;
						}
					}
				}
			}

			if (vMaxGastar == 0)
				return;

			OrdemCompra oc(titulo, data, nif, pMax, vMaxGastar);
			ordensCompra.push_back(oc);
			cout << TAB << "Nenhuma ordem de venda compativel encontrada, ordem de compra listada." << endl;
			espera_input();
			return;
		}
	}
	cout << TAB << "Nao existe um cliente com esse NIF (adicione cliente)\n";
	espera_input();
	return;
}

void Bolsa::ad_ordem_venda(){
	string titulo;
	long nif;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i < clientes.size(); i++) {
		if (nif == clientes.at(i).getNif()) {
			cout << TAB << "Titulo da acao: ";
			titulo = leTitulo();

			if (titulo.empty()) {
				espera_input();
				return;
			}

			float pMin;
			int qtd;
			cout << TAB << "Preco minimo por acao: ";
			pMin = le_float();

			cout << TAB << "Quantidade de acoes: ";
			qtd = leInteiro(0, 999999);

			Data data = getData();

			for (size_t j = 0; j < ordensCompra.size(); j++) {
				if (ordensCompra.at(j).getTitulo() == titulo) {
					if (ordensCompra.at(j).getPrecoMax() >= pMin) {
						if (pMin * qtd <= ordensCompra.at(j).getValorMaxGastar()) {
							Transacao t(titulo, pMin, qtd, data, clientes.at(i).getNif(), ordensCompra.at(j).getNif());
							transacoes.push_back(t);
							OrdemCompra actualizada(titulo, ordensCompra.at(j).getData(), ordensCompra.at(j).getNif(), ordensCompra.at(j).getPrecoMax(), ordensCompra.at(j).getValorMaxGastar() - qtd * pMin);
							ordensCompra.push_back(actualizada);
							cout << TAB << "Vendeu " << qtd << " acoes a " << pMin << " euros cada uma." << endl;
							ordensCompra.erase(ordensCompra.begin() + j);
							espera_input();
							return;
						}
						else if (pMin * qtd > ordensCompra.at(j).getValorMaxGastar()) {
							int nQuantidade = floor(ordensCompra.at(j).getValorMaxGastar() / pMin + 0.5);
							Transacao t(titulo, pMin, nQuantidade, data, clientes.at(i).getNif(), ordensCompra.at(j).getNif());
							transacoes.push_back(t);
							cout << TAB << "Vendeu " << nQuantidade << " acoes a " << pMin << " euros cada uma." << endl;
							ordensCompra.erase(ordensCompra.begin() + j);
							qtd = qtd - nQuantidade;
							espera_input();
						}
					}
				}
			}

			if (qtd == 0)
				return;

			OrdemVenda ov(titulo, data, nif, qtd, pMin);
			ordensVenda.push_back(ov);
			cout << TAB << "Nenhuma ordem de compra compativel encontrada, ordem de venda listada." << endl;
			espera_input();
			return;
		}
	}
	cout << TAB << "Nao existe um cliente com esse NIF (adicione cliente)\n";
	espera_input();
	return;
}

void Bolsa::ad_cli(){
	string nome;
	long nif;

	cout << endl << endl;
	cout << TAB << "Nome do cliente: ";
	nome = leTitulo();

	if (nome.empty()) {
		espera_input();
		return;
	}

	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	for (size_t i = 0; i<clientes.size(); i++)
		if (nif == clientes.at(i).getNif())
		{
			cout << TAB << "Ja existe um cliente com esse NIF\n";
			espera_input();
			return;
		}

		clientes.push_back(Cliente(nome, nif));
}

void Bolsa::listar_transacoes_cli(){
	long nif;

	cout << endl << endl;
	cout << TAB << "NIF do cliente: ";
	nif = leNif();

	if (nif == -1) {
		espera_input();
		return;
	}

	int primeiro_cli = -1;
	for (size_t i = 0; i < transacoes.size(); i++)
		if (nif == transacoes.at(i).getCliente_v() || nif == transacoes.at(i).getCliente_c()) {
			primeiro_cli = i;
			break;
		}

	if (primeiro_cli == -1){
		cout << "\nNenhum cliente com esse NIF fez transacoes.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha();
	cout << TAB << left << BARRA
		<< setw(11) << " Comprador " << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco medio " << BARRA
		<< setw(14) << " Numero acoes" << BARRA
		<< endl;
	linha();

	for (size_t i = primeiro_cli; i < transacoes.size(); i++)
		if (nif == transacoes.at(i).getCliente_v() || nif == transacoes.at(i).getCliente_c())
			cout << transacoes.at(i);

	linha();
	cout << endl << endl;

	espera_input();
}

void Bolsa::listar_transacoes_titulo(){
	string titulo;

	cout << endl << endl;
	cout << TAB << "Titulo da transacao: ";
	titulo = leTitulo();
	
	if (titulo.empty()) {
		espera_input();
		return;
	}
	
	int primeiro_cli = -1;
	for (size_t i = 0; i < transacoes.size(); i++)
		if (titulo == transacoes.at(i).getTitulo()) {
			primeiro_cli = i;
			break;
		}

	if (primeiro_cli == -1) {
		cout << "\nNenhuma transacao com esse titulo.\n\n";
		espera_input();
		return;
	}

	clearScreen();
	cout << endl;
	linha();
	cout << TAB << left << BARRA
		<< setw(11) << " Comprador " << BARRA
		<< setw(11) << " Vendedor " << BARRA
		<< setw(12) << " Data" << BARRA
		<< setw(15) << " Titulo" << BARRA
		<< setw(14) << " Preco medio " << BARRA
		<< setw(14) << " Numero acoes" << BARRA
		<< endl;
	linha();

	for (size_t i = primeiro_cli; i < transacoes.size(); i++)
		if (titulo == transacoes.at(i).getTitulo())
			cout << transacoes.at(i);

	linha();
	cout << endl << endl;

	espera_input();
}

void Bolsa::listar_transacoes_intervalo_de_tempo() {
	int opcao, dia, mes, ano;
	int primeiro_cli = -1;

	insertionSort(transacoes);

	cout << endl;
	cout << TAB << "1 - Transacoes efectuadas num dia." << endl;
	cout << TAB << "2 - Transacoes efectuadas num mes." << endl;
	cout << TAB << "3 - Transacoes efectuadas num ano." << endl;
	cout << TAB << "4 - Voltar ao menu inicial." << endl << endl;
	cout << TAB << "Qual a sua opcao: ";
	opcao = leInteiro(1, 4);

	switch (opcao) {
	case 1:
		cout << endl << endl;
		cout << TAB << "Dia da transacao: ";
		dia = leInteiro(0, 31);
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (dia == transacoes.at(i).getData().getDia()
				&& mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << "\nNenhuma transacao nesse dia.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha();
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha();

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (dia == transacoes.at(i).getData().getDia()
				&& mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha();
		cout << endl << endl;

		espera_input();
		break;
	case 2:
		cout << endl << endl;
		cout << TAB << "Mes da transacao: ";
		mes = leInteiro(0, 12);
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << "\nNenhuma transacao nesse mes.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha();
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha();

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (mes == transacoes.at(i).getData().getMes()
				&& ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha();
		cout << endl << endl;

		espera_input();
		break;
	case 3:
		cout << endl << endl;
		cout << TAB << "Ano da transacao: ";
		ano = leInteiro(1990, 2100);

		for (size_t i = 0; i < transacoes.size(); i++)
			if (ano == transacoes.at(i).getData().getAno()) {
				primeiro_cli = i;
				break;
			}

		if (primeiro_cli == -1) {
			cout << "\nNenhuma transacao nesse ano.\n\n";
			espera_input();
			return;
		}

		clearScreen();
		cout << endl;
		linha();
		cout << TAB << left << BARRA
			<< setw(11) << " Comprador " << BARRA
			<< setw(11) << " Vendedor " << BARRA
			<< setw(12) << " Data" << BARRA
			<< setw(15) << " Titulo" << BARRA
			<< setw(14) << " Preco medio " << BARRA
			<< setw(14) << " Numero acoes" << BARRA
			<< endl;
		linha();

		for (size_t i = primeiro_cli; i < transacoes.size(); i++)
			if (ano == transacoes.at(i).getData().getAno())
				cout << transacoes.at(i);

		linha();
		cout << endl << endl;

		espera_input();
		break;
	case 4:
		return;
		break;
	}
}

void Bolsa::listar_clientes() {
	insertionSort(clientes);

	clearScreen();
	cout << endl;
	cout << TAB_BIG << "Lista de Clientes" << endl << endl;
	for (size_t i = 0; i < clientes.size(); i++)
		cout << TAB << "Nome: " << right << setw(20) << clientes.at(i).getNome() << "     Nif: " << setfill('0') << setw(9) << clientes.at(i).getNif() << setfill(' ') << endl;
	cout << endl;
	espera_input();
	return;
}



int Bolsa::pos_vec_cli(string nome_cli){
	for (size_t i = 0; i < clientes.size(); i++)
	if (clientes.at(i).getNome() == nome_cli)
		return i;

	return -1;


}