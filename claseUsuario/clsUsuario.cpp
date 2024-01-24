#include "clsUsuario.h"
#include "funciones/user.h"
#include <fstream>
#include <string>
using namespace std;

clsUsuario::clsUsuario(string ID){
    id = ID;
}

void clsUsuario::valorarProducto(int idInventario, bool veri, int estrella){
    string ruta = "b../baseDatos/valoracion.txt";
    if(veri == true){
        ofstream archivo;
        string texto;
        archivo.close();
        archivo.open(ruta, ios::app); 
        if(archivo.fail()){
            cout<<"Error, no se encuentra el archivo";
        }
        int cant = cantRegistros(ruta);
        archivo<<cant+ 1<<" "<<id<<" "<<estrella<<endl;
        archivo.close();
    }else{
        cout<<"error";
    }
}

void clsUsuario::valorarProducto(int idInventario, bool veri, int estrella, string opinion){
    string ruta = "b../baseDatos/valoracion.txt";
    if(veri == true){
        ofstream archivo;
        string texto;
        archivo.close();
        archivo.open(ruta, ios::app);
        if(archivo.fail()){
            cout<<"Error, no se encuentra el archivo";
        }
        int cant = cantRegistros(ruta);
        archivo<<cant+ 1<<" "<<id<<" "<<estrella<<" "<<opinion<<endl;
        archivo.close();
    }else{
        cout<<"error";
    }
}