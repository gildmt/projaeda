/*
 * Transacao.h
 *
 *  Created on: 31/10/2016
 *      Author: gildi
 */

#ifndef SRC_TRANSACAO_H_
#define SRC_TRANSACAO_H_

#include "Cliente.h"
#include "Data.h"
#include <string>

class Transacao {
private:
	string titulo;
	float preco_acao;
	int num_acoes;
	Data data;
	Cliente* cliente_v;
	Cliente* cliente_c;

public:
	Transacao(string titulo, float preco_acao, int num_acoes, Data data, Cliente* cliente_v, Cliente* cliente_c);
	Transacao(ifstream & in); //le linha de ficheiro
	bool operator<(const Transacao &transacao); // compara 2 transacoes (1 cleinte e menor que outro se estiver há mais tempo no mercado)
	friend ostream& operator<<(ostream& out, const Transacao & transacao);  // mostra informacao da transacao no ecra
	

};



#endif /* SRC_TRANSACAO_H_ */
