
#ifndef _BEBIDA_H_
#define _BEBIDA_H_
#include "produto.h"

/**
* @file     bebida.h
* @brief    Classe Bebida, ela representa os membros de um objeto do tipo Bebida, herdando as características da classe Produto.
* @author   Israel Medeiros Fontes
* @since    19/10/2017
* @date     20/10/2017
*/

class Bebida : public Produto
{
	public:
		/// Construtor padrão.
		Bebida();

		/** Construtor parametrizado.
		* @param _codigo Código de barras da bebida.
		* @param _descricao Descrição da bebida.
		* @param _preco Preço da bebida.
		* @param _teor Teor alcoólico da bebida. 
		*/
		Bebida(std::string _codigo, std::string _descricao, double _preco, double _teor);
		
		/// Destrutor padrão.
		~Bebida();

	private:
		double m_teor_alcoolico; /**< Teor alcoólico da bebida. */

	public:
		/// ---Getters
		/**
		* @return Teor alcoólico da bebida.
		*/
		double getTeor();

		// ---Setters
		/**
		* Altera o teor alcoólico da bebida.
		* @param Novo teor da bebida.
		*/
		void setTeor(double _teor);

		// ---Operators
		friend std::ostream& operator<< (std::ostream &o, Bebida const &t); 

	private:
		std::ostream& print(std::ostream &o) const;

};
 
#endif
