#include <iomanip>
#include "fruta.h"

Fruta::Fruta() {}

Fruta::Fruta(std::string _codigo, std::string _descricao, double _preco, std::string _lote, short _validade):
	Produto(_codigo, _descricao, _preco), m_data_lote(_lote), m_validade(_validade) {}

Fruta::~Fruta() {}

std::string Fruta::getLote() {
	return m_data_lote;
}

short Fruta::getValidade() {
	return m_validade;
}

void Fruta::setLote(std::string _data) {
	m_data_lote = _data;
}

void Fruta::setValidade(short _validade) {
	m_validade = _validade;
}

std::ostream& Fruta::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << m_validade;
	return o;
}