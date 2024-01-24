#include <iostream>
#include<string.h>
#include <fstream>
#include <string>
#include "user.h"
using namespace std;

const string ruta = "baseDatos/usuario.txt";

void agregarUsuario(string nombre, string correo, string clave, int edad, int dni){
    ofstream archivo;
    archivo.open(ruta, ios::app);
   int n;
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<ruta<<endl;
    }
    archivo<<cantRegistros(ruta) + 1<<" ("<<nombre<<") "<<correo<<" "<<clave<<" "<<edad<<" "<<dni<<endl;
    archivo.close();
}


int cantRegistros(string rutaTXT){
    ifstream archivo;
    string texto;
    int cant = 0;
    archivo.open(rutaTXT);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<rutaTXT<<endl;
        return -1;
    }
    while (getline(archivo,texto)){
        cant++;
    }
    archivo.close();
    return cant;
}

string* retornarNombres(){
    ifstream archivo;
    string texto;
    int i=0;
    int j = 0;
    int k = 0;
    string* nombres = new string[100];
    archivo.open(ruta);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<ruta<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find("(");
        i++;
        j = texto.find(")", i);
        nombres[k] = texto.substr(i,j - i);
        k++;
    }
    archivo.close();
    return nombres;
}

string* retornarCorreos(){
    ifstream archivo;
    string texto;
    int i = 0;
    int j = 0;
     int k = 0;
    string* correos = new string [100];
    archivo.open(ruta);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<ruta<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find(")");
        i+=2;
        j = texto.find(" ",i);
        correos[k] = texto.substr(i,j-i);
        k++;
    }
    archivo.close();
    return correos;
}

string* retornarClaves(){
    ifstream archivo;
    string texto;
    archivo.close();
    int i = 0;
    int j = 0;
    int k = 0;
    string* claves = new string [100];
    archivo.open(ruta);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<ruta<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find(")");
        i+= 3;
        i = texto.find(" ",i);
        i++;
        j = texto.find(" ",i);
        claves[k] = texto.substr(i, j - i);
        k++;
    }
    archivo.close();
    return claves;
}   
