#ifndef CLSUSUARIO_H
#define CLSUSUARIO_H
#include <iostream>
using namespace std;

class clsUsuario{
    private:
        string id;
    public:
        clsUsuario(string);
        void valorarProducto(int ,bool, int);
        void valorarProducto(int ,bool, int, string);
        void buscarProducto(string);
        void guardarProducto(string);
        void comprarProducto(string);
};

#endif