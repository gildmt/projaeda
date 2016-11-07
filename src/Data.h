/*
* Data.h
*
*  Created on: 30/10/2016
*      Author: gildi
*/

#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;




class Data {
private:
	int ano;
	int mes;
	int dia;
public:
	Data(int d, int m, int a);
	Data();
	Data(string data_str);
	bool valida(void) const;
	int getDia() const;
	int getMes() const;
	int getAno() const;
	void setDia(const int& d);
	void setMes(const int& m);
	void setAno(const int& a);



	bool operator ==(const Data& d);

	bool operator <(const Data& d);

	friend ostream& operator <<(ostream& os, const Data& d);



};




class data_invalida {
string erro;
public:
data_invalida(string erro);
friend ostream& operator <<(ostream& os, const Data& d);
};







#endif /* SRC_DATA_H_ */