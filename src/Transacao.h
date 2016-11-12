/*
 * Transacao.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef SRC_TRANSACAO_H_
#define SRC_TRANSACAO_H_

#include "Cliente.h"
#include "Data.h"
#include "Utils.h"
#include <string>
#include <iomanip>

class Transacao {
private:
	string titulo;
	float preco_acao;
	int num_acoes;
	Data data;
	long nif_cliente_v;
	long nif_cliente_c;

public:
	Transacao(string titulo, float preco_acao, int num_acoes, Data data, long cliente_v, long cliente_c);
	Transacao(ifstream & in); //le linha de ficheiro
	bool operator<(const Transacao &tr) const; // compara 2 transacoes (1 transacao e menor que outra se estiver há mais tempo no mercado)
	friend ostream& operator<<(ostream& out, const Transacao & transacao);  // mostra informacao da transacao no ecra
	string getTitulo();
	float getPreco_acao();
	int getNum_acoes();
	Data getData();
	long getCliente_v();
	long getCliente_c();
	void guardar(ofstream & out) const;
};



#endif /* SRC_TRANSACAO_H_ */
