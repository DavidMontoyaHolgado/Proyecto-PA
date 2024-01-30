#ifndef CLSCOMPRA_H
#define CLSCOMPRA_H
#include <iostream>
#include <string.h>
#include "descuentos.h"
#include "MetodoPago.h"

class clsCompra{
    private:
        string lugarEnvio;
        float costoEnvio;
    public:
    clsCompra();
    clsCompra(string);
    void llenarDato();

    bool comprarProducto(float total);
   
};
#include "clsCompra.cpp"
#endif