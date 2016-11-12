/*
* Excecoes.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_MENUS_H_
#define SRC_MENUS_H_

#include <iostream>
#include <fstream>
#include <string>



#include "utils.h"
#include "Bolsa.h"
#include "Excecoes.h"


using namespace std;

int verfica_fich(string & fich_veri, string tipo_fich);

int infoInicial(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);

void opcoesIniciais(Bolsa & bolsa_de_valores);

void menuTransacoes(Bolsa & bolsa_de_valores);


#endif /* SRC_MENUS_H_ */