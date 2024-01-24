#include<iostream>
#include<fstream>

using namespace std; 

class Carrito{
	private:
		struct Producto{
			string nombre;
			double precio;
	          int NPro;
		};
		
		// const int c=100;
		 Producto compras[100];
		int cantidad;
	public:	
	 Carrito();
	 void anadirCarrito(string,double);
	 void quitarCarrito(int);
	 void mostrarCarrito();
	 double calculaTotal();
	 int getCompra();
	 int getCantidad();		
};

