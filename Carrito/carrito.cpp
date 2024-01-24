#include<iostream>
#include<fstream>
#include "carrito.h"

using namespace std;

Carrito::Carrito(){

    cantidad=0;
     
   
}

void Carrito::anadirCarrito(string nombre,double precio){
	
//	if(cantidad<Npro){
		compras[cantidad].nombre =nombre;
		compras[cantidad].precio = precio;
		cantidad++;
		cout<<endl;
		cout<<" Producto agregado al carrito: "<<nombre<<endl;
	//}else{
	//	cout<<"El carrito esta lleno no se pueden agregar mas productos.  "<<endl;
	//}
}

void Carrito::quitarCarrito(int indice){
//	if(indice>=0 and indice<cantidad){
		
	    cout << "Producto eliminado del carrito: " << compras[indice-1].nombre << endl;
	     
	     for(int i=indice;i<cantidad;i++){
	     	
	     	compras[i-1]=compras[i];
		 }
		 cantidad--;
	//} else{
		
	//	cout<<"Indeice de producto no valido. "<<endl;
	//}
	
}
 
 void Carrito::mostrarCarrito(){
 	
 	   cout << "Carrito de compras:" << endl;
 	   cout<<endl<<"Nº\tProducto\tPrecio\tnCAntidad"<<endl;
				 for(int j=0;j<cantidad;j++)
				 {
				 	cout<<j+1<<"\t" \
				 	<<compras[j].nombre<<"\t\t" \
				 	<<compras[j].precio<<"\t" \
				 	<<endl;
				 }
				 cout<<endl;
 	   
      /* for (int i = 0; i < cantidad; i++) {
            cout << "Nombre: " << compras[i].nombre << ", Precio: " << compras[i].precio << endl;
        }*/
        cout << "Total de productos: " << cantidad << endl;
 }

double Carrito::calculaTotal(){
	
	double total = 0.0;
        for (int i = 0; i < cantidad; i++) {
            total += compras[i].precio;
        }
        return total;
}



int main(){
	
	string producto;
	int precio;
	int quitar;
	int opc;
	Carrito carritov;
	
	//int cant=0;
	
	
	
	do{
		
		cout<<"1. Ingresar productos. "<<endl;
		cout<<"2. Mostrar lista de productos."<<endl;
		cout<<"3. Eliminar productos"<<endl;
		cout<<"4.salir de CARRITO."<<endl;
		cout<<endl;
		cout<<"ingrese la opcion: "; cin>>opc;
		cout<<endl;
		
		switch(opc){
			
			case 1:
				  //cout<<endl;
				  //cout<<"ingrese la cantidad de productos : "; cin>>cant;
			         //for(int i=0;i<cant;i++){
			         	 cout<<endl;
			         	 cout<<".Producto: ";
			         	 cin>>producto;
		                 cout<<"Precio : ";
	                 	cin>>precio;
	                  	carritov.anadirCarrito(producto,precio);
					 //}
			          cout<<endl;
	
                  	 carritov.mostrarCarrito();
	                  cout << "Total de la compra: $" << carritov.calculaTotal() << endl;
	                  cout<<endl;
			      break;
			
			case 2:
			       carritov.mostrarCarrito();
				   cout << "Total de la compra: $" << carritov.calculaTotal() << endl;
				   cout<<endl;    
	              break;
			
			case 3:	  
			         cout<<"Ingrese numero de producto a eliminar: "; cin>>quitar;
	
                    carritov.quitarCarrito(quitar);
                    cout<<endl;
			       break;
			 case 4:
			 	 break;
			 		
		}
		
		
		
		
	}while(opc!=4);
	
	
	
/*	cout<<"ingrese la cantidad de productos : "; cin>>cant;
	
	for(int i=0;i<cant;i++)
	{
		cout<<endl;
		cout<<i+1<<".Producto: ";
		cin>>producto;
		cout<<"Precio : ";
		cin>>precio;
		carritov.anadirCarrito(producto,precio,cant);
	}
	cout<<endl;
	
	carritov.mostrarCarrito();
	cout << "Total de la compra: $" << carritov.calculaTotal() << endl;

	cout<<endl;
	
	cout<<"Ingrese numero de producto a eliminar: "; cin>>quitar;
	
	carritov.quitarCarrito(quitar);
	cout<<endl;
	
	
	carritov.mostrarCarrito();
	cout << "Total de la compra: $" << carritov.calculaTotal() << endl; */

	return 0;
}
