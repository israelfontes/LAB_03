#ifndef _FRUTA_H_
#define _FRUTA_H_
#include "produto.h"

/**
* @file     fruta.h
* @brief    Classe Fruta, ela representa os membros de um objeto do tipo Fruta, herdando as características da classe Produto.
* @author   Israel Medeiros Fontes
* @since    19/10/2017
* @date     20/10/2017
*/

class Fruta : public Produto
{
	public:
		/// Construtor padrão.
		Fruta();

		/** Construtor parametrizado.
		* @param _codigo Código de barras da bebida.
		* @param _descricao Descrição da bebida.
		* @param _preco Preço da bebida.
		* @param _validade Validade da fruta.
		* @param _lote Lote da fruta.
		*/
		Fruta(std::string _codigo, std::string _descricao, double _preco, std::string _lote, short _validade);

		/// Destrutor padrão.
		~Fruta();
	private:
		std::string m_data_lote; /**< Lote da fruta. */
		short m_validade; /**< Validade da fruta. */

	public:
		/// ---Getters

		/** @return Lote da fruta. */ 
		std::string getLote();
		/** @return Validade da fruta. */
		short getValidade();
		
		/// ---Setters

		/**
		* Altera o lote da fruta. 
		* @param _lote Novo lote da fruta.
		*/
		void setLote(std::string _lote);
		/**
		* Altera a validade da fruta.
		* @param _validade Nova validade da fruta.
		*/
		void setValidade(short _validade);
	
		//friend std::ostream& operator<<(std::ostream &o, Fruta &t);
	
	private:
		std::ostream& print(std::ostream &o) const;
	};

#endif