#ifndef _POUPANCA_H_
#define _POUPANCA_H_
#include "conta.hpp"

/**
* @file     c_poupanca.hpp
* @brief    Classe ContaPoupanca, abstraí uma conta do tipo poupança.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/

class ContaPoupanca : public Conta
{
	private:
		double p_taxa_juros; /**< Taxa de juros da conta poupança. */

	public:

		///Construtor padrão.
		ContaPoupanca();

		///Destrutor padrão.
		~ContaPoupanca();
		
		/** 
		* Construtor parametrizado.
		* @param _numero Número da conta poupança em construção.
		* @param _agencia Número da agência da conta poupança em construção.
		* @param _status Status da conta poupança em construção.
		* @param _saldo Saldo da poupança conta em construção.
		* @param _taxa_juros Taxa de juros da conta poupança em construção.
		*/
		ContaPoupanca(std::string _numero, std::string _agencia, std::string _status, double _saldo, double _taxa_juros);

		/* @return Taxa de juros da conta poupança. */
		double getTaxa();

		/**
		* Altera a taxa de juros da conta poupança. 
		* @param Nova taxa de juros da conta poupança.
		*/
		void setTaxa(double const _taxa_juros);

		std::ostream& print(std::ostream &o) const;

		double getLimite();
		
		std::istream& read(std::istream &i);
};
#endif