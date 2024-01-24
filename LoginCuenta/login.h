#include<iostream>
#include<fstream>


using namespace std;

class loginCuenta{
	private:
		string nombres;
		string correo;
		string clave;
	public:
	   loginCuenta(string,string,string);
	   void crearCu(string *A, int n,string correo);
	   void iniciarSe(string *A,string *B,int n,string correo,string clave);
	   void cerrarSe();
};
