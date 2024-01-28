#include "MetodoPago.h"  
#include"formasPago.h"
#include "descuentos.h"

using namespace std;

clsMetodoPago::clsMetodoPago() {}

void clsMetodoPago::elegirMetodoPago() {
    char n;
    cout << "Desea pagar por Paypal escriba 1, si es por tarjeta escriba 2: ";
    cin >> n;

    if((n == '1') || (n == '2')) {
        if(n == '1') {
            clsPaypal paypal("", "");
            paypal.leerDatos();  // Solicita al usuario ingresar datos de PayPal
            int saldo = paypal.getSaldo();
            //cout << "Saldo actual en PayPal: $" << saldo << endl;
        }
        
        if(n == '2') {
            clsTarjeta tarjeta("", "", "", "", "");
            tarjeta.leerDatos();
            int saldo = tarjeta.getSaldo();
            //cout << "Saldo actual en la tarjeta: $" << saldo << endl;
        }
    }
    else {
        cout << "Opcion incorrecta, ingrese nuevamente";
    }
}

bool clsMetodoPago::realizarPago(float total) {
    // Primero, verifica si hay saldo suficiente para el pago
    
    if (saldo < total) {
        cout << "Pago fallido: Saldo insuficiente." << endl;
        return false;
    }
    saldo -= total;  // Descuenta el total del saldo
    cout << "Pago realizado con éxito. Saldo restante: " << saldo << endl;
    return true;
}