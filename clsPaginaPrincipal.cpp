# include <iostream>
#include "LoginCuenta/login.h"
using namespace std;

int main(){
	int opc, edad,dni;
	string nombre,correo,clave,apellido;
	loginCuenta cuenta;
	
	do{
		
		cout<<"1. Iniciar Secion. "<<endl;
		cout<<"2. Crear Cuenta."<<endl;
		cout<<"3. Cerrar secion"<<endl;
		cout<<"4.salir de la pagina."<<endl;
		cout<<endl;
		cout<<"ingrese la opcion: "; cin>>opc;
		cout<<endl;
		
		switch(opc){
			
			case 1:
					cout<<"\t\t\tLOGIN DE USUARIO"<<endl;
					cout<<"\t\t\t-----------------"<<endl;
					cout<<"Correo: ";
					cin>>correo;
					cout<<"Clave : ";
					cin>>clave;
				
				cuenta.iniciarSe(correo,clave);
				cout<<endl;
				break;
			
			case 2:
					cout<<"Nombre: ";cin>>nombre;
					cout<<"Apellido: ";cin>>apellido;
					cout<<"Edad: ";cin>>edad;
					cout<<"Identificacion: ";cin>>dni;
					cout<<"Correo: ";cin>>correo;
					cout<<"Clave : ";cin>>clave;
					cout<<endl;
						
				cuenta.crearCu(nombre,apellido,correo,clave,edad,dni);
				cout<<endl;
				
				break;
			case	3:
				cout<<endl;
				cuenta.cerrarSe();
	
				break;
			case 4:
				break;	
			
		}
		
	}while(opc!=4);	
	return 0;
}
