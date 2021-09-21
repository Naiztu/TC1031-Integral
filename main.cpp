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

	vector<Pedido> pedidos;
	Sorts<Pedido> sorts;

	pedidos.push_back(Pedido(1, "Deli", 304));
	pedidos.push_back(Pedido(2, "Auto", 84));
	pedidos.push_back(Pedido(3, "Most", 408));

	sorts.ordenaMerge(pedidos);

	//pantalla de cocina con prioridad actualizada
	cout << "\nID\tMedio\tTotal";
    for(Pedido i : pedidos){
        cout << i.printLista();
    }
    cout << "\n";

}

// g++ sorts.h pedido.h main.cpp 