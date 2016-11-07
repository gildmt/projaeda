/*
 * Transacao.c
 *
 *  Created on: 30/10/2016
 *      Author: gildi
 */

#include "Transacao.h"


Transacao::Transacao(string titulo, float preco_acao, int num_acoes, Data data, Cliente* cliente_v, Cliente* cliente_c){

}

Transacao::Transacao(ifstream & in){
	string nome1_aux, nome_aux2, titulo_aux, data_str;
	float preco_acao_aux;
	int num_acoes_aux;

	//le ficheiro
	getline(in, nome1_aux, ';'); nome1_aux.erase(nome1_aux.end() - 1); //apaga ultimo espaco
	in.ignore(); //anda 1 espaco
	getline(in, nome_aux2, ';'); nome_aux2.erase(nome_aux2.end() - 1); //apaga ultimo espaco
	in.ignore(); //anda 1 espaco
	getline(in, data_str, ';'); data_str.erase(data_str.end() - 1); //apaga ultimo espaco
	in.ignore(); //anda 1 espaco
	getline(in, titulo_aux, ';'); titulo_aux.erase(titulo_aux.end() - 1); //apaga ultimo espaco
	in >> preco_acao_aux;
	in.ignore(3); //anda 3 espaco
	in >> num_acoes_aux;

	int pos_cli1 = pos_vec_cli(nome1_aux);
	int pos_cli2 = pos_vec_cli(nome1_aux);


}


bool Transacao::operator<(const Transacao &transacao){

	//apagar
	return true;
}


ostream& operator<< (ostream& out, const Transacao & transacao){
	
	//apagar
	return out;

}