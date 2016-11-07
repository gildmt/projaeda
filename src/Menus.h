#pragma once

#include <iostream>
#include <fstream>
#include <string>



#include "utils.h"
#include "Bolsa.h"
#include "Excecoes.h"


using namespace std;

int verfica_fich(string fich_veri, string tipo_fich);

int infoInicial(string & fichClientes, string & fichTransacoes, string & fichOrdensVenda, string & fichOrdensCompra);

void opcoesIniciais(Bolsa & bolsa_de_valores);






//apagar
/*
void opcoesGestaoClientes(VendeMaisMais & supermercado);
void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);

void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);
*/