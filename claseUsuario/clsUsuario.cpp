#include "clsUsuario.h"
#include "../funciones/user.h"
#include "../Carrito/carrito.h"
#include "../claseCompra/clsCompra.h"
#include "../Buscador/buscador.h"
#include <fstream>
#include <string>
using namespace std;

clsUsuario::clsUsuario(){}

void clsUsuario::agregarId(string idUsuario){
    id = idUsuario;
}

void clsUsuario::valorarProducto(int idInventario, bool veri, int estrella){
    string ruta = "./baseDatos/valoracion.txt";
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
    string ruta = "./baseDatos/valoracion.txt";
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
