#include<iostream>
#include<fstream>
#include <sstream>
#include "carrito.h"
#include "../funciones/user.h"

using namespace std;

clsCarrito::clsCarrito(int idUsuario){idUser = idUsuario;}

void clsCarrito::anadirCarrito(int IDproducto,int cantidad,float precio){
		agregarRegistro("Carrito",idUser,IDproducto,cantidad,precio);
		cout<<" Producto agregado al carrito : "<<endl;
}

void clsCarrito::quitarCarrito(int posCarrito){
	ifstream archivo("../baseDatos/usuarios.txt");
	string texto, usuario;
	int pos =1;
	//Obtenemos los datos del usuario
	while(getline(archivo,texto)){
	if(pos == idUser){
		usuario = texto;
		break;}
	pos++;
	}

	//Obtenemos el nombre del usuario
	archivo.close();
	int posI = usuario.find("(");posI++;
	int posF = usuario.find(" ",posI);
	usuario = usuario.substr(posI, posF-posI);
	string ruta = "../baseDatos/registroDeCarrito/" + usuario + "_" + to_string(idUser) + ".txt";

	//Guardamos el carrito en un arreglo
	ifstream archivo2(ruta);
	int n = cantRegistros(ruta);
	string* arreglo = new string[n];
	int i = 0;
	texto = "";
	while(getline(archivo2,texto)){
		arreglo[i] = texto;
		i++;
	}
	archivo2.close();
	posI = 0;
	posF = 0;
	for(int j = posCarrito-1; j < n-1;j++){
		arreglo[j] = arreglo[j+1];
	}
	//Arreglamos el indice de los productos en carrito
	int aux;
	string resto;
	for(int j = 0;j< n-1; j++){
		resto = arreglo[j].substr(arreglo[j].find(" "), arreglo[j].length()-1);
		arreglo[j] = to_string(j+1) + resto;
	}	
	ofstream archivo3(ruta,ios::trunc);
	for(int j = 0;j < n-1;j++){
		archivo3<<arreglo[j]<<endl;
	}
	archivo3.close();
	
}
 
 void clsCarrito::mostrarCarrito(){
 	
 	//    cout << "Carrito de compras:" << endl;
 	//    cout<<endl<<"Nº\tProducto\tPrecio\tnCAntidad"<<endl;
	// 			 for(int j=0;j<cantidad;j++)
	// 			 {
	// 			 	cout<<j+1<<"\t" \
	// 			 	<<compras[j].nombre<<"\t\t" \
	// 			 	<<compras[j].precio<<"\t" \
	// 			 	<<endl;
	// 			 }
	// 			 cout<<endl;
 	   
      /* for (int i = 0; i < cantidad; i++) {
            cout << "Nombre: " << compras[i].nombre << ", Precio: " << compras[i].precio << endl;
        }*/
        // cout << "Total de productos: " << cantidad << endl;
 }

double clsCarrito::	calculaTotal(){
	
	// double total = 0.0;
    //     for (int i = 0; i < cantidad; i++) {
    //         total += compras[i].precio;
    //     }
    //     return total;
	return 0.0;
}



int main(){
	clsCarrito carrito(5);
	carrito.quitarCarrito(3);
	//carrito.anadirCarrito(20,1,800);
	// string producto;
	// int precio;
	// int quitar;
	// int opc;
	// Carrito carritov;
	
	// //int cant=0;
	
	
	
	// do{
		
	// 	cout<<"1. Ingresar productos. "<<endl;
	// 	cout<<"2. Mostrar lista de productos."<<endl;
	// 	cout<<"3. Eliminar productos"<<endl;
	// 	cout<<"4.salir de CARRITO."<<endl;
	// 	cout<<endl;
	// 	cout<<"ingrese la opcion: "; cin>>opc;
	// 	cout<<endl;
		
	// 	switch(opc){
			
	// 		case 1:
	// 			  //cout<<endl;
	// 			  //cout<<"ingrese la cantidad de productos : "; cin>>cant;
	// 		         //for(int i=0;i<cant;i++){
	// 		         	 cout<<endl;
	// 		         	 cout<<".Producto: ";
	// 		         	 cin>>producto;
	// 	                 cout<<"Precio : ";
	//                  	cin>>precio;
	//                   	carritov.anadirCarrito(producto,precio);
	// 				 //}
	// 		          cout<<endl;
	
    //               	 carritov.mostrarCarrito();
	//                   cout << "Total de la compra: $" << carritov.calculaTotal() << endl;
	//                   cout<<endl;
	// 		      break;
			
	// 		case 2:
	// 		       carritov.mostrarCarrito();
	// 			   cout << "Total de la compra: $" << carritov.calculaTotal() << endl;
	// 			   cout<<endl;    
	//               break;
			
	// 		case 3:	  
	// 		         cout<<"Ingrese numero de producto a eliminar: "; cin>>quitar;
	
    //                 carritov.quitarCarrito(quitar);
    //                 cout<<endl;
	// 		       break;
	// 		 case 4:
	// 		 	 break;
			 		
	// 	}
		
		
		
		
	// }while(opc!=4);

	return 0;
}
