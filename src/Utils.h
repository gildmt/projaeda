/*
* Utils.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <windows.h>

#define ALTURA_ECRA 24

#define TAB_BIG "          "
#define TAB    "   "
#define BARRA    "|"

#include <iostream>
#include <sstream>

#include "Data.h"

#undef max

using namespace std;



void clearScreen();
void linha();

long le_num();

float le_float();

int leInteiro(int min, int max);

long leNif();

string leTitulo();

void espera_input();

Data getData();
#endif /* SRC_UTILS_H_ */
