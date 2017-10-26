#ifndef _CORRENTE_H_
#define _CORRENTE_H_
#include <string>
#include "conta.hpp"

/**
* @file     c_corrente.h
* @brief    Classe ContaCorrente que abstraí uma uma Conta Corrente Bancária.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

class ContaCorrente : public Conta
{
	private:
		double cc_limite; /**< Limite da Conta Corrente. */
		double cc_limite_disp; /**< Limite disponível na Conta Corrente. */

	public:
		///Construtor padrão.
		ContaCorrente();

		/**
		* Construtor parametrizado da Conta Corrente em construção.
		* @param _numero Número da conta corrente em construção.
		* @param _agencia Agência da conta corrente em construção.
		* @param _status Status da conta corrente em construção.
		* @param _saldo Saldo da conta corrente em construção.
		* @param _limite Limite da conta corrente em construção.
		*/
		ContaCorrente(std::string _numero, std::string _agencia, std::string _status, double _saldo, double _limite);

		/// Destrutor padrão da conta corrente.
		~ContaCorrente();

		/** @return Limite da conta corrente. */
		double getLimite();

		/** @return Limite Disponível na conta corrente. */ 
		double getLimiteDisp();

		/**
		* Altera o limite da conta corrente. 
		* @param _limite Novo limite da conta corrente.
		*/
		void setLimite(double const _limite);

		/**
		* Altera o limite disponível na conta corrente.
		* @param _limite_disp Novo limite disponível na conta corrente.
		*/
		void setLimiteDisp(double const _limite_disp);

		/**
		* Preenche um obejto ostream com os dados da classe ContaCorrente.
		* @param o Obejto ostream a ser preenchido.
		* @return O objeto ostream com as informações.
		*/
		std::ostream& print(std::ostream &o) const;

		/**
		* Lê as informações da classe ContaCorrente.
		* @param i Objeto istream a ser utilizado na extração das informações.
		* @return istream com os dados lidos.
		*/
		std::istream& read(std::istream &i);
 };
 #endif