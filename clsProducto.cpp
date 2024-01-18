#include <iostream>
#include <string.h>
#include "clsDatosAdicionales.h"
using namespace std;

class clsProducto{
    public:
        string nombre;
        float precio;
        string descripcion;
        string marca;
        string modelo;
        string categoria;
        string categoria_tipo;
        string colores[10];
        int cantColor;
        clsDatosAdicionales Stock;
    public:
        clsProducto(string, float, string, string, string, string,string, string*,int);
        void llenarStockP();
        void llenarStockP(int, string *);
        string setNombre();
        float setPrecio();
        void mostrarDatos();
};

clsProducto::clsProducto(string nombreP, float precioP, string descripcionP, string marcaP,string modeloP, string _categoria, string categoria_tipo,string* coloresP, int cantColorP){
    nombre = nombreP;
    precio = precioP;
    descripcion = descripcionP;
    marca = marcaP;
    modelo = modeloP;
    categoria = _categoria;
    categoria_tipo = categoria_tipo;
    cantColor = cantColorP;
    for(int i = 0; i < cantColorP;i++){
        colores[i] = coloresP[i];
    }
}

void clsProducto::llenarStockP(){Stock.llenarStock(cantColor, colores);}

void clsProducto::llenarStockP(int cantTalla, string* talla){Stock.llenarStock(cantColor, cantTalla,colores, talla);}

string clsProducto::setNombre(){return nombre;}

float clsProducto::setPrecio(){return precio;}

void clsProducto::mostrarDatos(){
    cout<<"Nombre "<<nombre<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Precio: "<<precio<<endl;
    cout<<"Descripcion: "<<descripcion<<endl;
}

int main(){
    string colores[] = {"Rojo", "Morado", "Azul", "Amarillo"};
    clsProducto Celular("aifon 20", 20, "Es de buena calidad", "iafon", "12", "Tecnologia", "Celulares", colores,4); 
    Celular.mostrarDatos();
    Celular.llenarStockP();
    int* Datos = Celular.Stock.getArreglo();
    for(int i = 0; i < 4;i++){
        cout<<Datos[i]<<' ';
    }
    return 0;
}