/*
* OrdemVenda.cpp
*
*  Created on: 17/10/2016
*      Author: Pedro
*/


#include "Bolsa.h"


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
void Bolsa::le_ficheiros_ordv(string & fichOrdensVenda){}
void Bolsa::le_ficheiros_ordc(string & fichOrdensCompra){}


void Bolsa::le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){
	le_ficheiros_cli(fichClientes);
	le_ficheiros_tran(fichTransacoes);
	le_ficheiros_ordv(fichOrdensVenda);
	le_ficheiros_ordc(fichOrdensCompra);
}

void Bolsa::guarda_alteracoes(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra){

}


void Bolsa::ad_ordem_compra(){

}
void Bolsa::ad_ordem_venda(){

}
void Bolsa::ad_cli(){

}
void Bolsa::listar_transacoes_cli(){

}
void Bolsa::listar_transacoes_titulo(){

}
void Bolsa::listar_transacoes_dia(){

}
void Bolsa::listar_transacoes_intervalo_de_tempo(){

}



int Bolsa::pos_vec_cli(string nome_cli){
	for (int i = 0; i < clientes.size();i++)
	if (clientes.at(i).getNome() == nome_cli)
		return i;

	return -1;


}