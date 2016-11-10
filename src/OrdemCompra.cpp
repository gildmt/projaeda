/*
 * OrdemCompra.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#include "OrdemCompra.h"

OrdemCompra::OrdemCompra(string titulo, Data data, long nif_cliente, float precoMax, float valorMaxGastar) : Ordem(titulo, data, nif_cliente) {
	this->precoMax=precoMax;
	this->valorMaxGastar=valorMaxGastar;
}


