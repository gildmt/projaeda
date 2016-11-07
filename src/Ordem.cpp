/*
 * Ordens.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */


#include "Ordem.h"
#include "Cliente.h"


Ordem::Ordem(string titulo, Data data, Cliente* cli) {
	this->titulo = titulo;
	this->data=data;
	this->cliente=cli;
}


