#ifndef APP_H
#define APP_H

//
// App.h
//
//  Created on: 01/10/2021
//      Author: Angel Rico
//

#include <iostream>
#include "Pedido.h"
#include "Product.h"
#include "sorts.h"
#include "splay.h"
#include <vector>
#include <stack>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

/**
 * App: main structure
 * @file: app.h
 * @author: Angel Rico
 */
class App{
    private:
		void loadVectorPedido(vector<Pedido*>&);
		void loadListProducto(list<Product*>&);
		void loadTree(SplayTree<Product>&);

		stack<Pedido*> pedidos; 
		list<Product*> productos;
		SplayTree<Product> recomendaciones;

		vector<Pedido*> stackToVector(stack<Pedido*>);
		stack<Pedido*>  vectorToStack(vector<Pedido*>);

        int menuMain();
		void opcion1();
		void listaProducto();
		void opcion3();
		bool validaOpcion(int op,int inf, int sup);
    public:
        App(){}
        ~App();
        void start();
};


/**
 * @brief destructor
 */
App::~App(){
	while (!pedidos.empty()) {
        pedidos.top()->printLista();
        pedidos.pop();
    }
	
}


void App::start(){
    Sorts<Pedido*> sorts;
	vector<Pedido*> auxvector;

	loadVectorPedido(auxvector);
	sorts.ordenaMerge(auxvector);

	pedidos = vectorToStack(auxvector);
	
	loadListProducto(productos);
	loadTree(recomendaciones);

	int op = 0;
	do{
		op = menuMain();
		switch (op){
		case 1:
			opcion1();
			break;
		case 2:
			listaProducto();
			break;
		case 3:
			opcion3();
			break;
		default:
			cout << "\n              ¡¡¡ADIOS!!\n";
			break;
		}

	} while(op != 4);

}

stack<Pedido*> App::vectorToStack(vector<Pedido*> v){
	stack<Pedido*> s;
	for (int i = v.size() - 1; i >= 0; i--)	s.push(v[i]);
	return s;
}

vector<Pedido*> App::stackToVector(stack<Pedido*> s){
	vector<Pedido*> v;
	while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
	return v;
}


int App::menuMain(){
	bool ban = true;
    int op=0; 

    while (ban){
        cout << "\n*******************************************";
        cout << "\n                MENU:\n";
        cout << "*******************************************\n";
        cout << "1. Lista pedidos\n";
        cout << "2. Generar recomendacion \n";
		cout << "3. Lista productos \n";
        cout << "4. Salir \n";
        cout << "*******************************************\n";
        
        cout << "\nOpción: "; cin>>op;
        ban = validaOpcion(op,1,4);
    } 

    return op;
}

bool App::validaOpcion(int op,int inf, int sup){
    bool ban = true;
    if ((op>=inf)&&(op<=sup)){
        ban = false;
    }else{
        cout << "\n   ¡¡¡Introduce una opción valida!!! \n";
    }
    return ban;
}


/**
 * @brief load information to vector specific.
 */
void App::loadVectorPedido(vector<Pedido*> &v){
	string line;
	ifstream file;

	file.open("examplesPedidos.csv");
	getline(file, line);

	int id;
	string medio;
	long total;

	while (getline(file, line)){
		stringstream ss(line);
		ss >> id >> medio >> total;
		v.push_back(new Pedido(id, medio, total));
	}
}

void App::loadListProducto(list<Product*> &l){
	string line;
	ifstream file;

	file.open("examplesProducts.csv");
	getline(file, line);

	string id, name;
    int numConection;
    float price;

	while (getline(file, line)){
		stringstream ss(line);
		ss >> id >> name >> numConection >> price;
		l.push_back(new Product(id, name, numConection, price));
	}
}

void App::loadTree(SplayTree<Product> &t){
	list<Product*>::iterator it;
	for(it = productos.begin(); it != productos.end(); ++it)	t.add(**it);
}

void App::opcion1(){
	cout << "\nID\tMedio\tTotal";
	vector<Pedido*> aux = stackToVector(pedidos);
	while (!pedidos.empty()) {
		cout << pedidos.top()->printLista();
		pedidos.pop();
	}
	pedidos = vectorToStack(aux);
	cout << "\n";
}

void App::listaProducto(){
	cout << "\n\tID\tNombre\t\tPrecio";
	list<Product*>::iterator it;
	int i=1;
	for(it = productos.begin(); it != productos.end(); ++it){
		cout << "\n" << i << ".-  " << (*it)->printLista();
		i++;
	}
		
}


void App::opcion3(){
	listaProducto();
	int i, index = 1;
	cout << "\n\nNumero:"; cin >> i;
	list<Product*>::iterator it = productos.begin();
	while (i != index){
		++it;
		index++;
	}
	recomendaciones.find(**it);
	cout << recomendaciones.print_tree();
}

#endif