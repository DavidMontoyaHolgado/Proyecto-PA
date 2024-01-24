#ifndef DESCUENTOS_H
#define DESCUENTOS_H
#include<iostream>

class clsDescuentos {
public:
    clsDescuentos() {}

    float calcularDescuento(float totalSinDescuento, float porcentajeDescuento) {
        return totalSinDescuento * (1 - porcentajeDescuento);
    }
};
#endif