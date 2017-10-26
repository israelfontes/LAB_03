#include <iostream>
#include <iomanip>
#include <string>
#include "produto.h"

Produto::Produto(){}

Produto::~Produto(){}

Produto::Produto(std::string _codigo, std::string _descricao, double _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}

std::string Produto::getCodBarras() {
	return m_cod_barras;
}
	
std::string Produto::getDescricao() {
	return m_descricao;
}

double Produto::getPreco() {
	return m_preco;
}
	
void Produto::setCodBarras(std::string _codigo) {
	m_cod_barras = _codigo;
}

void Produto::setDescricao(std::string _descricao) {
	m_descricao = _descricao;
}

void Produto::setPreco(double _preco) {
	m_preco = _preco;
}

double Produto::operator+(Produto &p){
	return m_preco + p.getPreco();
}

double Produto::operator+(double &p){
	return m_preco + p;
}

double Produto::operator-(Produto &p){
	return m_preco - p.getPreco();
}

double Produto::operator-(double &p){
	return m_preco - p;
}

bool Produto::operator==(Produto &p){
	if(m_cod_barras.compare(p.getCodBarras()))
		return true;
	return false;
}

std::ostream& operator<< (std::ostream &o, Produto &t) {
	o << std::setfill (' ') << std::setw (10) << t.getCodBarras() << " | " 
 		<< std::setfill ('.') << std::setw (20) << t.getDescricao() << " | " 
		<< std::setfill (' ') << std::setw (5) << t.getPreco() << " | ";
	return t.print(o);
}