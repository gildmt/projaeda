/*
 * OrdemCompra.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEMCOMPRA_H_
#define ORDEMCOMPRA_H_

#include "Ordem.h"
#include "Utils.h"

#include <string>
#include <iostream>

using namespace std;

class OrdemCompra: public Ordem {
private:
	float precoMax;
	float valorMaxGastar;
public:

	OrdemCompra(string titulo, Data data, long nif_cliente, float precoMax, float valorMaxGastar);

	float getPrecoMax() const {
		return precoMax;
	}

	void setPrecoMax(float precoMax) {
		this->precoMax = precoMax;
	}

	float getValorMaxGastar() const {
		return valorMaxGastar;
	}

	void setValorMaxGastar(float valorMaxGastar) {
		this->valorMaxGastar = valorMaxGastar;
	}

	void guardar(ofstream & out) const;
	friend ostream& operator<<(ostream& out, const OrdemCompra & ordem);
};



#endif /* ORDEMCOMPRA_H_ */
