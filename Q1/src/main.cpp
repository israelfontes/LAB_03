/**
* @file     main.cpp
* @brief    Arquivo principal do programa.
* @author   Israel Medeiros Fontes
* @since    19/10/2017
* @date     20/10/2017
*/

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "produto.h"
#include "fruta.h"
#include "bebida.h"
#include "roupa.h"

using namespace std;

std::vector<shared_ptr<Produto>> lista; /**< Lista de produtos. */

ifstream roupas; /**< fstream arquivo a ser carregado os produtos do tipo Roupa.*/
ifstream bebidas; /**< fstream arquivo a ser carregado os produtos do tipo Bebida.*/
ifstream frutas; /**< fstream arquivo a ser carregado os produtos do tipo Fruta.*/

/**
* Adiciona um produto a lista de produtos caso ele já não tenha sido adicionado.
* @param p Produto a ser adicionado.
* @return -1 se o produto já existe na lista e 1 caso ela seja adicionado com sucesso.
*/
int addProduto(shared_ptr<Produto> p){
	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		if((*i)->getCodBarras() == (*p).getCodBarras()){
			cout << "(Erro !) Esse produto já foi cadastrado." << endl;
			return -1;	
		}
	}

	lista.push_back(p);
	return 1;
}

/**
* Carrega os produtos dos respectivos arquivos na lista de produtos caso eles não tenham sido adicionados.
*/
void carregarProdutos(){

	roupas.open("data/roupas.dat");
	if(!roupas)
		cout << "Erro ao abrir o arquivo roupas.dat" << endl;
	bebidas.open("data/bebidas.dat");
	if(!bebidas)
		cout << "Erro ao abrir o arquivo bebidas.dat" << endl;
	frutas.open("data/frutas.dat");
	if(!frutas)
		cout << "Erro ao abrir o arquivo frutas.dat" << endl;

	string temp;
	while(!roupas.eof()){
		Roupa roupa;
		roupas >> temp; 
		roupa.setCodBarras(temp);
		roupas >> temp;
		roupa.setDescricao(temp);
		roupas >> temp;
		roupa.setPreco(stod(temp));
		roupas >> temp;
		roupa.setMarca(temp);
		roupas >> temp;
		roupa.setSexo(temp[0]);
		roupas >> temp;
		roupa.setTamanho(temp);
		addProduto(make_shared<Roupa>(roupa));
	}

	while(!bebidas.eof()){
		Bebida bebida;
		bebidas >> temp; 
		bebida.setCodBarras(temp);
		bebidas >> temp;
		bebida.setDescricao(temp);
		bebidas >> temp;
		bebida.setPreco(stod(temp));
		bebidas >> temp;
		bebida.setTeor(stod(temp));
		addProduto(make_shared<Bebida>(bebida));
	}

	while(!frutas.eof()){
		Fruta fruta;
		frutas >> temp; 
		fruta.setCodBarras(temp);
		frutas >> temp;
		fruta.setDescricao(temp);
		frutas >> temp;
		fruta.setPreco(stod(temp));
		frutas >> temp;
		fruta.setLote(temp);
		frutas >> temp;
		fruta.setValidade(stoi(temp));
		addProduto(make_shared<Fruta>(fruta));
	}

	roupas.close();
	bebidas.close();
	frutas.close();

}


/// Metodo principal para testar as funções.
int main(int argc, char const *argv[])
{
	addProduto(make_shared<Fruta>("001002002-33","Maca verde",8.70,"01/10/2017",18));
	addProduto(make_shared<Fruta>("001002002-33","Laranja",4.75,"23/09/2017",15));
	addProduto(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	addProduto(make_shared<Bebida>("001002006-66", "Cerveja", 5.12, 12.6));
	cout << endl;

	carregarProdutos();

	double soma_total;
	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;
		soma_total = (**i) + soma_total;	
	}

	cout << "Soma total: R$" << soma_total << endl; 
	cout << "Subtração entre dois produtos: R$" << *lista[0] - *lista[1] << endl;
	cout << "Soma entre dois produtos: R$" << *lista[0] + *lista[1] << endl;  
	return 0;
}