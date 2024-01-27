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
		clsCarrito(int idUsuario);
		void anadirCarrito(int IDproducto,int cantidad,float precio);
		void quitarCarrito(int posCarrito);
		void mostrarCarrito();
		float calculaProducto(int pos);
};

#endif

