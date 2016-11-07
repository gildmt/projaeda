/*
 * Bolsa.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */

#ifndef BOLSA_H_
#define BOLSA_H_

#include <iostream>
#include <vector>
#include <fstream>
#include "OrdemVenda.h"
#include "OrdemCompra.h"
#include "Cliente.h"
#include "Transacao.h"

using namespace std;

class Bolsa {
private:
	vector<Cliente> clientes;
	vector<OrdemCompra> ordensCompra;
	vector<OrdemVenda> ordensVenda;
	vector<Transacao> transacoes;
public:

	Bolsa() {

	};

	void addCliente(Cliente cli);
	void removeCliente(Cliente cli);

	void addOrdemCompra(OrdemCompra oc);
	void addOrdemVenda(OrdemVenda ov);

	const vector<Cliente>& getClientes() const;

	void setClientes(const vector<Cliente>& clientes);

	const vector<OrdemCompra>& getOrdensCompra() const;

	void setOrdensCompra(const vector<OrdemCompra>& ordensCompra);

	const vector<OrdemVenda>& getOrdensVenda() const;

	void setOrdensVenda(const vector<OrdemVenda>& ordensVenda);

	void le_ficheiros(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);
	void le_ficheiros_cli(string & fichClientes);
	void le_ficheiros_tran(string & fichTransacoes);
	void le_ficheiros_ordv(string & fichOrdensVenda);
	void le_ficheiros_ordc(string & fichOrdensCompra);




	void guarda_alteracoes(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);
	void ad_ordem_compra();
	void ad_ordem_venda();
	void ad_cli();
	void listar_transacoes_cli();
	void listar_transacoes_titulo();
	void listar_transacoes_dia();
	void listar_transacoes_intervalo_de_tempo();


	//outras func

	int pos_vec_cli(string nome_cli);


};

#endif /* BOLSA_H_ */