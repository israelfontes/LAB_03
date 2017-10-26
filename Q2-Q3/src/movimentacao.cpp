#include <string>
#include "movimentacao.hpp"

/**
* @file     movimentacoes.hpp
* @brief    Classe Movimentacoes que abstraí as movimentações bancárias de uma conta bancária. 
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

Movimentacao::Movimentacao(){}

Movimentacao::Movimentacao(std::string _descricao, std::string _tipo, double _valor):
 m_descricao(_descricao), m_tipo(_tipo), m_valor(_valor){}

Movimentacao::~Movimentacao(){}

std::string Movimentacao::getDescricao(){ return m_descricao; }

std::string Movimentacao::getTipo(){ return m_tipo; }

double Movimentacao::getValor(){ return m_valor; }

void Movimentacao::setDescricao(std::string const _descricao){ m_descricao = _descricao; }

void Movimentacao::setTipo(std::string const _tipo){ m_tipo = _tipo; }

void Movimentacao::setValor(double const _valor){ m_valor = _valor; } 

