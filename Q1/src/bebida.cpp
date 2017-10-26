#include <iostream>
#include <iomanip>
#include "bebida.h"

Bebida::Bebida() {}

Bebida::~Bebida(){}

Bebida::Bebida( std::string _codigo, std::string _descricao, double _preco, double _teor ):
	Produto(_codigo, _descricao, _preco), m_teor_alcoolico(_teor){}

double Bebida::getTeor(){
	return m_teor_alcoolico;
}

void Bebida::setTeor(double _teor){
	m_teor_alcoolico = _teor;
}

std::ostream& Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (4) << m_teor_alcoolico << "%";
	return o;
}