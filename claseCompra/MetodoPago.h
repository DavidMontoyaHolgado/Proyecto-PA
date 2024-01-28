#ifndef METODOPAGO_H
#define METODOPAGO_H
#include<iostream>
#include "descuentos.h"
using namespace std;

class clsMetodoPago {
    protected:
        int saldo;
    private:
        string tipo;

    public:
        clsMetodoPago();
        void elegirMetodoPago();
        bool realizarPago(float);
            string getTipo() const {
        return tipo;
    }
};
#endif