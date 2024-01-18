#include <iostream>
#include <string>
using namespace std;
class clsValoracion{
    private:
        int puntos;
        string opiniones[100];
        int cant;
        int cantOp;
    public:
        clsValoracion();    
        void setValorar(int);
        void setValorar(int, string);
        int getValoracion();
        void getOpinion();
};

clsValoracion::clsValoracion(){
    puntos = 0;
    cant = 0;
    cantOp = 0;
}

void clsValoracion::setValorar(int estrellas){
    puntos += estrellas;
    cant++;}

void clsValoracion::setValorar(int estrellas, string valorar){
    puntos += estrellas;
    opiniones[cant] = valorar;
    cant++;
    cantOp++;
}

int clsValoracion::getValoracion(){
    return (cant > 0) ? (puntos / cant) : 0;
    }

void clsValoracion::getOpinion(){
    for(int i = 0; i < cantOp; i++){
        cout<<opiniones[i]<<endl;
    }
}