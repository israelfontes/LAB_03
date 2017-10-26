#include <iomanip>
#include "roupa.h"

Roupa::Roupa() {}

Roupa::Roupa(std::string _codigo, std::string _descricao, double _preco, 
			std::string _marca, char _sexo, std::string _tamanho):
	Produto(_codigo, _descricao, _preco), m_marca(_marca), m_tamanho(_tamanho), m_sexo(_sexo) {}

Roupa::~Roupa() {}

std::string Roupa::getMarca(){
	return m_marca;
}

std::string Roupa::getTamanha(){
	return m_tamanho;
}

char Roupa::getSexo(){
	return m_sexo;
}

void Roupa::setMarca(std::string _marca){
	m_marca = _marca;
}

void Roupa::setTamanho(std::string _tamanho){
	m_tamanho = _tamanho;
}
void Roupa::setSexo(char _sexo){
	m_sexo = _sexo;
}

std::ostream& Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_marca << " | " 
		<< std::setfill (' ') << std::setw (5) << m_tamanho << " | "
		<< std::setfill (' ') << std::setw (1) << m_sexo;
	return o;
}