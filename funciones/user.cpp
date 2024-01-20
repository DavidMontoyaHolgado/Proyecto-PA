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