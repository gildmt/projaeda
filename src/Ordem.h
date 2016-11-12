/*
 * Ordens.h
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#ifndef ORDEM_H_
#define ORDEM_H_

#include <string>
#include <iostream>
#include "Cliente.h"
#include "Data.h"

using namespace std;

class Ordem {
protected:
	string titulo;
	Data data;
	long nif_cliente;
public:

	Ordem(string titulo, Data data, long nif_cliente);

	const string& getTitulo() const {
		return titulo;
	}

	void setTitulo(const string& titulo) {
		this->titulo = titulo;
	}
	long getNif();
	Data getData();
};




#endif /* ORDEM_H_ */
