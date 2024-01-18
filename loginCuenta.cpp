
#include<bits/stdc++.h>
#include<string.h>

#define USER 
#define PASS 

using namespace std;
 
 //const int n=0;
 // string A[100]; 
  // string B[100];
 
 
 /*string A[6]= {"@unjbg", "@gmail","@hotmail","@live","@crome" , "@patita"};
 string B[6]={"1234","456","789","abc","asd","159"};
    const int n = sizeof(A) / sizeof(A[0]);
    const int m = sizeof(B) / sizeof(B[0]);*/
    
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

loginCuenta::loginCuenta(string _nombres, string _correo, string _clave){
	
	      nombres = _nombres;
		  correo = _correo;
		  clave = _clave;    
}

void loginCuenta::crearCu(string *A,int n,string correo){
	
       int pos=0;
	   int i=0;
	
	while(i<n and A[i]!=correo){
		
		i=i+1;
	}
	
	if(i>n or A[i]==correo){
		pos=i+1;
	}else{
		pos=-i-1;
	}


	if(pos>0){
    	
    	cout<<"El correo  "<<correo<<" ya existe "<<pos<<endl;
	}else{
		
		
		cout<<"Cuenta creada exitosamente"<<endl;
	}
	
	
}

void loginCuenta::iniciarSe(string *A,string *B,int n,string correo, string clave){
	
	
	
	  int pos=0;
	   int i=0;
	   //bool cen=0;
	  // bool cen=1;
	
	while(i<n and A[i]!=correo){
		
		i=i+1;
	}
	
	if(i>n or A[i]==correo){
		pos=i+1;
	}else{
		pos=-i-1;
	}


	if(pos>0){
    	
    //	cout<<"El correo  "<<correo<<" ya existe "<<pos<<endl;
    
         if(B[pos-1]==clave){
         	
         	cout<<endl;
         	cout<<"Bienvenidos al sistema "<<endl;
		 }else{
		 	
		 	cout<<"El Correo y/o la clave son incorrectas"<<endl;
		 }
		 
    
	}else{
		
		
		cout<<"El Correo y/o la clave son incorrectas"<<endl;
	}
	
	
	
}

int main(){
	
	 string A[6]= {"@unjbg", "@gmail","@hotmail","@live","@crome" , "@patita"}; //correos
     string B[6]={"1234","456","789","abc","asd","159"};  //contraseñas
     const int n = sizeof(A) / sizeof(A[0]);
     //const int m = sizeof(B) / sizeof(B[0]);
    
    int opc;
    string nombre,correo,clave;
    loginCuenta cuenta(nombre,correo,clave);
    
    do{
		
		cout<<"1. Iniciar Secion. "<<endl;
		cout<<"2. Crear Cuenta."<<endl;
		cout<<"3. Salir de la pagina."<<endl;
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
			  	break;
			
		}
		
	}while(opc!=3);	
    
	
	
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















