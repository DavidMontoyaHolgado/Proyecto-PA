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
        int getValorar();
        void darOpinion(string);
        string* getOpinion();
};

clsValoracion::clsValoracion(){
    puntos = 0;
    cant = 0;
}

void clsValoracion::setValorar(int estrellas){
    puntos += estrellas;
    cant++;}

int clsValoracion::getValorar(){
    return (cant > 0) ? (puntos / cant) : 0;
    }

string* clsValoracion::getOpinion(){
    return opiniones;
}

void clsValoracion::darOpinion(string opinion){
    opiniones[cant] = opinion;}