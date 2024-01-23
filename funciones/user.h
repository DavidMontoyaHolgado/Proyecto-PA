#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaraciones de funciones
int cantRegistros(string);
void agregarUsuario(string, string, string, int, int);
string* retornarNombres();
string* retornarCorreos();
string* retornarClaves();
void crearRegistro(string);
void agregarRegistroCompra(int, int, int, int);

#endif
