/*
 * Cliente.h
 *
 *  Created on: 17/10/2016
 *      Author: Pedro
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


//IMP: pode haver 2 cli com o mesmo nome, mas nao com o mesmo NIF

class Cliente {
private:
	string nome;
	long nif;

public:
	Cliente(string nome, int NIF);
	Cliente();
	Cliente(ifstream & in); //le linha de ficheiro
	string getNome();
	int getNif();
	void setNome(string nome);
	void setNif(long NIF);
};



#endif /* CLIENTE_H_ */
