#ifndef CLSUSUARIO_H
#define CLSUSUARIO_H
#include <iostream>
#include "../Carrito/carrito.h"
#include "../claseCompra/clsCompra.h"
#include "../Buscador/buscador.h"
#include "../funciones/user.h"
using namespace std;

class clsUsuario{
    private:
        string id;
    public:
        clsUsuario();
        void agregarId(string id);
        void valorarProducto(int ,bool, int);
        void valorarProducto(int ,bool, int, string);
};
#include "clsUsuario.cpp"
#endif