#include<iostream>
#include<string.h>
using namespace std;

class Buscador{
	private:
		string producto;
	public:
	  Buscador(string );
	  void clsBuscador(string *A,int n, string tienda);
	 // void buscarProducto(string)	
      //void añadirAlCarrito();	
};

Buscador::Buscador(string _producto){
	
	producto=_producto;
}

// *A =tienda
void Buscador::clsBuscador(string *A,int n, string tienda){
	
	int pos=0;
	   int i=0;
	
	while(i<n and A[i]!=tienda){
		
		i=i+1;
	}
	
	if(i>n or A[i]==tienda){
		pos=i+1;
	}else{
		pos=-i-1;
	}


	if(pos>0){
    	
    	cout<<"La tienda  "<<tienda<<" si existe "<<pos<<endl;
	}else{
		
		
		cout<<"No se encontro dicha tienda"<<endl;
	}
	
}





int main(){
	
	string A[6]= {"D'moda", "sagaFalavela","Electro","@live","Efe" , "El_gallo"}; //correos
	const int n = sizeof(A) / sizeof(A[0]);
	
	string tnd;
	
	Buscador tienda("celular");
	
	cout<<"ingrese la tienda que desea: "; cin>>tnd; 
	
	tienda.clsBuscador(A,n,tnd);
	
	return 0;
}

