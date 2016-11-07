/*
 * OrdemCompra.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */

#include "OrdemCompra.h"

OrdemCompra::OrdemCompra(string titulo, Data data, Cliente* cliente, float precoMax, float valorMaxGastar): Ordem(titulo, data, cliente) {
	this->precoMax=precoMax;
	this->valorMaxGastar=valorMaxGastar;
}


