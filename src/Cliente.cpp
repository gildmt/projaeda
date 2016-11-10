/*
 * Clientes.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */
#include "Cliente.h"

Cliente::Cliente(string nome, int nif) {
	this->nome=nome;
	this->nif=nif;
}

Cliente::Cliente(){};

Cliente::Cliente(ifstream & in){
	string nome_aux;
	long nif_aux;
	getline(in, nome_aux, ';'); nome_aux.erase(nome_aux.end() - 1); //apaga ultimo espaco
	in >> nif_aux;
	in.ignore(1);
	nome = nome_aux;
	nif = nif_aux;


}

string Cliente::getNome(){
	return nome;

}
int Cliente::getNif(){
	return nif;

}

void Cliente::setNome(string nome){
	this->nome = nome;
}

void Cliente::setNif(long nif){
	this->nome = nome;
}

bool Cliente::operator<(const Cliente &cl) const {
	return nome < cl.nome;
}





