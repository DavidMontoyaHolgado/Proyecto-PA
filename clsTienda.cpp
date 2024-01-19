#include <iostream>
#include "clsProducto.h"
#include "clsValoracion.h"
using namespace std;

class clsTienda{
    private:
        string nombreTienda;
        clsValoracion valoracion;
        clsProducto* Productos[20];
        int cant;
    public:
        clsTienda(string nombre_Tienda);
        void agregarProducto(string,float,string,string, string, string , string ,string*, int);
        void eliminarProducto(string);
};

clsTienda::clsTienda(string nombre_Tienda){
    nombreTienda = nombre_Tienda;
    cant = 0;
}

void clsTienda::agregarProducto(string nombreProducto,float precio,string descripcion,string marca, string modelo, string categoria, string categoria_tipo,string* colores, int cantColor){
    Productos[cant] = new clsProducto(nombreProducto,categoria, categoria_tipo, colores, cantColor);
    cant++;
}

void clsTienda::eliminarProducto(string nombreProducto){
    for(int i = 0; i < cant; i++){
        if(Productos[i]->getNombre() == nombreProducto){
            delete Productos[i];
            for(int j = i; j < cant-1; j++){
                Productos[j] = Productos[j+1];
            }
            cant--;
            break;
        }
        
    }
}