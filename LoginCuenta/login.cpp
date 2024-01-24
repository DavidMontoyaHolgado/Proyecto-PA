	#include<iostream>
	#include "login.h"
	#include "../funciones/user.h"
	using namespace std;

	loginCuenta::loginCuenta(){}

	void loginCuenta::crearCu(string nombre, string apellido, string correo, string clave, int edad, int identificacion){
		int n = cantRegistros("../baseDatos/usuarios.txt");
		bool cen = 0;
		int i=0;
		while(i<n && correos()[i]!=correo)
			i++;

		if(correos()[i]==correo)
			cen = 1;

		if(cen == 1){
			cout<<"El correo  "<<correo<<" ya existe "<<endl;
		}else{
			agregarUsuario(nombre,apellido,correo,clave,edad,identificacion);
			crearRegistro(nombre);
			cout<<"Cuenta creada exitosamente"<<endl;
		}
	}

	void loginCuenta::iniciarSe(string correo, string clave){
		int n = cantRegistros("../baseDatos/usuarios.txt");
		int pos=0;
		int i=0;
		bool cen=0;
		
		while(i<n && correos()[i]!=correo)
			i++;
		
		if(claves()[i]==clave){
			cen = 1;
		}
		if(cen){
			cout<<endl;
			cout<<"Bienvenidos al sistema "<<endl;  
		}else{		
			cout<<"El Correo y/o la clave son incorrectas"<<endl;
		}
	}

	void loginCuenta::cerrarSe(){
		
		cout<<"MUCHAS GRACIAS POR VISITARNOS "<<endl;;
		cout<<endl;
	}

