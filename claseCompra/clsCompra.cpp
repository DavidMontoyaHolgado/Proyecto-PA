#include<string.h>
#include<iostream>

#include"clsCompra.h"
#include"MetodoPago.h"
#include"formasPago.h"

clsCompra::clsCompra(clsMetodoPago mPag, Carrito car, string lugEnvio, float costEnvio, clsDescuentos d)
    : metPago(mPag), carrito(car), lugarEnvio(lugEnvio), costoEnvio(costEnvio), dtc(d)
{}

    


bool clsCompra::comprar(float total) {
    // Llamar al método realizarPago del objeto clsMetodoPago
    bool pagoExitoso = metPago.realizarPago(total);

    if (pagoExitoso) {
        // Realizar acciones adicionales después del pago exitoso
        // Por ejemplo, enviar el pedido, aplicar descuentos, etc.
        std::cout << "Compra realizada con éxito." << std::endl;
    } else {
        std::cout << "Compra fallida. Saldo insuficiente." << std::endl;
    }

    return pagoExitoso;
}