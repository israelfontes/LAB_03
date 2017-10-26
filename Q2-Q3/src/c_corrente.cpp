#include <string>
#include <iostream>
#include "c_corrente.hpp"

/**
* @file     c_corrente.hpp
* @brief    Implementaçao da Classe ContaCorrente.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

ContaCorrente::ContaCorrente(){}

ContaCorrente::ContaCorrente(std::string _numero, std::string _agencia, std::string _status, double _saldo, double _limite): 
	Conta(_numero, _agencia, _status, _saldo), cc_limite(_limite){}

ContaCorrente::~ContaCorrente(){}

double ContaCorrente::getLimite(){ return cc_limite; }

double ContaCorrente::getLimiteDisp(){ return cc_limite_disp; }

void ContaCorrente::setLimite(double const _limite){ cc_limite = _limite; }

void ContaCorrente::setLimiteDisp(double const _limite_disp){ cc_limite_disp = _limite_disp; }

std::ostream& ContaCorrente::print(std::ostream &o) const{
	o << "Limite: R$" << cc_limite << std::endl;
	o << "Limite Disponível: R$" << cc_limite_disp << std::endl;
	o << "============================================" << std::endl;
	return o;
}
		
std::istream& ContaCorrente::read(std::istream &i){
	std::cout << "Digite o limite da conta: R$";
	i >> cc_limite;
	cc_limite_disp = cc_limite;
	std::cout << std::endl;

	return i;
}