#include<string.h>
#include<iostream>

#include"clsCompra.h"
#include"MetodoPago.h"
#include"formasPago.h"
#include "descuentos.h"
using namespace std;

clsCompra::clsCompra(){}

void clsCompra::llenarDato(){
    cout << "Ingrese lugar de envio: ";
    cin>>lugarEnvio;
}

clsCompra::clsCompra(string lugEnvio) : lugarEnvio(lugEnvio){
    costoEnvio = 20;
}

bool clsCompra::comprarProducto(float total) {
    // Llamar al método realizarPago del objeto clsMetodoPago
    clsMetodoPago metPago;
    clsDescuentos dtc;
    total = dtc.calcularDescuento(total);
    metPago.elegirMetodoPago();
    bool pagoExitoso = metPago.realizarPago(total);

    if (!pagoExitoso) {
        cout << "Compra fallida. Saldo insuficiente." << endl;
    } 

    return pagoExitoso;
}