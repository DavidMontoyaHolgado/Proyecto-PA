#ifndef CARRITO_H
#define CARRITO_H
#include<iostream>
#include<fstream>

using namespace std; 

class clsCarrito{
	private:
		int idUser;
		string ruta;
	public:	
		clsCarrito(int id);
		void anadirCarrito(int IDproducto,int cantidad,float precio);
		void quitarCarrito(int posCarrito);
		int getIdProducto(int);
		void mostrarCarrito();
		float calculaProducto(int pos);
};

#include "carrito.cpp"
#endif

