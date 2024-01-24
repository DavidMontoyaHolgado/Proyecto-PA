#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "clsProducto.h"
#include "../funciones/user.h"
using namespace std;

int cantValores(string* arreglo){
	int cant=0;
	while(!arreglo[cant].empty()){
		cant++;
	}
    return cant;
}

clsProducto::clsProducto(int idTienda, string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int* stock){
    //Dando valora  las propiedades
    int cantColorP = cantValores(coloresP);
    nombreProducto = nombre_Producto;
    categoria = idCategoria;
    categoriaTipo = idSubCategoria;
    cantColor = cantColorP;
    for(int i = 0; i < cantColorP;i++){
        colores[i] = coloresP[i];
    }

    //Se agrega el producto al inventario global
    ofstream archivo("../baseDatos/inventario/inventarioGlobal.txt", ios::app);
    int ID = cantRegistros("../baseDatos/inventario/inventarioGlobal.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo "<<endl;
    }
    archivo<<ID + cantRemoveG() + 1 <<" ("<<nombreProducto<<") "<<idTienda<<" "<<categoria<<" "<<categoriaTipo<<endl;
    archivo.close();

    //Para el inventario por categoría
    ifstream archivo1;
    archivo1.open("../baseDatos/Categoria.txt");
    string texto;
    int ini, fin;
        //Buscando el nombre de la categoría con el idCategoría
    char charId = (to_string(idCategoria))[0];
    while(getline(archivo1,texto)){
        if(texto.find(charId) != string::npos && texto.find(charId)<10){
            ini = texto.find('(');
            ini++;
            fin = texto.find(')',ini);
            nombreCategoria = texto.substr(ini,fin-ini);  
            break; 
        }
    }
    archivo1.close();
        //Eliminamos los espacios si es de la categoría 3 o 4
    if(idCategoria == 3 || idCategoria == 4){
        for(int i = 0; i < nombreCategoria.length();i++){
            if(nombreCategoria[i] == ' '){
                nombreCategoria.erase(i,1); //Elimina los espacios
                i--;
            }
        }
    }
        //Llenando datos en la categoría del producto
    nombreCategoria = "../baseDatos/inventario/"+ nombreCategoria + ".txt";
    int cant = cantRegistros(nombreCategoria);
    int j = 1;
    int cantInventCategoria;
    ifstream leer(nombreCategoria);
        //Hallamos el id del inventario de Categoria
    while(getline(leer,texto)){
        if(cant == j){
            cantInventCategoria = texto[0] - '0';
        }
        j++;
    }
    ofstream archivo2(nombreCategoria, ios::app);

    for(int i = 0; i < cantColor; i++){
        archivo2<<cantInventCategoria+ cantRemoveC(idCategoria) + 1<<" "<<ID + cantRemoveG() + 1<<" ("<<nombre_Producto<<") "<<idTienda<<" "<<idSubCategoria<<" "<<precio<<" "<<coloresP[i]<<" "<<stock[i]<<" "<<marca<<" "<<modelo<<" ("<<descripcion<<")"<<endl;
    }
}

//EN EL CASO DE QUE EL PRODUCTO SEA ROPA

clsProducto::clsProducto(int idTienda, string nombre_Producto,float precio,string descripcion,string marca, string modelo, int idCategoria, int idSubCategoria,string* coloresP, int** stock, string* tallas){
    //Dando valora  las propiedades
    int cantColorP = cantValores(coloresP);
    int cantTalla = cantValores(tallas);
    nombreProducto = nombre_Producto;
    categoria = idCategoria;
    categoriaTipo = idSubCategoria;
    cantColor = cantColorP;
    for(int i = 0; i < cantColorP;i++){
        colores[i] = coloresP[i];
    }

    //Se agrega el producto al inventario global
    int ID = cantRegistros("../baseDatos/inventario/inventarioGlobal.txt");
    ofstream archivo("../baseDatos/inventario/inventarioGlobal.txt", ios::app);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo "<<endl;
    }
    archivo<<ID+ cantRemoveG() + 1 <<" ("<<nombre_Producto<<") "<<idTienda<<" "<<categoria<<" "<<categoriaTipo<<endl;
    archivo.close();

    //Para el inventario por categoría
    ifstream archivo1;
    archivo1.open("../baseDatos/Categoria.txt");
    string texto;
    int ini, fin;
        //Hallamos el nombre de la categoría a base del idCategoría
    char charId = (to_string(idCategoria))[0];
    while(getline(archivo1,texto)){
        if(texto.find(charId) != string::npos && texto.find(charId)<10){
            ini = texto.find('(');
            ini++;
            fin = texto.find(')',ini);
            nombreCategoria = texto.substr(ini,fin-ini);  
            break; 
        }
    }
    archivo1.close();
        //Eliminamos los espacios si es de la categoría 3 o 4
    if(idCategoria == 3 || idCategoria == 4){
        for(int i = 0; i < nombreCategoria.length();i++){
            if(nombreCategoria[i] == ' '){
                nombreCategoria.erase(i,1); //Elimina los espacios
                i--;
            }
        }
    }
    archivo1.close();
        //Llenando datos en la categoría del producto
    nombreCategoria = "../baseDatos/inventario/"+ nombreCategoria + ".txt";
    int cant = cantRegistros(nombreCategoria);
    if(cant != 0){
        string leer;
        int m = 1;
        string pos;
        ifstream archivo2("../baseDatos/inventario/Ropa.txt");
        //Comparamos 
        while(getline(archivo2,leer)){
            if(m == cant){
                pos = leer.substr(0,leer.find(" "));
            }
            m++;
        }
        cant = stoi(pos);
        archivo2.close();
    }
    
        //Creamos un arreglo de stocks por tallas separas por una ","
    string* stocks = new string [cantColor];
    for(int i = 0; i < cantColor;i++){
        stocks[i] = "";
        for(int j = 0; j < cantTalla;j++){
            stocks[i] += to_string(stock[i][j]);
            if(j < cantTalla-1){
                stocks[i] += ',';
            }
        }
    }

    string tallasCadena="";
    //Ponemos las tallas separado por comas
    for(int i = 0; i < cantTalla;i++){
        tallasCadena += tallas[i];
        if(i < cantTalla-1){
            tallasCadena += ",";
        }
    }
    ofstream archivo2(nombreCategoria, ios::app);
    for(int i = 0; i < cantColor; i++){
        archivo2<<cant+ cantRemoveC(idCategoria) + 1<<" "<<ID + cantRemoveG() + 1<<" ("<<nombre_Producto<<") "<<idTienda<<" "<<idSubCategoria<<" "<<precio<<" "<<coloresP[i]<<" "<<tallasCadena<<" "<<stocks[i]<<" "<<marca<<" "<<modelo<<" ("<<descripcion<<")"<<endl;
    }
}
