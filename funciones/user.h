#include <iostream>
#include <fstream>
#ifndef USER_H
#define USER_H
using namespace std;

void agregarUsuario(string, string, string, int, int);
string* retornarUsuarios();
string* retornarCorreos();
string* retornarClaves();
int cantRegistros(string);

#include "user.cpp"
#endif
