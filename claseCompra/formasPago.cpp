#include <regex>
#include"formasPago.h"
using namespace std;
clsPaypal::clsPaypal() {}

void clsPaypal::leerDatos() {
    bool correoValido = false;
    while (!correoValido) {
        cout << "Ingresa el correo: ";
        cin >> correo;
        if (correo.find('@') != string::npos) {
            correoValido = true;
        } else {
            cout << "Correo inválido, por favor ingresa un correo válido.\n";
        }
    }

    cout << "Ingresa la contrasena: ";
    cin >> contrasena;
}

int clsPaypal::getSaldo() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(500, 1000);
    int saldo = distribucion(gen);
    return saldo;
}


clsTarjeta::clsTarjeta() {}

void clsTarjeta::leerDatos() {
    bool numeroValido = false;
    while (!numeroValido) {
        cout << "Ingresa el numero de tarjeta (formato xxxx-xxxx-xxxx-xxxx): ";
        cin >> numeroTarjeta;

        // Verifica el formato
        regex formatoTarjeta("\\b\\d{4}-\\d{4}-\\d{4}-\\d{4}\\b");
        if (regex_match(numeroTarjeta, formatoTarjeta)) {
            numeroValido = true;
        } else {
            cout << "Formato de número de tarjeta inválido, por favor intenta nuevamente.\n";
        }
    }

    cout << "Ingresa la fecha de vencimiento: ";
    cin >> vencimiento;
    cout << "Ingresa el codigo de seguridad: ";
    cin >> codSeguridad;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Ingresa el nombre del titular: ";
    getline(cin,nombreTitular);
    cout << "Ingresa la direccion de facturacion: ";
    cin >> direccionFacturacion;
}

int clsTarjeta::getSaldo() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(500, 1000);
    int saldo = distribucion(gen);
    return saldo;
}