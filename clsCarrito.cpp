#include<iostream>
#include<string>
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
	 void anadirCarrito(string,double,int);
	 void quitarCarrito(int);
	 void mostrarCarrito();
	 int getCompra();
	 int getCantidad();		
};

Carrito::Carrito(){

    cantidad=0;
     
   
}

void Carrito::anadirCarrito(string nombre,double precio,int Npro){
	
	if(cantidad<Npro){
		compras[cantidad].nombre =nombre;
		compras[cantidad].precio = precio;
		cantidad++;
		cout<<" Producto agregado al carrito: "<<nombre<<endl;
	}else{
		cout<<"El carrito esta lleno no se pueden agregar mas productos.  "<<endl;
	}
}

void Carrito::quitarCarrito(int indice){
	if(indice>=0 and indice<cantidad){
		
	    cout << "Producto eliminado del carrito: " << compras[indice-1].nombre << endl;
	     
	     for(int i=indice-1;i<cantidad-1;i++){
	     	
	     	compras[i]=compras[i+1];
		 }
		 cantidad--;
	} else{
		
		cout<<"Indeice de producto no valido. "<<endl;
	}
	
}
 
 void Carrito::mostrarCarrito(){
 	
 	   cout << "Carrito de compras:" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "Nombre: " << compras[i].nombre << ", Precio: " << compras[i].precio << endl;
        }
        cout << "Total de productos: " << cantidad << endl;
 }




int main(){
	
	string producto;
	int precio;
	
	Carrito carritov;
	
	
	int cant;
	
	cout<<"ingrese la cantidad de productos : "; cin>>cant;
	
	for(int i=0;i<cant;i++)
	{
		cout<<"Producto: "<<endl;
		cin>>producto;
		cout<<"precio : "<<endl;
		cin>>precio;
		carritov.anadirCarrito(producto,precio,cant);
	}
	cout<<endl;
	
	carritov.mostrarCarrito();
	cout<<endl;
	carritov.quitarCarrito(2);
	cout<<endl;
	carritov.mostrarCarrito();
	return 0;
}
