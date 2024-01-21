#ifndef CLSUSUARIO_H
#define CLSUSUARIO_H
#include "clsUsuario.h"
#include "funciones/user.h"
#include <fstream>
#include <string>
using namespace std;

const string ruta = "baseDatos/valoracion.txt";

clsUsuario::clsUsuario(string ID){
    id = ID;
}

void clsUsuario::valorarProducto(int idInventario, bool veri, int estrella){
    if(veri == true){
        ofstream archivo;

        string texto;
        archivo.close();
        archivo.open(ruta, ios::app); 
        if(archivo.fail()){
            cout<<"Error, no se encuentra el archivo";
        }
        int cant = cantID(ruta);
        archivo<<cant<<" "<<id<<" "<<estrella<<endl;
        archivo.close();
    }else{
        cout<<"error";
    }
}

void clsUsuario::valorarProducto(int idInventario, bool veri, int estrella, string opinion){
    if(veri == true){
        ofstream archivo;
        string texto;
        archivo.close();
        archivo.open(ruta, ios::app);
        if(archivo.fail()){
            cout<<"Error, no se encuentra el archivo";
        }
        int cant = cantID(ruta);
        archivo<<cant<<" "<<id<<" "<<estrella<<" "<<opinion<<endl;
        archivo.close();
    }else{
        cout<<"error";
    }
}

#endif