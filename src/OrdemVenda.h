/*
 * OrdemVenda.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEMVENDA_H_
#define ORDEMVENDA_H_

#include "Ordem.h"

#include <string>
#include <iostream>

using namespace std;

class OrdemVenda: public Ordem {
private:
	int quantidade;
	float precoMin;
public:

	OrdemVenda(string titulo, Data data, long nif_cliente, int quantidade, float precoMin);

	float getPrecoMin() const {
		return precoMin;
	}

	void setPrecoMin(float precoMin) {
		this->precoMin = precoMin;
	}

	int getQuantidade() const {
		return quantidade;
	}

	void setQuantidade(int quantidade) {
		this->quantidade = quantidade;
	}
};




#endif /* ORDEMVENDA_H_ */
