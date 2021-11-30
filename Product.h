#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product{
    private:
        string id, name;
        int numConection;
        float price;
    public:
        Product(string, string, int, float);
        string printLista();
        void setNumConexion(int n){ numConection = n;}
        string getName() const { return name;}
        bool  operator< (Product &p){ return (numConection < p.numConection);  }
        bool  operator> (Product &p){ return (numConection > p.numConection);  }
        bool operator== (Product &p){ return (numConection == p.numConection); }
};

Product::Product(string _id, string _name, int _numConection, float _price) : 
                id(_id), name(_name), numConection(_numConection), price(_price) {}

/**
 * @brief object impression
 */
string Product::printLista(){
    stringstream aux;
    aux << id << "\t" << name;
    if (name.length() <= 7) aux<< "\t";
    aux<< "\t" << price;
    return aux.str();
}

#endif