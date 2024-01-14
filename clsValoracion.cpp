#include <iostream>
#include <string>
using namespace std;
class clsValoracion{
    private:
        int puntos;
        string opiniones[100];
        int cant;
    public:
        clsValoracion();    
        void setValorar(int);
        void setValorar(int, string);
        int getValoracion();
        string* getOpinion();
};

clsValoracion::clsValoracion(){
    puntos = 0;
    cant = 0;
}

void clsValoracion::setValorar(int estrellas){
    puntos += estrellas;
    cant++;}

void clsValoracion::setValorar(int estrellas, string valorar){
    puntos += estrellas;
    opiniones[cant] = valorar;
    cant++;
}

int clsValoracion::getValoracion(){
    return (cant > 0) ? (puntos / cant) : 0;
    }

string* clsValoracion::getOpinion(){
    return opiniones;
}