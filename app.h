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
#include <array>
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
		int numPedidos = 0, numProductos = 0;

		void loadVectorPedido(vector<Pedido*>&);
		void loadListProducto(vector<Product*>&);
		void loadTree(SplayTree<Product>&);

		stack<Pedido*> pedidos; 
		vector<Product*> productos;
		SplayTree<Product> recomendaciones;
		list<string> listaTipos;

		vector<Pedido*> stackToVector(stack<Pedido*>);
		stack<Pedido*> vectorToStack(vector<Pedido*>);
		void ordenaStack(stack<Pedido*>&, vector<Pedido*>);

        int menuMain();
		int menuPedido();
		void opcion1();
		void opcion2();
		void opcion3();
		string listaProducto();
		bool validaOpcion(int op,int inf, int sup);
		void loadFileNew();

		void casosDePrueba();
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
        Pedido *aux = pedidos.top();
        pedidos.pop();
		delete aux;
    }
	for (auto item : productos){
		delete item;
	}
	
}

void App::start(){
	vector<Pedido*> auxvector;
	loadVectorPedido(auxvector);
	ordenaStack(pedidos, auxvector);
	
	loadListProducto(productos);
	loadTree(recomendaciones);
	casosDePrueba();
	int op = 0;
	do{
		op = menuMain();
		switch (op){
		case 1:
			/*Caso de prueba en metodo opcion 1*/
			opcion1();
			break;
		case 2:
			/*
			Caso de prueba:
			*******************************************
							MENU:
			*******************************************
			1. Lista pedidos
			2. Lista productos
			3. Sugerencia del dia
			4. Salir
			*******************************************

			Opci├│n: 2

					ID      Nombre          Precio
			1.-  	0  		bigMac          65.5
			2.-  	1  		McPollo         55
			3.-  	2  		McDoble         93.5
			4.-  	3 		Deluxe          130.5
			5.-  	4  		HambQueso       50.5
			6.-  	5  		CBO             114.5
			7.-  	6  		Crispy          78.5
			8.-  	7  		McNifica        68.5
			9.-  	8  		CuartoDLibra    76
			*/
			opcion2();
			break;
		case 3:
			/*
			Caso de prueba:
			*******************************************
							MENU:
			*******************************************
			1. Lista pedidos
			2. Lista productos
			3. Sugerencia del dia
			4. Salir
			*******************************************

			Opci├│n: 3

					ID      Nombre          Precio
			1.-  	0  		bigMac          65.5
			2.-  	1  		McPollo         55
			3.-  	2  		McDoble         93.5
			4.-  	3 		Deluxe          130.5
			5.-  	4  		HambQueso       50.5
			6.-  	5  		CBO             114.5
			7.-  	6  		Crispy          78.5
			8.-  	7  		McNifica        68.5
			9.-  	8  		CuartoDLibra    76

			Ultimo pedido:5

			================================
			Ultimo Pedido:HambQueso
			sugerencias del dia:
			->Deluxe
			->McNifica
			->CBO
			->CuartoDLibra
			->McDoble
			->McPollo
			->bigMac
			->Crispy
			================================
			*/
			opcion3();
			break;
		default:
			loadFileNew();
			cout << "\n              ¡¡¡ADIOS!!\n";
			break;
		}

	} while(op != 4);

}

void App::opcion1(){
	int op = 0;
	bool ban = true;
	long total;
	string tipo;
	do{
		cout << "\nID\tMedio\tTotal";
		vector<Pedido*> aux = stackToVector(pedidos);
		for (auto item : aux) 
			cout << item->printLista();
		op = menuPedido();
		switch (op){
		case 1:
			/*
			Caso de prueba:
			*******************************************
							MENU:
			*******************************************
			1. Lista pedidos
			2. Lista productos
			3. Sugerencia del dia
			4. Salir
			*******************************************

			Opci├│n: 1 

			ID      Medio   Total
			13      Auto    586
			10      Auto    987
			7       Auto    325
			4       Auto    65
			1       Auto    352
			14      Most    98
			11      Most    456
			8       Most    67
			5       Most    234
			2       Most    46
			12      Deli    576
			9       Deli    86
			6       Deli    7523
			3       Deli    1254
			0       Deli    304
			*******************************************
			1. Agregar Pedido
			2. Eliminar Pedido
			3. Salir
			*******************************************

			Opci├│n: 1
			Tipo: Most
			Total: 324


			ID      Medio   Total
			1       Auto    352
			4       Auto    65
			7       Auto    325
			10      Auto    987
			13      Auto    586
			2       Most    46
			5       Most    234
			8       Most    67
			11      Most    456
			14      Most    98
			15      Most    324 <----- Agregado
			0       Deli    304
			3       Deli    1254
			6       Deli    7523
			9       Deli    86
			12      Deli    576
			*/
			do{
				cout << "Tipo: "; cin >> tipo;
				for (auto const&item: listaTipos)
					if(item == tipo) ban = false;
			} while (ban);
			cout << "Total: "; cin >> total;
			pedidos.push(new Pedido(numPedidos, tipo, total));
			ordenaStack(pedidos, stackToVector(pedidos));
			numPedidos++;
			cout << "\n";
			break;
		case 2:
			/*
			Caso de prueba:
			*******************************************
			1. Agregar Pedido
			2. Eliminar Pedido
			3. Salir
			*******************************************

			Opci├│n: 2

			Pedido entregado:
			1       Auto    352		<--- Eliminado 

			ID      Medio   Total
			4       Auto    65
			7       Auto    325
			10      Auto    987
			13      Auto    586
			2       Most    46
			5       Most    234
			8       Most    67
			11      Most    456
			14      Most    98
			15      Most    324
			0       Deli    304
			3       Deli    1254
			6       Deli    7523
			9       Deli    86
			12      Deli    576
			*/
			if (pedidos.size()!=0){
				cout << "\nPedido entregado: " << pedidos.top()->printLista() <<"\n";
				pedidos.pop();
			} else cout << "\n¡¡¡Ya no hay pedidos!!! \n" ;
			
			break;
		default:
			cout << "\n";
			break;
		}
	} while(op != 3);
}

void App::ordenaStack(stack<Pedido*> &s, vector<Pedido*> p){
	Sorts<Pedido*> sorts;
	
	sorts.ordenaMerge(p);
	s = vectorToStack(p);
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
        cout << "2. Lista productos \n";
		cout << "3. Sugerencia del dia\n";
        cout << "4. Salir \n";
        cout << "*******************************************\n";
        
        cout << "\nOpción: "; cin>>op;
        ban = validaOpcion(op,1,4);
    } 

    return op;
}

int App::menuPedido(){
	bool ban = true;
    int op=0; 

    while (ban){
        cout << "\n*******************************************\n";
        cout << "1. Agregar Pedido\n";
        cout << "2. Eliminar Pedido \n";
        cout << "3. Salir \n";
        cout << "*******************************************\n";
        
        cout << "\nOpción: "; cin>>op;
        ban = validaOpcion(op,1,3);
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

	string medio;
	long total;

	while (getline(file, line)){
		stringstream ss(line);
		ss >> medio >> total;
		v.push_back(new Pedido(numPedidos, medio, total));
		numPedidos++;
	}
	file.close();
	remove("examplesPedidos.csv");
}

void App::loadListProducto(vector<Product*> &l){
	string line;
	ifstream file;

	file.open("examplesProducts.csv");
	getline(file, line);

	string name;
    int numConection;
    float price;

	while (getline(file, line)){
		stringstream ss(line);
		ss >> name >> numConection >> price;
		l.push_back(new Product(to_string(numProductos), name, numConection, price));
		numProductos++;
	}
}

void App::loadTree(SplayTree<Product> &t){
	vector<Product*>::iterator it;
	vector<Product*> paux(productos);

	Sorts<Product*> s;

	s.ordenaMerge(paux);

	for(it = paux.begin(); it != paux.end(); ++it)	t.add(**it);
}



string App::listaProducto(){
	stringstream aux;
	aux << "\n\tID\tNombre\t\tPrecio";
	vector<Product*>::iterator it;
	int i=1;
	for(it = productos.begin(); it != productos.end(); ++it){
		aux << "\n" << i << ".-\t" << (*it)->printLista();
		i++;
	}	
	return aux.str();	
}

void App::opcion2(){
	cout << listaProducto();
}

void App::opcion3(){
	cout << listaProducto();
	int i;
	bool ban = true;

    while (ban){
        cout << "\n\nUltimo pedido:"; cin >> i;
        ban = validaOpcion(i,1,productos.size());
    } 
	recomendaciones.find(*productos[i-1]);
	cout << recomendaciones.print_tree();
}

void App::loadFileNew(){
	fstream CreateFile("examplesPedidos.csv", ios::out);
	CreateFile << "typeOfService\tbill"<<endl;
	for (auto item:stackToVector(pedidos)){
		CreateFile << item->getTipo()<<"\t"<<item->getTotal()<< endl;
	}
}

void App::casosDePrueba(){
	cout << "\n*******************************************";
    cout << "\n                Casos de prueba:\n";
    cout << "*******************************************\n\n";

	listaTipos.push_back("Deli");
	listaTipos.push_back("Most");
	listaTipos.push_back("Auto");
	string aux0 = "Deli\tMost\tAuto\t";
	stringstream aux00;
	for (auto item: listaTipos) aux00 << item << "\t";
	cout << "\n" <<"2.- Lista Tipos esperada: " << aux0 << "\n programa: " << aux00.str() << "\n";
	cout <<	(!aux0.compare(aux00.str()) ? "success\n" : "fail\n");

	//Se funciona en la primera corrida
	string aux1 = "\n\tID\tNombre\t\tPrecio\n1.-\t0\tbigMac\t\t65.5\n2.-\t1\tMcPollo\t\t55\n3.-\t2\tMcDoble\t\t93.5\n4.-\t3\tDeluxe\t\t130.5\n5.-\t4\tHambQueso\t50.5\n6.-\t5\tCBO\t\t114.5\n7.-\t6\tCrispy\t\t78.5\n8.-\t7\tMcNifica\t68.5\n9.-\t8\tCuartoDLibra\t76";
	cout << "\n" <<"2.- Lista Pedidos esperada: " << aux1 << "\n programa " << listaProducto() << "\n";
	cout <<	(!aux1.compare(listaProducto()) ? "success\n" : "fail\n");
	
	vector<Product*>::iterator it;
	vector<Product*> paux(productos);
	Sorts<Product*> s;
	s.ordenaMerge(paux);

	string aux2 = "HambQueso\tMcPollo\tCrispy\tCuartoDLibra\tbigMac\tMcNifica\tMcDoble\tDeluxe\tCBO\t";
	stringstream aux22;
	for (auto item: paux){
		aux22 << item->getName()<<"\t";
	}
	cout << "\n" <<"3.- Lista Productos ordenadas esperada: " << aux2 << "\n programa: " << aux22.str() << "\n";
	cout <<	(!aux2.compare(aux22.str()) ? "success\n" : "fail\n");

	//Solo funciona en la primera corridada
	string aux3="\n================================\nUltimo Pedido: bigMac\nSugerencias del dia:\n->CuartoDLibra\n->Deluxe\n->McNifica\n->CBO\n->McDoble\n->Crispy\n->McPollo\n->HambQueso\n================================\n";
	recomendaciones.find(*productos[0]);
	cout << "\n" <<"4.- Ultimos pedidos esperada: " << aux3 << "\n programa: " <<  recomendaciones.print_tree() << "\n";
	cout <<	(!aux3.compare( recomendaciones.print_tree()) ? "success\n" : "fail\n");
}

#endif