#ifndef _CONTA_H_
#define _CONTA_H_
#include <istream>
#include <vector>
#include <string>
#include "movimentacao.hpp"

/**
* @file     conta.hpp
* @brief    Classe Conta que abstraí as características de uma conta bancária.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     23/10/2017
*/


class Conta{

	private:
		std::string c_numero; /**< Número da conta. */
		std::string c_agencia; /**< Agência da conta. */
		std::string c_status; /**< Status da conta (Especial ou não) */
		std::vector<Movimentacao> c_movimentacoes; /**< Conjunto de movimentações da conta. */
		double c_saldo; /**< Saldo da conta. */

	public:

		/// Construtor padrão.
		Conta();

		/** 
		* Construtor parametrizado.
		* @param _numero Número da conta em construção.
		* @param _agencia Número da agência da conta em construção.
		* @param _status Status da conta em construção.
		* @param _saldo Saldo da conta em construção.
		*/
		Conta(std::string _numero, std::string _agencia, std::string _status, double _saldo);

		/// Destrutor virtual para que a conta seja destruída quando os objetos derivados forem destruídos.
		virtual ~Conta();

		/** @return Número da conta. */
		std::string getNumero();

		/** @return Número da agência da conta. */
		std::string getAgencia();

		/** @return Status da conta. */
		std::string getStatus();

		/** @return Saldo da conta. */
		double getSaldo();

		/** @return Ponteiro para as Movimentações da conta. */
		std::vector<Movimentacao> * getMovimentacoes();

		/**
		* Altera o número da conta. 
		* @param _numero Novo número da conta.
		*/
		void setNumero(std::string const _numero);

		/**
		* Altera a agência da conta.
		* @param _agencia Nova agência. 
		*/
		void setAgencia(std::string const _agencia);
		
		/**
		* Altera o status da conta.
		* @param _status Novo status da conta.
		*/
		void setStatus(std::string const _status);

		/**
		* Altera o saldo da conta.
		* @param _saldo Novo saldo da conta.
		*/
		void setSaldo(double const _saldo);

		/**
		* Adiciona uma movimentação bancária a conta.
		* @param _descricao Descrição da movimentação.
		* @param _tipo Tipo da movimentação (débito ou crédito).
		* @param _valor Valor da movimentação.
		*/
		void addMovimentacao(std::string const _descricao, std::string const _tipo, double const _valor);

		/**
		* Sobrecarga do operador de extração.
		* @param i objeto istream
		* @param conta Objeto conta a ser extraído.
		* @return Objeto istream
		*/
		friend std::istream& operator>> (std::istream &i, Conta &conta);

		/**
		* Sobrecarga do operador de inserção.
		* @param o objeto ostream.
		* @param conta Objeto conta a ser extraído.
		* @return Objeto ostream.
		*/
		friend std::ostream& operator<< (std::ostream &o, Conta &conta);  

		/**
		* Sobrecarga do operador de igualdade. Compara se duas contas são iguais.
		* @param conta Objeto conta a ser comparado.
		* @return Valor booleano da comparação de this e conta.
		*/
		bool operator== (Conta &conta);

		/**
		* Metodo virtual para que as classes derivadas implementem e possam responder ao operador de extração.
		* @param i Objeto istream a ser utilizado na extração das informações.
		* @return istream com os dados lidos.
		*/
		virtual std::istream& read(std::istream&)=0;
	
		/**
		* Metodo virtual para que as classes derivadas implementem e possam responder ao operador de inserção.
		* @param o Obejto ostream a ser preenchido.
		* @return O objeto ostream com as informações.
		*/		
		virtual std::ostream& print(std::ostream&) const = 0 ;

		/// Gambiarra
		virtual double getLimiteDisp()=0;

		/// Gambiarra
 		virtual void setLimiteDisp(double const _limite_disp)=0;

};
#endif