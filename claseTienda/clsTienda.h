#ifndef CLSTIENDA_H
#define CLSTIENDA_H
#include "clsProducto.h"
#include <string>
using namespace std;
class clsTienda{
    private:
        string nombreTienda;
        clsProducto Producto;
        int id;
        int ruc;
    public:
        clsTienda();
        clsTienda(string nombreT, int RUC);
        void agregarProducto(string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int* stock);
        void agregarProductoRopa(string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int** stock, string* tallas);
        void eliminarProducto(int idProducto);
};

#endif