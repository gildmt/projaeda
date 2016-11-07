/*
* Ordens.cpp
*
*  Created on: 17/10/2016
*      Author: Pedro
*/


#include "Utils.h"


void clearScreen() {

	COORD upperLeftCorner = { 0, 0 };
	DWORD charsWritten;
	DWORD conSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO  csbi;

	GetConsoleScreenBufferInfo(hCon, &csbi);
	conSize = csbi.dwSize.X * csbi.dwSize.Y;

	// fill with spaces
	FillConsoleOutputCharacter(hCon, TEXT(' '), conSize, upperLeftCorner, &charsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, conSize, upperLeftCorner, &charsWritten);

	// cursor to upper left corner
	SetConsoleCursorPosition(hCon, upperLeftCorner);
}


int le_num()
{
	string input;
	int num;

	getline(cin, input);
	stringstream ss(input);

	while (!(ss >> num  && ss.eof())) {
		cout << "Input invalido" << endl;
		cout << "Introduza um numero valido: ";
		getline(cin, input);
		ss.str("");	ss.clear(); //apagar conteudo da stringsstream
		ss << input;
	}
	return num;
}

int leInteiro(int min, int max){
	int num = le_num();

	while (num < min || num > max)
	{
		cout << "\nInput Invalido. Introduza um numero entre " << min << " e " << max << " : ";
		num = le_num();
	}
	return num;

}