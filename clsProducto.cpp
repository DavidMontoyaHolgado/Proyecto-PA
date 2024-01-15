#include <iostream>
#include <string.h>
using namespace std;
class clsProducto{
    private:
        string nombre;
        float precio;
        string descripcion;
        string marca;
        string tipo;
    public:
        clsProducto(string, float, string, string, string);
        string setnombre();
        float setPrecio();
        void mostrarDatos();
};

clsProducto::clsProducto(string nombreP, float precioP, string descripcionP, string marcaP, string tipoP){
    nombre = nombreP;
    precio = precioP;
    descripcion = descripcionP;
    marca = marcaP;
    tipo = tipoP;
}

string clsProducto::setnombre(){return nombre;}

float clsProducto::setPrecio(){return precio;}

void clsProducto::mostrarDatos(){
    cout<<"Nombre "<<nombre<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Precio: "<<precio<<endl;
    cout<<"Descripcion: "<<descripcion<<endl;
}