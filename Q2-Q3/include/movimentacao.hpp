#ifndef _MOVIMENTACAO_H
#define _MOVIMENTACAO_H
#include <string>

/**
* @file     movimentacao.h
* @brief    Classe Movimentacao que abstraí uma movimentação de conta bancária.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

class Movimentacao{

	private:
		std::string m_descricao; /**< Descrição da momvimentação. */
		std::string m_tipo; /**< Tipo da movimentação (crédito ou débito). */
		double m_valor; /**< Valor da movimentação. */

	public:
		///Construtor padrão.
		Movimentacao();

		/**
		* Constutor parametrizado.
		* @param _descricao Descrição da nova movimentação.
		* @param _tipo Tipo da nova movimentação.
		* @param _valor da nova movimentação.
		*/
		Movimentacao(std::string _descricao, std::string _tipo, double _valor);

		/// Destrutor padrão virtual para que possa ser destruído quando objetos derivados sejam destruídos.
		virtual ~Movimentacao();

		/** @return Descrição da movimentação. */
		std::string getDescricao();

		/** @return Tipo da movimentação. */
		std::string getTipo();

		/** @return Valor da movimentação. */
		double getValor();

		/**
		* Altera a descrição da movimentação.
		* @param _descricao Nova descrição da movimentação.
		*/
		void setDescricao(std::string const _descricao);

		/**
		* Altera o tipo da descrição.
		* @param _tipo Novo tipo da descrição. 
		*/		
		void setTipo(std::string const _tipo);

		/**
		* Altera o valor da movimentação. 
		* @param _valor Novo valor da movimentação.
		*/
		void setValor(double const _valor); 
};
#endif