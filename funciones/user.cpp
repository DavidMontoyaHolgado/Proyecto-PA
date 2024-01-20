#include <iostream>
#include <fstream>
#include "user.h"
using namespace std;

const string ruta = "baseDatos/usuario.txt";

void agregarUsuario(string nombre, string correo, string clave, int edad, int dni){
    ofstream archivo;
    archivo.open(ruta, ios::app);
    int n;
    if(archivo.fail()){
        exit(1);
    }
    archivo<<retornarID()<<" ("<<nombre<<") "<<correo<<" "<<clave<<" "<<edad<<" "<<dni<<endl;
    archivo.close();
}

int retornarID(){
    ifstream archivo;
    string texto;
    int id=0;
    archivo.close();
    archivo.open(ruta);
    while(getline(archivo, texto)){
        id++;
    }
    archivo.close();
    id++;
    return id;
}

int cantUser(){
    ifstream archivo;
    string texto;
    archivo.close();
    int cant = 0;
    archivo.open(ruta);
    while (getline(archivo,texto)){
        cant++;
    }
    return cant;
}

string* retornarNombres(){
    ifstream archivo;
    string texto;
    archivo.close();
    int i=0;
    int j = 0;
    int k = 0;
    string* nombres = new string[100];
    archivo.open(ruta);
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
    archivo.close();
    int i = 0;
    int j = 0;
     int k = 0;
    string* correos = new string [100];
    archivo.open(ruta);
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