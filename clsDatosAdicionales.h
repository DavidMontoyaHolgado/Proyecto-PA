#include <iostream>
#include <string>
using namespace std;
string colores []= {"Rojo","verde","azul","morado","anaranjado", };
class clsDatosAdicionales{
    private:
        string ejeX;
        string ejeY;
        int fila;
        int columna;
        int matriz[10][5];
    public:
        clsDatosAdicionales(int, int);
        void llenarStock(string *, string *);
        int (*getMatriz())[5];
        void mostrarDatos();
};

clsDatosAdicionales::clsDatosAdicionales(int _cantX, int _cantY){
    ejeX = "Talla";
    ejeY = "Color";
    fila = _cantX;
    columna = _cantY;
}

void clsDatosAdicionales::llenarStock(string *_color, string *_talla){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna;j++){
            cout<<"Ingresa "<<_color[i]<<" talla "<<_talla[j]<<": ";
            cin>>matriz[i][j];
        }
    }
}

int (*clsDatosAdicionales::getMatriz())[5]{
    return matriz;
}