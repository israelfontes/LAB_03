#ifndef _ROUPA_H_
#define _ROUPA_H_
#include "produto.h"

/**
* @file     roupa.h
* @brief    Classe Roupa, ela representa os membros de um objeto do tipo roupa, herdando as características da classe Produto.
* @author   Israel Medeiros Fontes
* @since    19/10/2017
* @date     20/10/2017
*/

class Roupa : public Produto
{
	public:
		/// Construtor padrão.
		Roupa();

		/**
		* Construtor parametrizado.
		* @param _codigo Código de barras da roupa.
		* @param _descricao Descrição da roupa.
		* @param _preco Preço da roupa.
		* @param _marca Marca da roupa.
		* @param _sexo Sexo que a roupa veste.
		* @param _tamanho da roupa. 
		*/
		Roupa(std::string _codigo, std::string _descricao, double _preco, std::string _marca, char _sexo, std::string _tamanho);

		/// Destrutor padrão.
		~Roupa();

	private:
		std::string m_marca; /**< Marca da roupa. */
		std::string m_tamanho; /**< Tamanho da roupa. */
		char m_sexo; /**< Sexo que a roupa veste. */

	public:
		/// ---Getters

		/** 
		* @return Marca da roupa.
		*/ 
		std::string getMarca();
		
		/**
		* @return Tamanho da roupa.
		*/
		std::string getTamanha();
		/**
		* @return Sexo que a roupa veste.
		*/
		char getSexo();
		
		/// ---Setters

		/**
		* Altera a marca da roupa.
		* @param _marca Nova marca da roupa.
		*/
		void setMarca(std::string _marca);
	
		/**
		* Altera o tamanho da roupa.
		* @param _tamanho Novo tamanho da roupa.
		*/
		void setTamanho(std::string _tamanho);
		
		/**
		* Altera o sexo que a roupa veste.
		* @param _sexo Novo sexo que a roupa veste.
		*/
		void setSexo(char _sexo);

		// 	friend std::ostream& operator<< (std::ostream &o, Roupa &t);
	
	private:
		std::ostream& print(std::ostream &o) const;

};

#endif