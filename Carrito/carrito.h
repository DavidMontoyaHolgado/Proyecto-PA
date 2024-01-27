#ifndef CARRITO_H
#define CARRITO_H
#include<iostream>
#include<fstream>

using namespace std; 

class clsCarrito{
	private:
		int idUser;
	public:	
		clsCarrito(int idUsuario);
		void anadirCarrito(int IDproducto,int cantidad,float precio);
		void quitarCarrito(int posCarrito);
		void mostrarCarrito();
		double calculaTotal();
		float calculaProducto(int pos);
};

#endif

