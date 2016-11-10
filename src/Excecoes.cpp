/*
* Excecoes.c
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Excecoes.h"


FicheiroInexistente::FicheiroInexistente(string tipo_fich){
	this->tipo_fich = tipo_fich;
}


ostream& operator<< (ostream& out, const FicheiroInexistente & fich_inex){
	out << "\n Esse ficheiro nao existe." << endl << "Introduza o nome de um ficheiro de " 
		<< fich_inex.tipo_fich << " existente(ou control+z para sair): ";
	return out;
}

FicheiroInvalido::FicheiroInvalido(string tipo_fich){
	this->tipo_fich = tipo_fich;
}


ostream& operator<< (ostream& out, const FicheiroInvalido & fich_inva){
	out << "\n Esse ficheiro e invalido." << endl << "Introduza o nome de um ficheiro de " 
		<< fich_inva.tipo_fich << " valido(ou control+z para sair): ";
	return out;
}

