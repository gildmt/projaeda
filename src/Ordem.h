/*
 * Ordens.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */

#ifndef ORDEM_H_
#define ORDEM_H_

#include <string>
#include <iostream>
#include "Cliente.h"
#include "Data.h"

using namespace std;

class Ordem {
private:
	string titulo;
	Data data;
	Cliente* cliente;
public:

	Ordem(string titulo, Data data, Cliente* cli);

	const string& getTitulo() const {
		return titulo;
	}

	void setTitulo(const string& titulo) {
		this->titulo = titulo;
	}

	
};




#endif /* ORDEM_H_ */
