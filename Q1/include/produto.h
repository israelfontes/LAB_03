
#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
/**
* @file     produto.h
* @brief    Classe Produto, ela possui os membros comuns a todos os produtos.
* @author   Israel Medeiros Fontes
* @since    19/10/2017
* @date     20/10/2017
*/

class Produto
{
	public:
		/**
		* Construtor padrão sem parâmetros.
		*/
		Produto();
		/**
		* Construtor parametrizado.
		* @param _codigo Codigo do produto
		* @param _descricao Descrição do Produto.
		* @param _preco Preço do produto.
		*/
		Produto(std::string _codigo, std::string _descricao, double _preco);
		///---Destrutor virtual para que o objeto Produto possa ser destruido automaticamente quando o objeto derivado for destruido.
		virtual ~Produto();
	protected:
		std::string m_cod_barras; /**< Valor do código de barras. */
		std::string m_descricao; /**< Valor da descrição. */
		double m_preco;	/**< Valor do preço do produto. */

	public:
		/// ---Getters
		/**
		* @return Código de barras do produto.
		*/
		std::string getCodBarras();

		/**
		* @return Descrição do produto.
		*/
		std::string getDescricao();

		/**
		* @return Preço do produto.
		*/
		double getPreco();
		
		/// ---Setters

		/**
		* Altera o código de barras do produto.
		* @param _codigo Novo código de barras do produto.
		*/
		void setCodBarras(std::string _codigo);
		/**
		* Altera a descriçãos do produto.
		* @param _descricao Nova descrição do produto.
		*/
		void setDescricao(std::string _descricao);

		/**
		* Altera o preço do produto.
		* @param _preco Novo preço do produto.
		*/
		void setPreco(double _preco);
		
		/// ---Operators

		/**
		* Sobrecarga do operador de inserção.
		* @return Output stream com os atributos do produto.
		*/
		friend std::ostream& operator<< (std::ostream &o, Produto &p); 
		
		/**
		* Sobrecarga do operador de adição.
		* @return Valor da soma de dois produtos.
		*/
		double operator+(Produto &p);
		
		/**
		* Sobrecarga do operador de adição.
		* @return Valor da soma do preço entre um objeto produto e um double.
		*/
		double operator+(double &p); 
		
		/**
		* Sobrecarga do operador de subtração.
		* @return Valor da subtração entre dois produtos.
		*/
		double operator-(Produto &p);
		
		/**
		* Sobrecarga do operador de subtração.
		* @return Valor da subtração do preço entre um objeto produto e um double.
		*/
		double operator-(double &p);

		/**
		* Sobrecarga do operador de verificação de igualdade.
		* @return Verificação de igualde entre os códigos de barras de dois produtos.
		*/
		bool operator==(Produto &p);   
		
	private:
		/**
		* 
		*/
		virtual std::ostream& print(std::ostream&) const = 0;
};
#endif