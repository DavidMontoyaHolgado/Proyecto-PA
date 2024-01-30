#ifndef METODOPAGO_H
#define METODOPAGO_H
#include<iostream>
#include "descuentos.h"
using namespace std;

class clsMetodoPago {
    protected:
        int saldo;

    public:
        clsMetodoPago();
        void elegirMetodoPago();
        bool realizarPago(float);
};
#include "MetodoPago.cpp"
#endif