#include<string.h>
#include<iostream>

#include"clsCompra.h"
#include "../Carrito/carrito.h"
#include"MetodoPago.h"
#include"formasPago.h"
#include "descuentos.h"
using namespace std;

clsCompra::clsCompra(clsMetodoPago mPag, clsCarrito car, string lugEnvio, float costEnvio, clsDescuentos d) : metPago(mPag), carrito(car), lugarEnvio(lugEnvio), costoEnvio(costEnvio), dtc(d){}

bool clsCompra::comprar(float total) {
    // Llamar al método realizarPago del objeto clsMetodoPago
    total = dtc.calcularDescuento(total);
    bool pagoExitoso = metPago.realizarPago(total);

    if (pagoExitoso) {
        // Realizar acciones adicionales después del pago exitoso
        // Por ejemplo, enviar el pedido, aplicar descuentos, etc.
        std::cout << "Compra realizada con éxito." <<endl;
    } else {
        std::cout << "Compra fallida. Saldo insuficiente." << endl;
    }

    return pagoExitoso;
}