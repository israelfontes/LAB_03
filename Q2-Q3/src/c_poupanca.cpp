#include <string>
#include <iostream>
#include "c_poupanca.hpp"

/**
* @file     c_poupanca.cpp
* @brief    Implementação dos membros de Conta poupança.
* @since    23/10/2017
* @date     23/10/2017
*/

ContaPoupanca::ContaPoupanca(){}

ContaPoupanca::ContaPoupanca(std::string _numero, std::string _agencia, std::string _status, double _saldo, double _taxa_juros):
	Conta(_numero, _agencia, _status, _saldo), p_taxa_juros(_taxa_juros){}

ContaPoupanca::~ContaPoupanca(){}

double ContaPoupanca::getTaxa(){ return p_taxa_juros; }		

double ContaPoupanca::getLimiteDisp(){return 0;}

void ContaPoupanca::setLimiteDisp(double const _limite_disp){  }

void ContaPoupanca::setTaxa(double const _taxa_juros){ p_taxa_juros = _taxa_juros; }

std::ostream& ContaPoupanca::print(std::ostream &o) const{
	o << "Taxa de juros: " << p_taxa_juros << "%" << std::endl;
	o << "============================================" << std::endl;
	return o;
}
	
std::istream& ContaPoupanca::read(std::istream &i){
	
	std::cout << "Digite a taxa de juros (%): ";
	i >> p_taxa_juros;
	
	std::cout << std::endl;
	return i;
}