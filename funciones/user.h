#include <iostream>
#include <fstream>
#ifndef USER_H
#define USER_H
using namespace std;

void agregarUsuario(string, string, string, int, int);
int retornarID();
string* retornarUsuarios();
string* retornarCorreos();
string* retornarClaves();
int cantUsuarios();

#include "user.cpp"
#endif
