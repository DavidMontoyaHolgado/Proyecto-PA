#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<ctime>
#include "descuentos.h"

using namespace std;

clsDescuentos::clsDescuentos(){}

float clsDescuentos::calcularDescuento(float totalSinDescuento) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string fechaActual = to_string(localTime->tm_year + 1900) + '-' +
                         to_string(localTime->tm_mon + 1) + '-' +
                         to_string(localTime->tm_mday);

    string FECHA1, FECHA2, ID, linea;
    float desc, descuentoAcumulado = 1.0;

    ifstream archivo;
    archivo.open("./claseCompra/fecha.txt");

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            ss >> FECHA1 >> FECHA2 >> desc >> ID;

            if (fechaActual >= FECHA1 && fechaActual <= FECHA2 ) {
                descuentoAcumulado *= (1 - desc);
            }
        }

        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    float totalConDescuento = totalSinDescuento * descuentoAcumulado;
    //cout << "Total a pagar despues de descuentos: " << fixed << setprecision(2) << totalConDescuento << endl;

    return totalConDescuento;
}