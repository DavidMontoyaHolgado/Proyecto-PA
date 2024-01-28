#include "MetodoPago.h"  
#include"formasPago.h"


clsMetodoPago::clsMetodoPago(int sal) {
    saldo = sal;
}

void clsMetodoPago::elegirMetodoPago() {
    char n;
    cout << "Desea pagar por Paypal escriba 1, si es por tarjeta escriba 2: ";
    cin >> n;

    if((n == '1') || (n == '2')) {
        if(n == '1') {
            clsPaypal paypal("", "");
            paypal.leerDatos();  // Solicita al usuario ingresar datos de PayPal
            int saldoPaypal = paypal.getSaldo();
            cout << "Saldo actual en PayPal: $" << saldoPaypal << endl;
        }
        
        if(n == '2') {
            clsTarjeta tarjeta("", "", "", "", "");
            tarjeta.leerDatos();
            int saldoTarjeta = tarjeta.getSaldo();
            cout << "Saldo actual en la tarjeta: $" << saldoTarjeta << endl;
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