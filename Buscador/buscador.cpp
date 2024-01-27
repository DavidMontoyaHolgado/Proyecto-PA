#include<iostream>
#include<fstream>
#include <iomanip>
#include "buscador.h"

using namespace std;

clsBuscador::clsBuscador(){}

// *A =producto
void clsBuscador::buscarProducto(string producto){
	//Poniendo el nombre del producto en minuscula

	string ruta = "../baseDatos/inventario/inventarioGlobal.txt";
	ifstream archivo(ruta);
	string texto;
	int posI, posF;
	size_t veri;
	string _producto;
	while(getline(archivo,texto)){
		posI = texto.find("(");posI++;
		posF = texto.find(")",posF);posF--;
		_producto = texto.substr(posI,posF-posI+1).find(producto);
		if(_producto != string::npos){
			break;
		}
	}
	archivo.close();
	posI = texto.find(")");
	posI+=2;
	posI = texto.find(" ",posI),posI++;
	posF = texto.find(" ",posI);posF--;
	int pos = stoi(texto.substr(posI,posF-posI+1));
	ifstream archivo2("../baseDatos/Categoria.txt");
	int i =1;
	while(getline(archivo2,texto)){
		if(i == pos)
			break;
		i++;
	}
	string categoria;
	posI = texto.find("(");posI++;
	posF = texto.find(")",posI);posF--;
	categoria = texto.substr(posI,posF-posI+1);
	//Quitamos espacios en blanco si es categoría 3 o 4
	if(pos == 3 || pos == 4){
		for (int ii = 0; ii < categoria.length(); ii++) {
   			if (categoria[ii] == ' ')
      			categoria.erase(ii, 1);
  		}
	}
	string ruta2 = "../baseDatos/inventario/" + categoria + ".txt";
	ifstream archivo3(ruta2);
	string nombre;
	float precio;
	int n,m;
	texto= " ";
	while(getline(archivo3,texto)){
		posI = texto.find("(");posI++;
		posF = texto.find(")",posF);posF--;
		if(texto.substr(posI,posF-posI+1).find(producto) != string::npos){
			n = texto.find("(");n++;
			m = texto.find(")",n);m--;
			nombre = texto.substr(n,m-n+1);
			m+=3;
			n = texto.find(" ",m);n++;
			m = texto.find(" ",n);m++;
			n = texto.find(" ", m);n--;
			precio = stoi(texto.substr(m,n-m+1));
			cout<<"  |"<<left<<setw(50)<<nombre<<"|"<<setw(5)<<"S/."<<precio<<"|"<<endl;
			cout<<"   -----------------------------------------------------------"<<endl;

		}
	} 
	archivo3.close();
}



int main(){

	clsBuscador buscador;
	buscador.buscarProducto("Maquillaje");
	return 0;
}
