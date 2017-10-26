/**
* @file     agencia.cpp
* @brief    Implementação da funções de uma agência bancária.
* @author   Israel Medeiros Fontes
* @since    23/10/2017
* @date     26/10/2017
*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "agencia.hpp"
#include "c_poupanca.hpp"
#include "c_corrente.hpp"
#include "conta.hpp"
#include "movimentacao.hpp"

using namespace std;

bool criarConta(vector<shared_ptr<Conta>> * contas){
	ContaCorrente cc_conta;
	ContaPoupanca cp_conta;

	int opcao;

	cout << "=================CRIANDO CONTA===============" << endl;
	cout << "Qual tipo da conta? (1) Corrente (2) Poupança" << endl;
	cin >> opcao;

	if(opcao == 1){
			
		cin >> cc_conta;
		for (auto i = contas->begin(); i != contas->end(); ++i)
		{
			if(**i == cc_conta){
				cout << "===============CONTA NÃO CRIADA==============" << endl;
				cout << "(Erro !) Essa conta já foi cadastrada!" << endl;
				cout << "=============================================" << endl;
				return criarConta(contas);	
			}
		}
		contas->push_back(make_shared<ContaCorrente>(cc_conta));
		cout << "=================CONTA CRIADA================" << endl;
		return true;
	
	}else if(opcao == 2){
		
		cin >> cp_conta;
		for (auto i = contas->begin(); i != contas->end(); ++i)
		{
			if(**i == cp_conta){
				cout << "===============CONTA NÃO CRIADA==============" << endl;
				cout << "(Erro !) Essa conta já foi cadastrada!" << endl;
				cout << "=============================================" << endl;
				return criarConta(contas);	
			}
		}
		contas->push_back(make_shared<ContaPoupanca>(cp_conta));
		cout << "=================CONTA CRIADA================" << endl;
		return true;

	}
	cout << "Opção inválida." << endl;
	return criarConta(contas);
	
}

shared_ptr<Conta> procurarConta(vector<shared_ptr<Conta>> * contas){
	
	std::string n_string, a_string;

	cout << "Digite o número da conta: ";
	cin >> n_string;

	cout << "Digite a agência: ";
	cin >> a_string;

	for (auto i = contas->begin(); i != contas->end(); ++i){
		if(not n_string.compare((**i).getNumero()) and not a_string.compare((**i).getAgencia()))
			return *i;
	}
	return nullptr;
}

bool realizarDeposito(vector<shared_ptr<Conta>> * contas){
	shared_ptr<Conta> conta;

	cout << "==================DÉPOSITO===================" << endl;

	conta = procurarConta(contas);
	if(conta != nullptr){
		double valor;
		
		cout << "Digite o valor para déposito: R$";
		cin >> valor;

		conta->setSaldo(conta->getSaldo()+valor);
		conta->addMovimentacao("Déposito", "Crédito", valor);

		cout << "=============DÉPOSITO REALIZADO==============" << endl;
		return true;
	}else{
		cout << "===========DÉPOSITO NÃO REALIZADO============" << endl;
		cout << "(Erro !) A conta não exitse." << endl;
		return false;
	}
}

bool realizarSaque(vector<shared_ptr<Conta>> * contas){
	shared_ptr<Conta> conta;
	
	cout << "===================SAQUE=====================" << endl;

	conta = procurarConta(contas);

	if(conta != nullptr){
		double valor;
		cout << "Digite o valor do saque:";
		cin >> valor;

		if(conta->getSaldo() < 0){
			
			if(conta->getLimiteDisp() >= valor){
				conta->setLimiteDisp(conta->getLimiteDisp()-valor);
				conta->setSaldo(conta->getSaldo()-valor);
				conta->addMovimentacao("Saque", "Débito", valor);
				cout << "===============SAQUE REALIZADO===============" << endl;
				return true;
			}else{
				cout << "=============SAQUE NÃO REALIZADO=============" << endl;
				cout << "A conta não tem saldo suficiente." << endl;
				cout << "=============================================" << endl;
				return false;
			}

		}else if(valor <= conta->getSaldo()+conta->getLimiteDisp()){
			conta->setSaldo(conta->getSaldo()-valor);
			if(conta->getSaldo() < 0)
				conta->setLimiteDisp(conta->getLimiteDisp()+conta->getSaldo());	
			
			conta->addMovimentacao("Saque", "Débito", valor);
			cout << "===============SAQUE REALIZADO===============" << endl;
			return true;
		}else{
			cout << "=============SAQUE NÃO REALIZADO=============" << endl;
			cout << "A conta não tem saldo suficiente." << endl;
			cout << "=============================================" << endl;
			return false;
		}	
	}else{
		cout << "=============SAQUE NÃO REALIZADO=============" << endl;
		cout << "A conta não existe." << endl;
		cout << "=============================================" << endl;
		return false;
	}
	return true;
}

bool realizarTransferencia(vector<shared_ptr<Conta>> * contas){
 
	shared_ptr<Conta> conta_r, conta_d;

	cout << "================TRANSFERÊNCIA================" << endl;
	
	conta_r = procurarConta(contas);

	if(conta_r != nullptr){
		
		cout << "Digite o valor da transferência: R$";
		double valor;
		cin >> valor;

		if(valor <= conta_r->getSaldo()+conta_r->getLimiteDisp()){
			
			conta_d = procurarConta(contas);

			if(conta_d != nullptr){

				conta_r->setSaldo(conta_r->getSaldo()-valor);
			
				if(conta_r->getSaldo() < 0)
					conta_r->setLimiteDisp(conta_r->getLimiteDisp()+conta_r->getSaldo());
			
				conta_d->setSaldo(conta_d->getSaldo()+valor);
				conta_r->addMovimentacao("Transferência", "Débito", valor);
				conta_d->addMovimentacao("Transferência", "Crédito", valor);
				cout << "============TRANSFERÊNCIA REALIZADA==========" << endl;
				return true;

			}else{
				cout << "==========TRANSFERÊNCIA NÃO REALIZADA========" << endl;
				cout << "(Erro !) A conta destino não existe." << endl;
				cout << "=============================================" << endl;
				return false;
			}
		}else{
			cout << "==========TRANSFERÊNCIA NÃO REALIZADA========" << endl;
			cout << "(Erro !) A conta não possui saldo suficiente." << endl;
			cout << "=============================================" << endl;
			return false;
		}

	}else{
		cout << "==========TRANSFERÊNCIA NÃO REALIZADA========" << endl;
		cout << "(Erro !) A conta remetente não exitse." << endl;
		cout << "=============================================" << endl;				
		return false;
	}
}

void extratoConta(vector<shared_ptr<Conta>> * contas){
	shared_ptr<Conta> conta;
	cout << "====================EXTRATO==================" << endl;
	conta = procurarConta(contas);

	if(conta != nullptr){
		cout << "=============================================" << endl;

		cout << *conta;
		for(auto i = conta->getMovimentacoes()->begin(); i < conta->getMovimentacoes()->end(); ++i){
			cout << "==================MOVIMENTAÇÃO===============" << endl;
			cout << *i;
			cout << "=============================================" << endl;
		}
	}else{
		cout << "============CONTA NÃO ENCONTRADA=============" << endl;
	}
}

bool excluirConta(vector<shared_ptr<Conta>> * contas){
	string n_string, a_string;

	cout << "================EXCLUIR CONTA================" << endl;
	cout << "Digite o número da conta: ";
	cin >> n_string;
	cout << "Digite o número da agência:";
	cin >> a_string;

	for(auto i = contas->begin(); i < contas->end(); ++i){
		if(not n_string.compare((**i).getNumero()) and not a_string.compare((**i).getAgencia())){
			contas->erase(i);
			cout << "================CONTA EXCLUIDA===============" << endl;
			return true;
		}
	}

	cout << "================CONTA NÃO ENCONTRADA=============" << endl;	
	return false;
}