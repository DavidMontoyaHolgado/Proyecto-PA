#ifndef BUSCADO_H
#define BUSCADO_H
#include<iostream>
#include<fstream>

using namespace std;

class clsBuscador{
	private:
		string producto;
	public:
		clsBuscador();
		int* buscarProducto(string);	
      //void a�adirAlCarrito();	
};
#include "buscador.cpp"
#endif
