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
        clsUsuario(string);
        void valorarProducto(int ,bool, int);
        void valorarProducto(int ,bool, int, string);
};

#endif