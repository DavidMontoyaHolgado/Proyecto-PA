#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<ctime>
#include "descuentos.h"

using namespace std;

int main() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string fechaActual = to_string(localTime->tm_year + 1900) + '-' +
                         to_string(localTime->tm_mon + 1) + '-' +
                         to_string(localTime->tm_mday);

    cout << "Fecha actual: " << fechaActual << endl;

    string FECHA1, FECHA2, ID, linea;
    float desc, totalSinDescuento = 0.0, descuentoAcumulado = 1.0;
  

    ifstream archivo;
    archivo.open("fecha.txt");

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            ss >> FECHA1 >> FECHA2 >> desc >> ID;

            if (fechaActual >= FECHA1 && fechaActual <= FECHA2 ) {
                descuentoAcumulado *= (1 - desc);
                cout << "Descuento aplicado: " << ID << " - " << desc * 100 << "%" << endl;
            }
        }

        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    clsDescuentos descuentos;
    float totalConDescuento = descuentos.calcularDescuento(totalSinDescuento, 1 - descuentoAcumulado);

    cout << "Total a pagar despues de descuentos: " << fixed << setprecision(2) << totalConDescuento << endl;

    return 0;
}