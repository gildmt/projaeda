/*
* Ordens.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
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

void linha(int n)
{
	cout << TAB;
	for (int i = 1; i < n; i++)
		cout << "--";

	cout << "\n";
}


long le_num()
{
	string input;
	long num;

	getline(cin, input);
	stringstream ss(input);

	while (!(ss >> num  && ss.eof())) {
		cout << TAB << "Input invalido" << endl;
		cout << TAB << "Introduza um numero valido: ";
		getline(cin, input);
		ss.str("");	ss.clear(); //apagar conteudo da stringsstream
		ss << input;
	}
	return num;
}

float le_float()
{
	string input;
	float num;

	getline(cin, input);
	stringstream ss(input);

	while (!(ss >> num  && ss.eof())) {
		cout << TAB << "Input invalido" << endl;
		cout << TAB << "Introduza um numero valido: ";
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
		cout << endl;
		cout << TAB << "Input Invalido. Introduza um numero entre " << min << " e " << max << " : ";
		num = le_num();
	}
	return num;

}

long leNif() {
	string input;
	long num;

	getline(cin, input);
	stringstream ss(input);

	if (!(ss >> num  && ss.eof())) {
		cout << endl;
		cout << TAB << "Input invalido" << endl;
		return -1;
	}

	if (num >= 0 && num <= 999999999)
		return num;
	return -1;
}

string leTitulo() {
	string input;
	string titulo;

	getline(cin, input);
	stringstream ss(input);

	if (!(ss >> titulo  && ss.eof())) {
		cout << endl;
		cout << TAB << "Input invalido" << endl;
		return "";
	}

	return titulo;
}

void espera_input()
{
	cout << endl;
	cout << TAB << "Pressione Enter para continuar.";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//string s;
	//getline(cin, s);
	//_getch;
}

Data getData() {
	time_t t = time(0); 
	struct tm now;
	Data actual;
	localtime_s(&now, &t);
	actual = Data(now.tm_mday, (now.tm_mon + 1), (now.tm_year + 1900));

	return actual;
}

bool fich_vazio(fstream& pFile)
{
	return pFile.peek() == fstream::traits_type::eof();
}

void acabatxt(string &str)
{
	string sufixo = ".txt";
	if (str.size() < sufixo.size())
		str = str + sufixo;

	if (str.compare(str.size() - sufixo.size(), sufixo.size(), sufixo) != 0)
		str = str + sufixo;
}

