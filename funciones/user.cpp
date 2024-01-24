<<<<<<< HEAD
#include <iostream>
#include<string.h>
#include <fstream>
#include <string>
=======
>>>>>>> edfa07e4be6078ecf2ea5d39cdcbfbb00f9de9ad
#include "user.h"
#include <string>

void agregarUsuario(string nombre, string correo, string clave, int edad, int dni){
    ofstream archivo;
<<<<<<< HEAD
    archivo.open(ruta, ios::app);
   int n;
=======
    archivo.open("../baseDatos/usuarios.txt", ios::app);
    int n;
>>>>>>> edfa07e4be6078ecf2ea5d39cdcbfbb00f9de9ad
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
    }
    archivo<<cantRegistros("../baseDatos/usuarios.txt") + 1<<" ("<<nombre<<") "<<correo<<" "<<clave<<" "<<edad<<" "<<dni<<endl;
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

int cantRemoveG(){
    string ruta =  "../baseDatos/inventario/incremento.txt";
    string* arreglo = new string[8];
    ifstream  archivo(ruta,ios::in);
    if (!archivo.is_open()) {
        cout << "Error opening file: "<<endl;
        return 0; 
    }
    //Guardamos el .txt en el arreglo
    int i = 0;
    while(getline(archivo,arreglo[i])){
        i++;
    }
    archivo.close();
    int cant = stoi(arreglo[0].substr(2, arreglo[0].find(" ",2)));
    return cant;
}

int cantRemoveC(int idCategoria){
    string ruta =  "../baseDatos/inventario/incremento.txt";
    string* arreglo = new string[8];
    ifstream  archivo(ruta,ios::in);
    if (!archivo.is_open()) {
        cout << "Error opening file: "<<endl;
        return 0; 
    }
    //Guardamos el .txt en el arreglo
    int i = 0;
    while(getline(archivo,arreglo[i])){
        i++;
    }
    archivo.close();
    int cant = stoi(arreglo[0].substr(2, arreglo[idCategoria].find(" ",2)));
    return cant;
}

string* retornarNombres(){
    ifstream archivo;
    string texto;
    int i=0;
    int j = 0;
    int k = 0;
    string* nombres = new string[100];
    archivo.open("../baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
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
    archivo.open("../baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
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
    int i = 0;
    int j = 0;
    int k = 0;
    string* claves = new string [100];
    archivo.open("../baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
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
<<<<<<< HEAD
=======

void crearRegistro(string nombre){
    string id = to_string(cantRegistros("../baseDatos/usuarios.txt"));
    string ruta = "../baseDatos/registroDeCompra/" + nombre + "_" + id + ".txt";
    ofstream archivo(ruta, ios::out);
    if(!archivo.is_open()){
        cerr<<"Error al abrir el archivo";
        exit(1);
    }
    archivo.close();
}

void agregarRegistroCompra(int IDuser, int IDproducto, int unidades, int gasto){
    ifstream archivo("../baseDatos/usuarios.txt");
    int pos,posI,posF;
    string leer, sub, nombre;
    string stringID = to_string(IDuser);
    //Buscando el nombre del usuario
    while(getline(archivo,leer)){
        pos = leer.find(" ");
        sub = leer.substr(0, pos);
        if(sub == stringID){
            posI = leer.find("(");
            posF = leer.find(" ", posI);
            nombre = leer.substr(posI + 1, posF - posI-1);
            break;
        }
    }
    archivo.close();
    if(nombre.empty()){
        cerr<<"No se encontro el usuario"<<endl;
        exit(1);
    }
    string ruta = "../baseDatos/registroDeCompra/" + nombre + "_" + to_string(IDuser) + ".txt"; 
    ofstream archivo2(ruta, ios::app);
    if(!archivo2.is_open()){
        cerr<<"No se pudo abrir el archivo";
        exit(1);
    }

    // Registrando la compra
    archivo2<<IDuser<<" "<<IDproducto<<" "<<unidades<<" "<<gasto<<endl;
    archivo2.close();
}
>>>>>>> edfa07e4be6078ecf2ea5d39cdcbfbb00f9de9ad