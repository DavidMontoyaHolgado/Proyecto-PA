#include <iostream>
#include <string>
using namespace std;
class clsDatosAdicionales{
    private:
        int matriz[10][5];
        int arreglo[10];
    public:
        clsDatosAdicionales(){}
        void llenarStock(int, string *);
        void llenarStock(int, int, string *, string *);
        int (*getMatriz())[5];
        int *getArreglo();
};

void clsDatosAdicionales::llenarStock(int cantX, int cantY, string *color, string* talla){
    for(int i = 0; i < cantX; i++){
        for(int j = 0; j < cantY;j++){
            cout<<"Ingresa "<<color[i]<<" talla "<<talla[j]<<": ";
            cin>>matriz[i][j];
        }
    }
}

void clsDatosAdicionales::llenarStock(int cant, string* colores){
    for(int i = 0; i < cant;i++){
        cout<<"Ingresa el stock del "<<colores[i]<<": ";
        cin>>arreglo[i];
    }
}

int * clsDatosAdicionales::getArreglo(){return arreglo;}

int (*clsDatosAdicionales::getMatriz())[5]{return matriz;}