#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

string enMinuscula(string palabra){
    for(int i = 0; i < palabra.length();i++){
        palabra[i] =  tolower(palabra[i]);
    }
    return palabra;
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
    ofstream archivo("./baseDatos/inventario/inventarioGlobal.txt", ios::app);
    int ID = cantRegistros("./baseDatos/inventario/inventarioGlobal.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo "<<endl;
    }
    archivo<<ID + cantRemoveG() + 1 <<" ("<<nombreProducto<<") "<<idTienda<<" "<<categoria<<" "<<categoriaTipo<<endl;
    archivo.close();

    //Para el inventario por categoría
    ifstream archivo1;
    archivo1.open("./baseDatos/Categoria.txt");
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
    nombreCategoria = "./baseDatos/inventario/"+ nombreCategoria + ".txt";
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
    int ID = cantRegistros("./baseDatos/inventario/inventarioGlobal.txt");
    ofstream archivo("./baseDatos/inventario/inventarioGlobal.txt", ios::app);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo "<<endl;
    }
    archivo<<ID+ cantRemoveG() + 1 <<" ("<<nombre_Producto<<") "<<idTienda<<" "<<categoria<<" "<<categoriaTipo<<endl;
    archivo.close();

    //Para el inventario por categoría
    ifstream archivo1;
    archivo1.open("./baseDatos/Categoria.txt");
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
    nombreCategoria = "./baseDatos/inventario/"+ nombreCategoria + ".txt";
    int cant = cantRegistros(nombreCategoria);
    if(cant != 0){
        string leer;
        int m = 1;
        string pos;
        ifstream archivo2("./baseDatos/inventario/Ropa.txt");
        //Comparamos 
        while(getline(archivo2,leer)){
            if(m == cant){
                pos = leer.substr(0,leer.find(" "));
            }
            m++;
        }
        archivo2.close();
        cant = stoi(pos);
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




float clsProducto::mostrarProducto(int idPRoducto){
    ifstream archivo1("./baseDatos/inventario/inventarioGlobal.txt");
    string texto;
    string producto;
    int i = 1;
    //Guardando toda la información del producto
    while(getline(archivo1,texto)){
        if(idPRoducto == i){
            producto = texto;
        }
        i++;
    }
    archivo1.close();
    //Encontrando la categoria del producto
    int posI = 0;
    int posF = 0;
    posI = producto.find(")");
    posI += 2;
    posI = producto.find(" ",posI);posI++;
    posF = producto.find(" ",posI);posF--;
    string ruta = producto.substr(posI,posF-posI+1);
    int idCategoria = stoi(ruta);
    //Ruta del producto
    ifstream archivo2("./baseDatos/Categoria.txt");
    i =1;
    string categoria;
    //Encontrando el nombre del producto
    while(getline(archivo2,texto)){
        if(i == stoi(ruta)){
            posI = texto.find("(");posI++;
            posF = texto.find(")",posI);
            categoria = texto.substr(posI,posF-posI);
            break;
        }
        i++;
    }
    archivo2.close();

    for (int w = 0; w < categoria.length(); w++) {
        if (categoria[w] == ' ') {
        categoria.erase(w, 1);
        }
    }

    //Agarrando los productos con el mismo ID
    ruta = "./baseDatos/inventario/" + categoria + ".txt";
    ifstream archivo3(ruta);
    string productos[5];
    i = 0;
    string productoTxt;
    while(getline(archivo3,texto)){
        posI = texto.find("(");posI++;
        posF = texto.find(")", posI);
        productoTxt = producto.substr(producto.find("(")+1,producto.find(")")-producto.find("(")-1);
        if(enMinuscula(texto.substr(posI,posF-posI)) == enMinuscula(productoTxt)){
            productos[i] = texto;
            i++;
            break;
        }
    }

    //CONSEGUIMOS LOS DATOS DEL PRODUCTO
    //COLORES
    string colores[5];
    int n;
    string coloresCadena="";
    for(int j = 0; j < i; j++){
        posI = productos[j].find(")");
        posI+=2;
        posI = productos[j].find(" ",posI);posI++;
        posI = productos[j].find(" ",posI);posI++;
        posI = productos[j].find(" ",posI);posI++;
        posF = productos[j].find(" ",posI);posF--;
        colores[j] = productos[j].substr(posI,posF-posI+1);
        n=posF + 2;
        if(j +1 == i){
            coloresCadena+= colores[j] + ".";
            break;
        }
        coloresCadena+= colores[j] + ",";
        //Guardamos el indice final de los colores
    }
    //NOMBRE
    posI = productos[0].find("(");posI++;
    posF = productos[0].find(")");posF--;
    string nombreProducto = producto.substr(posI-2,posF-posI+1);
        
    //PRECIO
    float Precio;
    posI = productos[0].find(")");
    posI+=2;
    posI = productos[0].find(" ",posI);posI++;
    posI = productos[0].find(" ",posI);posI++;
    posF = productos[0].find(" ",posI);posF--;
    Precio = stof(productos[0].substr(posI,posF-posI+1));
    if(idCategoria != 1){

        //MARCA
        string marca;
        posI = productos[0].find(" ",n);posI++;
        posF = productos[0].find(" ",posI);posF--;
        marca = productos[0].substr(posI,posF-posI+1);

        //MODELO
        string modelo;
        posI = productos[0].find("(",posF);posI++;
        posF = productos[0].find(")",posI);posF--;
        modelo = productos[0].substr(posI,posF-posI+1);

        //DESCRIPCION
        string descripcion;
        posI = productos[0].find("(",posF);posI++;
        posF = productos[0].find(")",posI);posF--;
        descripcion = productos[0].substr(posI,posF-posI+1);
        
        cout << " ===================================================================================" << endl;
        cout << " |                           DATOS DEL PRODUCTO                                    |" << endl;
        cout << " ===================================================================================" << endl;
        cout << " | " << left << setw(20) << "Nombre:" << "| " << left << setw(57) << nombreProducto << " |" << endl;
        cout << " | " << left << setw(20) << "Precio:" << "| " <<"S/."<< left << setw(54) <<Precio << " |" << endl;
        cout << " | " << left << setw(20) << "Marca:" << "| " << left << setw(57) << marca << " |" << endl;
        cout << " | " << left << setw(20) << "Modelo:" << "| " << left << setw(57) << modelo << " |" << endl;
        if(coloresCadena.find(' ') != std::string::npos){
            cout << " | " << left << setw(20) << "Colores:" << "| " << left << setw(57) << coloresCadena << " |" << endl;
        }else{
            cout << " | " << left << setw(20) << "Color:" << "| " << left << setw(57) << coloresCadena << " |" << endl;
        }
        cout << " | " << left << setw(20) << "Descripción:" << "| " << left << setw(57) << descripcion << " |" << endl;
        cout << " ===================================================================================" << endl;
    }else{
        //TALLA
        string tallas;
        posI = n;
        posF = productos[0].find(" ",posI);posF--;
        tallas = productos[0].substr(posI+1,posF-posI-1);
        //MARCA
        string marca;
        posI = productos[0].find(")",posF+1);
        posI+= 3;
        posF = productos[0].find(" ",posI);posF--;
        marca = productos[0].substr(posI,posF-posI);

        //MODELO
        string modelo;
        posI = productos[0].find("(",posF);posI++;
        posF = productos[0].find(")",posI);posF--;
        modelo = productos[0].substr(posI,posF-posI+1);

        //DESCRIPCION
        string descripcion;
        posI = productos[0].find("(",posF);posI++;
        posF = productos[0].find(")",posI);posF--;
        descripcion = productos[0].substr(posI,posF-posI+1);

        cout << " ===================================================================================" << endl;
        cout << " |                           DATOS DEL PRODUCTO                                    |" << endl;
        cout << " ===================================================================================" << endl;
        cout << " | " << left << setw(20) << "Nombre:" << "| " << left << setw(57) << nombreProducto << " |" << endl;
        cout << " | " << left << setw(20) << "Precio:" << "| " <<"S/."<< left << setw(54) <<Precio << " |" << endl;
        cout << " | " << left << setw(20) << "Marca:" << "| " << left << setw(57) << marca << " |" << endl;
        cout << " | " << left << setw(20) << "Modelo:" << "| " << left << setw(57) << modelo << " |" << endl;
        if(coloresCadena.find(' ') != string::npos){
            cout << " | " << left << setw(20) << "Colores:" << "| " << left << setw(57) << coloresCadena << " |" << endl;
        }else{
            cout << " | " << left << setw(20) << "Color:" << "| " << left << setw(57) << coloresCadena << " |" << endl;
        }
        if(tallas.find(',') != string::npos){
            cout << " | " << left << setw(20) << "Talla:" << "| " << left << setw(57) << tallas << " |" << endl;
        }else{
            cout << " | " << left << setw(20) << "Tallas:" << "| " << left << setw(57) << tallas << " |" << endl;
        }
        cout << " | " << left << setw(20) << "Descripción:" << "| " << left << setw(57) << descripcion << " |" << endl;
        cout << " ===================================================================================" << endl;
    }
    return Precio;
}