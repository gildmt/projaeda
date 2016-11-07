/*
* Excecoes.h
*
*  Created on: 30/10/2016
*      Author: gildi
*/

#ifndef SRC_EXCECOES_H_
#define SRC_EXCECOES_H_

#include <string>


using namespace std;


class FicheiroInexistente {
public:
	string tipo_fich;
	FicheiroInexistente(string tipo_fich);
	friend ostream& operator<<(ostream& out, const FicheiroInexistente & fich_inex);
};

class FicheiroInvalido {
private:
	string tipo_fich;

public:
	FicheiroInvalido(string tipo_fich);
	friend ostream& operator<<(ostream& out, const FicheiroInvalido & fich_inva);
};







#endif /* SRC_EXCECOES_H_ */