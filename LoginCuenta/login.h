#ifndef LOGINCUENTA_H
#define LOGINCUENTA_H
#include<iostream>
#include<fstream>


using namespace std;

class loginCuenta{
	public:
	   loginCuenta();
	   void crearCu(string nombre, string apellido, string correo, string clave, int edad, int identificacion);
	   void iniciarSe(string correo,string clave);
	   void cerrarSe();
};
#include "login.cpp"
#endif