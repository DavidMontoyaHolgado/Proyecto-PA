#include <iostream>
#include <string>
#include <fstream>
#include "clsTienda.h"
#include "clsProducto.h"
#include "../funciones/user.h"
#include <typeinfo>

using namespace std;

clsTienda::clsTienda(){}

clsTienda::clsTienda(string nombreT, int RUC){
    nombreTienda = nombreT;
    ruc = RUC;
    ifstream archivo("../baseDatos/tiendas.txt");
    string texto, subTexto;
    int i, j;
    bool creado = false;
    id = 0;
        //Verificando si la tienda existe
    while(getline(archivo, texto)){
        i = texto.find("(");
        i++;
        j = texto.find(")",i);
        subTexto = texto.substr(i,j-i);
        if(nombreTienda == subTexto){
            creado = true;
            id++;
        } 
    } //Se añade la tienda si no existe anteriormente
    if(!creado){
        string ruta = "../baseDatos/tiendas.txt";
        id = cantRegistros(ruta);
        id ++;
        ofstream tiendas2;
        tiendas2.open("../baseDatos/tiendas.txt",ios::app);
        tiendas2<<id<<" ("<<nombreTienda<<") "<<ruc<<endl;
        tiendas2.close();
    }
}

void clsTienda::agregarProducto(string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int* stock){
    Producto = clsProducto(id, nombre_Producto, precio, descripcion,marca, modelo, idCategoria, idSubCategoria,coloresP, stock);
}

void clsTienda::agregarProductoRopa(string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int** stock, string* tallas){
    Producto = clsProducto(id,nombre_Producto,precio, descripcion,marca,modelo,idCategoria, idSubCategoria, coloresP,stock, tallas);
}



void clsTienda::eliminarProducto(int idProducto){
    string urlInventario = "../baseDatos/inventario/inventarioGlobal.txt";
    //ELIMINANDO DEL INVENTARIO GLOBAL
    int cantidad = cantRegistros(urlInventario);
    string* arreglo = new string[cantidad];
    ifstream archivo(urlInventario);
    int i = 0;
    //Guardando los datos del archivo en un arreglo
    while(getline(archivo,arreglo[i]))
        i++;
    int id;
    int pos = 0;
    archivo.close();
    //Buscando la posición del Producto
    ifstream archivo2(urlInventario);
    string texto;
    string idProductoS = to_string(idProducto);
    while(getline(archivo2, texto)){
        pos++;
        if(texto.substr(0,texto.find(" ")) == idProductoS){
            break;
        }
    }

    archivo2.close();
    //Removemos el producto
    string dato = arreglo[pos - 1]; //Guardamos el valor eliminado
    for(int i = pos-1; i < cantidad-1;i++){
        arreglo[i] = arreglo[i + 1]; 
    }
    ofstream archivo3(urlInventario,ios::trunc);
    for(int i = 0; i < cantidad-1;i++){
        archivo3<<arreglo[i]<<endl;
    }
    archivo3.close();
    
    //ELIMINAMOS DEL INVENTARIO POR CATEGORÍA
    int posDato = dato.find(")");
    posDato+=4;
    texto = "";

    //Estamos obteniendo el nombre de la categoría
    string idCategoria =to_string(dato[posDato] - '0');
    string nameCategoria;
    int m, n;
    fstream archivo4("../baseDatos/Categoria.txt", ios::in);
    while(getline(archivo4, texto)){
        if(texto.substr(0, texto.find(" ")) == idCategoria){
            m = texto.find("(");m++;
            n = texto.find(")",m);n--;
            nameCategoria = texto.substr(m, n - m+1);
            break;
        }
    }
    archivo4.close();
    //Eliminamos los espacios de las categorías
    for(int k = 0; k < nameCategoria.length();k++){
        if(nameCategoria[k] == ' '){
            nameCategoria.erase(k,1); //Elimina los espacios
            k--;
        }
    }
    //Hallamos la posición del producto en el inventario por categoría
    string rutaInventCate = "../baseDatos/inventario/" + nameCategoria + ".txt";
    ifstream archivo5(rutaInventCate);
    string idInven, idInvenCat;
    texto = "";
    string posInvenCat;
    int x=0;
    string inventGlobal = dato.substr(0,dato.find(" "));
    //Hallamos la posición del producto en el inventario de categoría
    while(getline(archivo5, texto)){
        m = texto.find(" ");m++;
        n = texto.find(" ",m);n--;
        posInvenCat = texto.substr(m,n-m+1);
        x++;
        if(posInvenCat == inventGlobal){
            break;
        }
    }
    archivo5.close();
    //Guardando los datos del inventario de categoría
    int cantInventCat =  cantRegistros(rutaInventCate);
    string* arregloCategoría = new string [cantInventCat];
    i = 0;
    ifstream archivo6(rutaInventCate);
    while(getline(archivo6,arregloCategoría[i]))
        i++;
    archivo6.close();
    //Removemos el producto que se quiere eliminar
    for(int ii = x-1; ii < cantInventCat-1;ii++){
        arregloCategoría[ii] = arregloCategoría[ii + 1]; 
    }
    //Insertamos los datos al inventario por Categoría sin el producto
    ofstream archivo7(rutaInventCate, ios::trunc);
    for(int iii = 0; iii < cantInventCat - 1; iii++)
        archivo7<<arregloCategoría[iii]<<endl;
    archivo7.close();
    //
    ifstream archivo8("../baseDatos/inventario/incremento.txt");
    string* incremento = new string [7];
    i = 0;
    while(getline(archivo8,incremento[i]))
        i++;
    archivo8.close();
    int cantRemove;
    int a;
    //Incrementamos en uno al incremento.txt en remove de inventario global y en el inventario en específico del producto
    for(int jj = 0; jj < 7;jj++){
         if(jj == 0 || jj == stoi(idCategoria)){
            a = incremento[jj].find(" ",2);
            cantRemove = stoi(incremento[jj].substr(2,a-2));
            cantRemove++;
            incremento[jj] = to_string(jj) + " " + to_string(cantRemove);
        }
    }
    //Sobrescribimos el archivo incremento
    ofstream archivo9("../baseDatos/inventario/incremento.txt", ios::trunc);
    for(int jj= 0; jj < 7;jj++)
        archivo9<<incremento[jj]<<endl;
    archivo9.close();
}