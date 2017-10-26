#ifndef _AGENCIA_H_
#define _AGENCIA_H_

/**
* @file     agencia.hpp
* @brief    Abstração das funcionalidades básicas de uma agência bancária.
* @author   Israel Medeiros Fontes
* @since    26/10/2017
* @date     26/10/2017
*/

#include <memory>
#include "conta.hpp"
using namespace std;
/**
* Cria um objeto do tipo Conta e armazena no conteiner contas.
* @param contas Conteiner que será armazenado a nova conta.
* @return True se a conta for criada com sucesso e false caso ela já exista.
*/
bool criarConta(std::vector<shared_ptr<Conta>> * contas);

/**
* Procura uma conta no conteiner contas.
* @param contas Conteiner onde será procurado.
* @return Ponteiro para conta que foi encontrado se foi encontrada, caso contrario, nullptr.
*/
std::shared_ptr<Conta> procurarConta(std::vector<shared_ptr<Conta>> * contas);

/**
* Realiza deposito em uma conta se for encontrada no conteiner.
* @param contas Conteiner onde contem a conta a ser realizado deposito.
* @return True caso o deposito seja realizado com sucesso (a conta tenha sido encontrado), false caso contrario. 
*/
bool realizarDeposito(std::vector<shared_ptr<Conta>> * contas);

/**
* Realiza saque em uma conta.
* @param contas Conteiner onde contem a conta a ser realizado o saque.
* @return True caso a conta exista e tenha saldo suficiente, false caso contrário.
*/
bool realizarSaque(std::vector<shared_ptr<Conta>> * contas);

/**
* Realiza transferencia de uma conta para outra.
* @param contas Conteiner onde contem as contas para tranferencia.
* @return True caso as contas existam e o remetente tenha saldo, false caso contrario.
*/
bool realizarTransferencia(std::vector<shared_ptr<Conta>> * contas);

/**
* Mostra extrato de conta.
* @param contas Conteiner onde contem a conta a ser apresentado o extrato.
*/
void extratoConta(std::vector<shared_ptr<Conta>> * contas);

/**
* Exclui conta.
* @param contas Conteiner onde contem a conta a ser excluida.
* @return True caso a conta exista e consiga ser excluida do conteiner, false caso contrario.
*/
bool excluirConta(std::vector<shared_ptr<Conta>> * contas);


#endif