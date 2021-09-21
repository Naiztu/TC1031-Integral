#ifndef PEDIDO_H
#define PEDIDO_H

//
// Pedido.h
//
//  Created on: 01/09/2021
//      Author: Angel Rico
//

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Pedido{
	private:
        long total;
        string medio;
        int Id;
		void prioridad();
	public:
		Pedido(){}
        Pedido(int, string, long);
        string printLista();
        int numPrioridad;
};

Pedido::Pedido(int _Id, string _medio, long _total){
    Id = _Id;
    medio = _medio;
    total = _total;
    prioridad();
}

void Pedido::prioridad(){
    if (medio == "Auto"){
        numPrioridad = 1; //Maxima prioridad
    }else if (medio == "Most"){
        numPrioridad = 2; //Media prioridad
    }else if (medio == "Deli"){
        numPrioridad = 3; //Baja prioridad
    }
}

string Pedido::printLista(){
    stringstream aux;
    aux << "\n" << Id << "\t" << medio << "\t" << total << "\t" << numPrioridad;
    return aux.str();
}

#endif