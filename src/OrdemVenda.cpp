/*
 * OrdemVenda.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */


#include "OrdemVenda.h"

OrdemVenda::OrdemVenda(string titulo, Data data, long nif_cliente, int quantidade, float precoMin) : Ordem(titulo, data, nif_cliente) {
	this->quantidade=quantidade;
	this->precoMin=precoMin;
}
