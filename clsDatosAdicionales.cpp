#include <iostream>
#include <string>
using namespace std;

class clsDatosAdicionales{
    private:
        string ejeX;
        string ejeY;
        int cantX;
        int cantY;
        int matriz[100][100];
    public:
        clsDatosAdicionales(string, string, int, int);
        void llenarStock();
};

clsDatosAdicionales::clsDatosAdicionales(string _ejeX, string _ejeY, int _cantX, int _cantY){
    ejeX = _ejeX;
    ejeY = _ejeY;
    cantX = _cantX;
    cantY = _cantY;
}

 void clsDatosAdicionales::llenarStock(){
    for(int y = 0; y < cantY; y++){
        for(int x = 0; x <cantX; x++){
            
        }
    }
 }