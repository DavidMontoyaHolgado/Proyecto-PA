#ifndef FORMASPAGO_H
#define FORMASPAGO_H
#include<iostream>
#include<random>
using namespace std;

class clsPaypal {
    private:
        string correo;
        string contrasena;

    public:
        clsPaypal(string, string);
        void leerDatos();
        int getSaldo();
};

class clsTarjeta {
    private:
        string numeroTarjeta;
        string vencimiento;
        string codSeguridad;
        string nombreTitular;
        string direccionFacturacion;

    public:
        clsTarjeta(string, string, string, string, string);
        void leerDatos();
        int getSaldo();
};
#endif