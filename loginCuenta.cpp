
#include<bits/stdc++.h>
#include<string.h>

#define USER "alex"
#define PASS "gaaa"

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
	   void iniciarSe(string nombre,string correo,string clave);
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

/*void loginCuenta::iniciarSe(string nombre,string correo, string clave){
	
      if(correo == USER and clave == PASS){
		
		cout<<" Bienvenido al sistema "<<endl;
	}else{
		cout<<"El Correo y/o la clave son incorrectas "<<endl;
	}
	
	
}*/

int main(){
	
	 string A[6]= {"@unjbg", "@gmail","@hotmail","@live","@crome" , "@patita"};
     string B[6]={"1234","456","789","abc","asd","159"};
     const int n = sizeof(A) / sizeof(A[0]);
     const int m = sizeof(B) / sizeof(B[0]);
    
	
	
	string nombre,correo,clave;
	
	loginCuenta cuenta(nombre,correo,clave);
	
	cout<<"nombre: ";
	cin>>nombre;
	cout<<"correo: ";
	cin>>correo;
	cout<<"clave : ";
	cin>>clave;
	
   //  cuenta.iniciarSe(nombre,correo,clave);
	
 cuenta.crearCu(A,n,correo);
	
	return 0;
}















