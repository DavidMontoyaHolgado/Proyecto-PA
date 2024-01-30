#include <regex>
#include"formasPago.h"

clsPaypal::clsPaypal(string corr, string contra) {
    correo = corr;
    contrasena = contra;
}

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
    uniform_int_distribution<int> distribucion(100, 1000);
    int saldo = distribucion(gen);
    return saldo;
}


clsTarjeta::clsTarjeta(string numT, string ven, string codS, string nombTit, string direccFac) {
    numeroTarjeta = numT;
    vencimiento = ven;
    codSeguridad = codS;
    nombreTitular = nombTit;
    direccionFacturacion = direccFac;
}

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
    cout << "Ingresa el nombre del titular: ";
    cin >> nombreTitular;
    cout << "Ingresa la direccion de facturacion: ";
    cin >> direccionFacturacion;
    cout<<endl;
}

int clsTarjeta::getSaldo() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribucion(100, 1000);
    int saldo = distribucion(gen);
    return saldo;
}
