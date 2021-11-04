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
#include <sstream>

using namespace std;

/**
 * Pedido: abstract object for order
 * @file: Pedido.h
 * @author: Angel Rico
 */
class Pedido{
	private:
        long total;
        string medio;
        int Id;
		void prioridad();
	public:
        int numPrioridad; 
		Pedido(){}
        Pedido(int, string, long);
        string printLista();
        bool operator< (Pedido &p){return (numPrioridad < p.numPrioridad);}
        bool operator> (Pedido &p){return (numPrioridad > p.numPrioridad);}
};

/**
 * @brief Construct a new Pedido object
 * 
 * @param _Id unique identifier.
 * @param _medio means where the order was made.
 * @param _total ticket total.
 */
Pedido::Pedido(int _Id, string _medio, long _total){
    Id = _Id;
    medio = _medio;
    total = _total;
    prioridad();
}

/**
 * @brief priority calculation
 */
void Pedido::prioridad(){
    if (medio == "Auto"){
        numPrioridad = 1; //Maxima prioridad
    }else if (medio == "Most"){
        numPrioridad = 2; //Media prioridad
    }else if (medio == "Deli"){
        numPrioridad = 3; //Baja prioridad
    }
}

/**
 * @brief object impression
 */
string Pedido::printLista(){
    stringstream aux;
    aux << "\n" << Id << "\t" << medio << "\t" << total;
    return aux.str();
}
#endif