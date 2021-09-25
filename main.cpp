//
// main.h
//
//  Created on: 01/09/2021
//      Author: Angel Rico
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include "sorts.h"
#include "Pedido.h"

using namespace std;

int main(int argc, char* argv[]) {

	vector<Pedido*> pedidos;
	Sorts<Pedido*> sorts;

	pedidos.push_back(new Pedido(1, "Deli", 304));
	pedidos.push_back(new Pedido(2, "Auto", 84));
	pedidos.push_back(new Pedido(3, "Most", 408));
	pedidos.push_back(new Pedido(1, "Deli", 874));
	pedidos.push_back(new Pedido(2, "Auto", 53));
	pedidos.push_back(new Pedido(3, "Most", 897));
	pedidos.push_back(new Pedido(1, "Deli", 537));
	pedidos.push_back(new Pedido(2, "Auto", 12));
	pedidos.push_back(new Pedido(3, "Most", 56));
	pedidos.push_back(new Pedido(1, "Deli", 134));
	pedidos.push_back(new Pedido(2, "Auto", 209));
	pedidos.push_back(new Pedido(3, "Most", 953));

	sorts.ordenaMerge(pedidos);

	//pantalla de cocina con prioridad actualizada
	cout << "\nID\tMedio\tTotal";
    for(Pedido *i : pedidos){
        cout << i->printLista();
    }
    cout << "\n";

}

// g++ main.cpp 