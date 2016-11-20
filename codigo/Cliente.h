/*
* Cliente.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <iostream>
#include <fstream>


using namespace std;

/**
* @class	Cliente
*
* @brief	Classe que guarda o nome e o nif do cliente e as funcoes para manipulacao da mesma.
*/

class Cliente {
private:
	/** @brief	O nome do Cliente. */
	string nome;
	/** @brief	O NIF do Cliente. */
	long nif;

public:

	/**
	* @fn	Cliente::Cliente(string nome, long NIF);
	*
	* @brief	Constructor do Cliente que aceita o nome e o NIF como parametros.
	*
	* @param	nome	The nome.
	* @param	NIF 	The nif.
	*/

	Cliente(string nome, long NIF);

	/**
	* @fn	Cliente::Cliente();
	*
	* @brief	Construtor por defeito.
	*/

	Cliente();

	/**
	* @fn	Cliente::Cliente(ifstream & in);
	*
	* @brief	Constructor que le uma linha de um ficheiro.
	*
	* @param   in	Ficheiro de Clientes.
	*/

	Cliente(ifstream & in); 

	/**
	* @fn	string Cliente::getNome();
	*
	* @brief	Retorna o nome do Cliente.
	*
	* @return	O Nome do Cliente.
	*/

	string getNome();

	/**
	* @fn	int Cliente::getNif();
	*
	* @brief	Retorna o NIF do Cliente.
	*
	* @return	 O NIF do Cliente.
	*/

	int getNif();

	/**
	* @fn	void Cliente::setNome(string nome);
	*
	* @brief	Define o nome do Cliente.
	*
	* @param	nome	 O nome do Cliente.
	*/

	void setNome(string nome);

	/**
	* @fn	void Cliente::setNif(long NIF);
	*
	* @brief	Define o NIF do Cliente.
	*
	* @param	NIF	O NIF do Cliente.
	*/

	void setNif(long NIF);

	/**
	* @fn	bool Cliente::operator<(const Cliente &cl) const;
	*
	* @brief	Operador de comparacao "menor que".
	*
	* @param			cl	O Cliente com que se compara.
	*
	* @return	True se o primeiro parametro for menor que o segundo. False se maior ou igual.
	*/

	bool operator<(const Cliente &cl) const;

	/**
	* @fn	void Cliente::guardar(ofstream & out) const;
	*
	* @brief	Escreve no ficheiro de texto na forma "nome ; nif".
	*
	* @param			out	O Ficheiro de texto em que se escreve.
	*/

	void guardar(ofstream & out) const;
};



#endif /* CLIENTE_H_ */
