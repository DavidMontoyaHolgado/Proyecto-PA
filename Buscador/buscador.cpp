#include<iostream>
#include<fstream>
#include <iomanip>
#include "buscador.h"
#include <algorithm>
using namespace std;

void toLowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

clsBuscador::clsBuscador(){}

int* clsBuscador::buscarProducto(string producto){
	//Poniendo el nombre del producto en minúscula

    string ruta = "../baseDatos/inventario/inventarioGlobal.txt";
    ifstream archivo(ruta);
    string texto;
    int posI, posF;
    string cadena;

    while(getline(archivo, texto)) {
        posI = texto.find("("); posI++;
        posF = texto.find(")", posI); posF--;
        cadena = texto.substr(posI, posF - posI + 1);

        // Convertir la cadena extraída a minúsculas
        toLowercase(cadena);

        if(cadena.find(producto) != string::npos) {
            // Producto encontrado
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
	int* encontrado = new int[5];
	int veri = 0;
	int x,y;
	while(getline(archivo3,texto)){
		posI = texto.find("(");posI++;
		posF = texto.find(")",posF);posF--;
		if(texto.substr(posI,posF-posI+1).find(producto) != string::npos && veri < 4){
			x = texto.find(" ");x++;
			y = texto.find(" ",x);y--;
			encontrado[veri] = stoi(texto.substr(x,y-x+1));
			veri++;
			//Para mostrar 
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
	return encontrado;
}

int main(){
	clsBuscador buscador;
	int* arreglo = buscador.buscarProducto("maquillaje");
}