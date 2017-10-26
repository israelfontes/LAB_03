#include <iostream>
#include <memory>

#include "agencia.hpp"
#include "conta.hpp"


using namespace std;

vector<shared_ptr<Conta>> contas;


int main(int argc, char const *argv[]){
	int opcao;

	while(1){
		cout << "+++++++++++++++ MENU ++++++++++++++++" << endl;
		cout << "(1) Cadastrar conta" << endl;
		cout << "(2) Realizar saque" << endl;
		cout << "(3) Realizar transferência" << endl;
		cout << "(4) Extrato de conta" << endl;
		cout << "(6) Excluir conta" << endl;
		cout << "(0) Sair" << endl;

		cin >> opcao;

		switch(opcao){
			case 1:
				criarConta(&contas);
				break;
			case 2:
				realizarSaque(&contas);
				break;
			case 3:
				realizarTransferencia(&contas);
				break;
			case 4:
				extratoConta(&contas);
				break;
			case 5:
				realizarDeposito(&contas);
				break;
			case 6:
				excluirConta(&contas);
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "Opção inválida." << endl;
		};
	}

	return 0;
}