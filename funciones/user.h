#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaraciones de funciones
int cantRegistros(string rutaTXT);
int cantUser();
int cantRemoveG();
int cantRemoveC(int idCategoria);
void agregarUsuario(string nombre,string apellido, string correo, string clave, int edad, int dni);
string* nombres();
string* Correos();
string* claves();
void crearRegistro(string nombre);
void agregarRegistro(string CompraOCarrito, int IDuser, int IDproducto, int unidades, float gasto);
void mostrarCategorias();
void mostrarSubCategoria(int categoria);
#include "user.cpp"
#endif
