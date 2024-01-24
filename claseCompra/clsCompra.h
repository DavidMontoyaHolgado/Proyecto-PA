#ifndef CLSCOMPRA_H
#define CLSCOMPRA_H
#include<iostream>
#include<string.h>
#include"descuentos.h"
#include"MetodoPago.h"
#include"carrito.h"

class clsCompra{
    private:
        clsMetodoPago metPago;
        Carrito carrito;
        string lugarEnvio;
        float costoEnvio;
        clsDescuentos dtc;
    public:
    clsCompra(clsMetodoPago , Carrito , string,float,clsDescuentos );

    bool comprar(float total);
   
};

#endif