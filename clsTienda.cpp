#include <iostream>
#include "clsProducto.h"
#include "clsValoracion.h"
using namespace std;

class clsTienda{
    private:
        string nombreTienda;
        clsValoracion valoracion;
        clsProducto* Productos[30];
        int cant;
    public:
        clsTienda(string);
        void agregarProducto(string,float,string,string, string, string , string ,string*, int);
        void eliminarProducto(string);
        clsValoracion getValoracion(){return valoracion;};
};

clsTienda::clsTienda(string nombreT){
    nombreTienda = nombreT;
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


int main(){
    clsTienda Tienda("JOBO");
    string colores[] = {"Rojo", "Verde", "Amarillo", "Dorado"};
    Tienda.agregarProducto("Galaxy 10", 5000, "De buena calidad", "Samsumg", "Galaxy 10", "Tecnologia", "Celular", colores, 4);  
    Tienda.agregarProducto("Galaxy 8", 4500, "De buena calidad", "Samsumg", "Galaxy 8", "Tecnologia", "Celular", colores, 4);
    Tienda.getValoracion().setValorar(3);
    Tienda.getValoracion().setOpinar("Buena calidad, pero se tardo");
    Tienda.eliminarProducto("Galaxy 8");
}