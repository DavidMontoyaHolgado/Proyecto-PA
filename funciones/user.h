#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaraciones de funciones
int cantRegistros(string rutaTXT);
void agregarUsuario(string nombre, string correo, string clave, int edad, int dni);
string* retornarNombres();
string* retornarCorreos();
string* retornarClaves();
void crearRegistro(string nombre);
void agregarRegistroCompra(int IDuser, int IDproducto, int unidades, int gasto);

#endif
