#include<iostream>
#include "login.h"
#include "../funciones/user.h"
using namespace std;

loginCuenta::loginCuenta(string _nombres, string _apellido, string _correo, string _clave){
	nombre = _nombres;
	apellido = _apellido;
	correo = _correo;
	clave = _clave;    
}

void loginCuenta::crearCu(string nombre, string apellido, string correo, string clave, int edad, int identificacion){
	int n = cantRegistros("../baseDatos/usuarios.txt");
       int pos=0;
	   int i=0;
	
	while(i<n and correos()[i]!=correo){
		
		i=i+1;
	}
	
	if(i>n or claves()[i]==correo){
		pos=i+1;
	}else{
		pos=-i-1;
	}

	if(pos>0){
    	cout<<"El correo  "<<correo<<" ya existe "<<pos<<endl;
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
	   //bool cen=0;
	  // bool cen=1;
	
	while(i<n and correos()[i]!=correo){
		
		i=i+1;
	}
	
	if(i>n or correos()[i]==correo){
		pos=i+1;
	}else{
		pos=-i-1;
	}


	if(pos>0){
    	
    //	cout<<"El correo  "<<correo<<" ya existe "<<pos<<endl;
    
         if(claves[pos-1]==clave){
         	
         	cout<<endl;
         	cout<<"Bienvenidos al sistema "<<endl;
			
		 }else{
		 	
		 	cout<<"El Correo y/o la clave son incorrectas"<<endl;
		 }
		 
    
	}else{
		
		
		cout<<"El Correo y/o la clave son incorrectas"<<endl;
	}
	
}

void loginCuenta::cerrarSe(){
	
	cout<<"MUCHAS GRACIAS POR VISITARNOS "<<endl;;
	cout<<endl;
}



int main(){
	
	 string A[6]= {"@unjbg", "@gmail","@hotmail","@live","@crome" , "@patita"}; //correos
     string B[6]={"1234","456","789","abc","asd","159"};  //contrase�as
     const int n = sizeof(A) / sizeof(A[0]);
     //const int m = sizeof(B) / sizeof(B[0]);
    
    int opc;
    string nombre,correo,clave;
    loginCuenta cuenta(nombre,correo,clave);
    
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
		      	
			  	cuenta.iniciarSe(A,B,n,correo,clave);
			  	cout<<endl;
			  	break;
			
			  case 2:
		             cout<<"Nombre: ";
	                cin>>nombre;
	                cout<<"Correo: ";
                	cin>>correo;
                	cout<<"Clave : ";
	                cin>>clave;
	                cout<<endl;
			  	         
			  	cuenta.crearCu(A,n,correo);
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
    
	
	
/*	string nombre,correo,clave;
	
	loginCuenta cuenta(nombre,correo,clave);
	
	cout<<"nombre: ";
	cin>>nombre;
	cout<<"correo: ";
	cin>>correo;
	cout<<"clave : ";
	cin>>clave;
	
	
     cuenta.iniciarSe(A,B,n,correo,clave);*/
	
 //cuenta.crearCu(A,n,correo);
	
	return 0;
}

