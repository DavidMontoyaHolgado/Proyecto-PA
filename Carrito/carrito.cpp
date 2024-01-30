#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "carrito.h"
#include "../funciones/user.h"

using namespace std;

clsCarrito::clsCarrito(int id){
	idUser = id;
	string texto;
	int posI, posF;
	string sub;
	string nombre;
	ifstream archivo("./baseDatos/usuarios.txt");
	if(!archivo.is_open()){
		cout<<"enserio"<<endl;
	}
	int i,f;
	while(getline(archivo,texto)){
		posF = texto.find(" ");posF--;
		sub = texto.substr(0,posF+1);
		if(sub == to_string(id)){
			i = texto.find("(");i++;
			f = texto.find(" ",i);f--;
			nombre = texto.substr(i,f-i+1);
		}
	}
	archivo.close();
	ruta = "./baseDatos/registroDeCarrito/" + nombre + "_" + to_string(id) + ".txt";
}

void clsCarrito::anadirCarrito(int IDproducto,int cantidad,float precio){
		agregarRegistro("Carrito",idUser,IDproducto,cantidad,precio);
		cout<<" Producto agregado al carrito : "<<endl;
}

void clsCarrito::quitarCarrito(int posCarrito){
	//Guardamos el carrito en un arreglo
	ifstream archivo2(ruta);
	int n = cantRegistros(ruta);
	string* arreglo = new string[n];
	int i = 0;
	string texto = "";
	while(getline(archivo2,texto)){
		arreglo[i] = texto;
		i++;
	}
	archivo2.close();
	int posI = 0;
	int posF = 0;
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
	//Guardamos el carrito en un arreglo
	ifstream archivo2(ruta);
	int n = cantRegistros(ruta);
	string* arreglo = new string[n];
	int i = 0;
	string texto = "";
	while(getline(archivo2,texto)){
		arreglo[i] = texto;
		i++;
	}
	archivo2.close();
	string nombre;
	int num, IdProducto, cant;
	float precio;
	int posI =0;
	int posF = 0;
	texto = "";	
	cout<<" "<<left<<setw(5)<<"N°"<<setw(45)<<"Nombre del producto"<<setw(10)<<"Cantidad"<<setw(8)<<"Precio"<<endl;
	 	for(int j=0;j<n;j++)
	 	{
			istringstream stream(arreglo[j]);
			stream >> num >> IdProducto >> cant >> precio;
			ifstream archivo3("./baseDatos/inventario/inventarioGlobal.txt");
			while(getline(archivo3,texto)){
				
				if(texto.substr(0,texto.find(" ")) == to_string(IdProducto)){
					posI = texto.find("(");posI++;
					posF = texto.find(")",posI);posF--;
					nombre = texto.substr(posI, posF-posI+1);
				}
			}
	 		cout<<" "<<left<<setw(5)<<j+1<<setw(49)<<nombre;
			cout<<left <<setw(7)<<left<<cant<<setw(10)<<precio<<endl;
	 	}
	 	cout<<endl;
 }


float clsCarrito::calculaProducto(int pos){
	ifstream archivo(ruta);
	string texto;
	int i = 1;
	int POS,IdProducto,cant, total;
	float precio;
	while(getline(archivo,texto)){
		if(i == pos){
			istringstream partes(texto);
			partes>>POS>>IdProducto>>cant>>precio;
			total = precio * cant;
			break;
		}
		i++;
	}
	return total;
}

int clsCarrito::getIdProducto(int pos){
	ifstream archivo(ruta);
	string texto;
	int posI,posF;
	string sub;
	string id;
	int x,y;
	while(getline(archivo,texto)){
		posF = texto.find(" ");
		sub = texto.substr(0,posF);
		if(sub == to_string(pos)){
			x = texto.find(" ");x++;
			y = texto.find(" ",x);y--;
			id= texto.substr(x,y-x+1);
		}
	}
	return stoi(id);
}