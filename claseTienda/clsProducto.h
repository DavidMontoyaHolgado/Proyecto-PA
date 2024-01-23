#ifndef CLSPRODUCTO_H
#define CLSPRODUCTO_H
#include <iostream>
#include <string>
using namespace std;

class clsProducto{
    private:
        string nombreProducto;
        int categoria;
        string nombreCategoria;
        int categoriaTipo;
        string colores[10];
        int cantColor;
    public:
        clsProducto(){};
        clsProducto(int, string, float,string, string,string, int, int, string *, int, int*);
        clsProducto(int, string, float,string, string,string, int, int, string *, int, int**,int, string*);
};

#endif