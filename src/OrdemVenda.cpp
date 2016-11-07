/*
 * OrdemVenda.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */


#include "OrdemVenda.h"

OrdemVenda::OrdemVenda(string titulo, Data data, Cliente* cliente, int quantidade, float precoMin) : Ordem(titulo, data, cliente) {
	this->quantidade=quantidade;
	this->precoMin=precoMin;
}

