	#include<iostream>
	#include "login.h"
	#include <string>
	#include "../funciones/user.h"
	#include "../Carrito/carrito.h"
	using namespace std;

	loginCuenta::loginCuenta(){}

	void loginCuenta::crearCu(string nombre, string apellido, string correo, string clave, int edad, int identificacion){
		int n = cantRegistros("./baseDatos/usuarios.txt");
		bool cen = 0;
		int i = 0;
		while (true) {
            // Bucle para verificar si el correo contiene el símbolo "@"
            while (correo.find('@') == string::npos) {
                cout << "El correo " << correo << " no es válido, debe contener '@'." << endl;
                cout << "Ingrese su correo electrónico: ";
                cin >> correo;
            }

            // Verificar si el correo ya existe en la base de datos
            while (i < n && Correos()[i] != correo)
                i++;

            if (Correos()[i] == correo) {
                cout << "El correo " << correo << " ya existe." << endl;
                cout << "Ingrese otro correo electrónico: ";
                cin >> correo;
                i = 0; // Reiniciar el contador de búsqueda en la base de datos.
            } else {
                break; // Salir del bucle si el correo es válido y no existe en la base de datos.
            }
        }

        agregarUsuario(nombre, apellido, correo, clave, edad, identificacion);
        crearRegistro(nombre);
        int id = n+1;;
        cout << "Cuenta creada exitosamente" << endl;
    }


	void loginCuenta::iniciarSe(string correo, string clave){
		int n = cantRegistros("./baseDatos/usuarios.txt");
		int pos=0;
		int i=0;
		bool cen=0;
		while(i<n){
			if(Correos()[i] == correo){
				break;
			}
			i++;
		}
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


