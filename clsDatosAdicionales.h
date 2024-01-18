#include <iostream>
#include <string>
using namespace std;
class clsDatosAdicionales{
    private:
        int matriz[10][5];
    public:
        clsDatosAdicionales(){}
        void llenarStock(int, int, string *, string *);
        int (*getMatriz())[5];
};

void clsDatosAdicionales::llenarStock(int _cantX, int _cantY, string *_color, string *_talla){
    for(int i = 0; i < _cantX; i++){
        for(int j = 0; j < _cantY;j++){
            cout<<"Ingresa "<<_color[i]<<" talla "<<_talla[j]<<": ";
            cin>>matriz[i][j];
        }
    }
}

int (*clsDatosAdicionales::getMatriz())[5]{
    return matriz;
}