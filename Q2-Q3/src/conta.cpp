#include <iostream>
#include <string>
#include <vector>

#include "conta.hpp"
#include "movimentacao.hpp"

/**
* @file     conta.cpp
* @brief    Implementação da classe Conta.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

Conta::Conta(){ }

Conta::Conta(std::string _numero, std::string _agencia, std::string _status, double _saldo): 
	c_numero(_numero), c_agencia(_agencia), c_status(_status), c_saldo(_saldo) {}

Conta::~Conta(){}

std::string Conta::getNumero(){ return c_numero; }

std::string Conta::getAgencia(){ return c_agencia; }

std::string Conta::getStatus(){ return c_status; }

double Conta::getSaldo(){ return c_saldo; }

std::vector<Movimentacao> * Conta::getMovimentacoes(){ return &c_movimentacoes; }

void Conta::addMovimentacao(std::string const _descricao, std::string const _tipo, double const _valor){	
	Movimentacao movimentacao(_descricao, _tipo, _valor);
	c_movimentacoes.push_back(movimentacao);
}

void Conta::setNumero(std::string const _numero){ c_numero = _numero; }

void Conta::setAgencia(std::string const _agencia){ c_agencia = _agencia; }

void Conta::setStatus(std::string const _status){c_status = _status; } 

void Conta::setSaldo(double const _saldo){ c_saldo = _saldo; }

bool Conta::operator== (Conta &conta){
	if(not c_numero.compare(conta.getNumero()) and not c_agencia.compare(conta.getAgencia()))
		return true;
			
	return false;
}	

std::ostream& operator<< (std::ostream &o, Conta &conta){

	o << "=====================CONTA===================" << std::endl;
	o << "Número da conta: " << conta.getNumero() << std::endl;
	o << "Agência: " << conta.getAgencia() << std::endl;
	o << "Status da conta: " << conta.getStatus() << std::endl;
	o << "Saldo: R$" << conta.getSaldo() << std::endl;
	
	return conta.print(o);
}

std::istream& operator>> (std::istream &i, Conta &conta){
	std::string temp;
	double temp_d;

	std::cout << "Digite o número da conta: ";
	i >> temp;
	conta.setNumero(temp);

	std::cout << "Digite a agência: ";
	i >> temp;
	conta.setAgencia(temp);

	std::cout << "Digite o status da conta: ";
	i >> temp;
	conta.setStatus(temp);

	std::cout << "Digite o saldo inicial da conta: R$";
	i >> temp_d;
	conta.setSaldo(temp_d);
	std::cout << std::endl;

	return conta.read(i);
}