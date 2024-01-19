#include <iostream>
#include <string.h>
#include "clsDatosAdicionales.h"
using namespace std;

class clsProducto{
    private:
        string nombreProducto;
        // float precio;
        // string descripcion;
        // string marca;
        // string modelo;
        string categoria;
        string categoria_tipo;
        string colores[10];
        int cantColor;
        clsDatosAdicionales Stock;
    public:
        clsProducto(string, string,string, string*,int);
        string getNombre() const {return nombreProducto;};
        // float getPrecio() const {return precio;};
        // string getDescripcion () const {return descripcion;};
        // string getMarca () const {return marca;};        
        // string getModelo () const {return modelo;};
        // string getCategoria () const {return ;};
        // string getColores    () const {return ;};
        void llenarStockP();
        void llenarStockP(int, string *);
};

clsProducto::clsProducto(string nombre_Producto, string _categoria, string categoria_tipo,string* coloresP, int cantColorP){
    nombreProducto = nombre_Producto;
    // precio = precioP;
    // descripcion = descripcionP;
    // marca = marcaP;
    // modelo = modeloP;
    categoria = _categoria;
    categoria_tipo = categoria_tipo;
    cantColor = cantColorP;
    for(int i = 0; i < cantColorP;i++){
        colores[i] = coloresP[i];
    }
}

void clsProducto::llenarStockP(){Stock.llenarStock(cantColor, colores);}

void clsProducto::llenarStockP(int cantTalla, string* talla){Stock.llenarStock(cantColor, cantTalla,colores, talla);}
