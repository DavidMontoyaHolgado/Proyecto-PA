#include<bits/stdc++.h>
using namespace std;
 
 int n=0;
  string A[100]; //= {"@unjbg", "@gmail","@hotmail","@live","@crome" , "@patita"};
    //const int n = sizeof(A) / sizeof(A[0]);
 
 

class loginCuenta{
	private:
		string nombres;
		string correo;
		string clave;
	public:
	   loginCuenta(string,string,string);
	   void crearCu(string *A, int n,string correo);
	   void iniciarSe();
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
	bool cen=0;
	
	while(i<n and A[i]!=correo){
		
		i=i+1;
	}
	
	if(i<n){
		pos=i+1;
	}else{
		pos=-1;
	}
	
   
   if(pos>0){
   	cout<<"El correo "<<correo<<" ya existe "<<pos<<endl;
   }else{
   	
   	//cout<<"El correo "<<correo<<" no se encuentra creada."<<endl;
   	cen=1;
   }
   
   
   if(cen==1){
   	 
   	 A[n]=correo;
   	n++;  
   }
	
}

int main(){
	
	string nom,correo,clave;
	cout<<"nombre: ";
	cin>>nom;
	cout<<"correo: ";
	cin>>correo;
	cout<<"clave : ";
	cin>>clave;
	
	
	loginCuenta cuenta(nom,correo,clave); 
	cuenta.crearCu(A,n,correo);
	
	for(int i=0;i<=n;i++){
		cout<<A[i]<<endl;
	}
	
	
	return 0;
}

