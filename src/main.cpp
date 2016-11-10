/*
 * main.cpp
 *
 *  Created on: 17/10/2016
 *      Author: Gil Teixeira & Paulo Correia
 */

#include "Bolsa.h"
#include "Data.h"
#include "Menus.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>


//#include "Cliente.h"

using namespace std;



int main(){
	string fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra;

	//v final
	//if (infoInicial(fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra))
	//	return 1;

	//v para testes
	fichClientes = "c.txt";
	fichTransacoes = "t.txt";
	fichOrdensVenda = "ov.txt";
	fichOrdensCompra = "oc.txt";

	// cria bolsa
	Bolsa bolsa_de_valores;
	
	//le ficheiros
	bolsa_de_valores.le_ficheiros(fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra);

	opcoesIniciais(bolsa_de_valores); // menu inicial com as grandes opcoes
	// que implementam as funcioanlidades
	// disonibilizadas

	//guarda alteracoes
	bolsa_de_valores.guarda_alteracoes(fichClientes, fichTransacoes, fichOrdensVenda, fichOrdensCompra);

	return 0;
}



	/* TEsstes

	int main() {


	Cliente cli("Pedro",145123123);

	OrdemCompra ordem1("primeira", "17/10/2016", cli, 19.0, 190.0);
	OrdemCompra ordem2("segunda", "17/10/2016", cli, 12.0, 190.0);
	OrdemCompra ordem3("terceira", "17/10/2016", cli, 15.0, 190.0);
	OrdemCompra ordem4("quarta", "17/10/2016", cli, 16.0, 190.0);

	vector<Ordem> ordens;
	ordens.push_back(ordem1);
	ordens.push_back(ordem2);
	ordens.push_back(ordem3);
	ordens.push_back(ordem4);


}

int main() {
int a1 = 2016;
int a2 = 2071;
int a3 = 1960;
int m = 2;
int d = 29;


Data d1(d, m, a1);
Data d2(d, m, a2);
Data d3(d, m, a3);


if (d2.valida())
cout << "+";


if (d1.valida())
cout << "-";


if (d3.valida())
cout << "7";

cout << d3;

}



*/

