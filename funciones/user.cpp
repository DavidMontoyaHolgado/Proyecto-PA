#include <iostream>
#include <fstream>
#include "user.h"
#include <string>
#include <cctype>
using namespace std;;


void agregarUsuario(string nombre,string apellido, string correo, string clave, int edad, int dni){
    ofstream archivo;
    archivo.open("./baseDatos/usuarios.txt", ios::app);

    if(!archivo.is_open()){
        cout<<"Error: No se pudo abrir el archivo"<<endl;
    }
    archivo<<cantRegistros("./baseDatos/usuarios.txt") + 1<<" ("<<nombre<<" "<<apellido<<") "<<correo<<" "<<clave<<" "<<edad<<" "<<dni<<endl;
    archivo.close();
}

int cantUser(){
    ifstream archivo;
    string texto;
    int cant = 0;   
    const string ruta = "./baseDatos/usuarios.txt";
    archivo.open(ruta);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
        return -1;
    }
    while (getline(archivo,texto)){
        cant++;
    }
    archivo.close();
    return cant;
}

int cantRegistros(string rutaTXT){
    ifstream archivo;
    string texto;
    int cant = 0;   
    archivo.open(rutaTXT);
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<rutaTXT<<endl;
        return -1;
    }
    while (getline(archivo,texto)){
        cant++;
    }
    archivo.close();
    return cant;
}

int cantRemoveG(){
    string ruta =  "../baseDatos/inventario/incremento.txt";
    string* arreglo = new string[8];
    ifstream  archivo(ruta,ios::in);
    if (!archivo.is_open()) {
        cout << "Error opening file: "<<endl;
        return 0; 
    }
    //Guardamos el .txt en el arreglo
    int i = 0;
    while(getline(archivo,arreglo[i])){
        i++;
    }
    archivo.close();
    int cant = stoi(arreglo[0].substr(2, arreglo[0].find(" ",2)));
    return cant;
}

int cantRemoveC(int idCategoria){
    string ruta =  "../baseDatos/inventario/incremento.txt";
    string* arreglo = new string[8];
    ifstream  archivo(ruta,ios::in);
    if (!archivo.is_open()) {
        cout << "Error opening file: "<<endl;
        return 0; 
    }
    //Guardamos el .txt en el arreglo
    int i = 0;
    while(getline(archivo,arreglo[i])){
        i++;
    }
    archivo.close();
    int cant = stoi(arreglo[0].substr(2, arreglo[idCategoria].find(" ",2)));
    return cant;
}

string* nombres(){
    ifstream archivo;
    string texto;
    int i=0;
    int j = 0;
    int k = 0;
    string* _nombres = new string[100];
    archivo.open("./baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo"<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find("(");
        i++;
        j = texto.find(")", i);
        _nombres[k] = texto.substr(i,j - i);
        k++;
    }
    archivo.close();
    return _nombres;
}

string* Correos(){
    string texto;
    int i = 0;
    int j = 0;
     int k = 0;
    string* _correos = new string [100];
    ifstream archivo;
    archivo.open("./baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cout<<"Error: No se pudo abrir el archivo"<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find(")");
        i+=2;
        j = texto.find(" ",i);j--;
        _correos[k] = texto.substr(i,j-i+1);
        k++;
    }
    archivo.close();
    return _correos;
}

string* claves(){
    ifstream archivo;
    string texto;
    int i = 0;
    int j = 0;
    int k = 0;
    string* Claves = new string [100];
    archivo.open("./baseDatos/usuarios.txt");
    if(!archivo.is_open()){
        cerr<<"Error: No se pudo abrir el archivo-----"<<endl;
        return {};
    }
    while(getline(archivo,texto)){
        i = texto.find(")");
        i+= 2;
        i = texto.find(" ", i);i++;
        j = texto.find(" ",i);j--;
        Claves[k] = texto.substr(i, j - i + 1);
        k++;
    }
    archivo.close();
    return Claves;
}   

void crearRegistro(string nombre){
    string id = to_string(cantRegistros("./baseDatos/usuarios.txt"));
	int pos;
	for(int i= 0; i < nombre.length();i++){
		if(nombre[i] == ' '){
			pos = nombre.find(" ");
			nombre = nombre.substr(0,pos);
			break;
		}
	}
    string ruta = "./baseDatos/registroDeCompra/" + nombre + "_" + id + ".txt";
    ofstream archivo(ruta, ios::out);
    if(!archivo.is_open()){
        cerr<<"Error al abrir el archivo";
        exit(1);
    }
    archivo.close();

	ifstream archivo1("./baseDatos/usuarios.txt");
	string texto, usuario;
	pos =1;
	//Obtenemos los datos del usuario
	while(getline(archivo1,texto)){
	    if(pos == stoi(id)){
		    usuario = texto;
		    break;
        }
	    pos++;
	}

	//Obtenemos el nombre del usuario
	archivo1.close();
	int posI = usuario.find("(");posI++;
	int posF = usuario.find(" ",posI);
	usuario = usuario.substr(posI, posF-posI);
	//Ruta del carrito de cada usuario
	ruta = "./baseDatos/registroDeCarrito/" + usuario + "_" + id + ".txt";
    ofstream archivo2(ruta, ios::out);
    if(!archivo2.is_open()){
        cerr<<"Error al abrir el archivo";
        exit(1);
    }
    archivo2.close();
}

void agregarRegistro(string CompraOCarrito, int IDuser, int IDproducto, int unidades, float gasto){
    ifstream archivo("./baseDatos/usuarios.txt");
    int pos,posI,posF;
    string leer, sub, nombre;
    string stringID = to_string(IDuser);
    //Buscando el nombre del usuario
    while(getline(archivo,leer)){
        pos = leer.find(" ");
        sub = leer.substr(0, pos);
        if(sub == stringID){
            posI = leer.find("(");
            posF = leer.find(" ", posI);
            nombre = leer.substr(posI + 1, posF - posI-1);
            break;
        }
    }
    archivo.close();
    if(nombre.empty()){
        cerr<<"No se encontro el usuario"<<endl;
        exit(1);
    }
    //Nos aseguramos que el nombre inicie con mayuscula y lo demás en minúscula
    CompraOCarrito[0] = toupper(CompraOCarrito[0]);
    for(int i = 1; i < CompraOCarrito.length();i++){
        CompraOCarrito[i] = tolower(CompraOCarrito[i]);
    }
    string ruta = "./baseDatos/registroDe" + CompraOCarrito + "/" + nombre + "_" + to_string(IDuser) + ".txt"; 
    ofstream archivo2(ruta, ios::app);
    if(!archivo2.is_open()){
        cerr<<"No se pudo abrir el archivo";
        exit(1);
    }
    int cantProductos = cantRegistros(ruta);
    // Registrando la compra
    archivo2<<cantProductos+1<<" "<<IDproducto<<" "<<unidades<<" "<<gasto<<" "<<endl;
    archivo2.close();
}

void mostrarCategorias(){
    ifstream archivo("./baseDatos/Categoria.txt");
    string texto;
    int i = 0;
    int posI, posF;
    string sub;
    while(getline(archivo,texto)){
        posI = texto.find("(");posI++;
        posF = texto.find(")",posI);posF--;
        sub = texto.substr(posI,posF-posI+1);
        cout<<"  "<<i+1<<". "<<sub<<endl;
        i++;
    } 
    archivo.close(); 
}

void mostrarSubCategoria(int categoria){
    ifstream archivo("./baseDatos/Categoria.txt");
    string texto;
    int posI,posF;
    string sub;
    int i = 1;
    int k = 0;
    while(getline(archivo,texto)){
        if(i == categoria){
            posI = texto.find(")");
            posI+=2;
            posF = texto.find(".",posI);posF--;
            sub = texto.substr(posI,posF-posI+1);
        }
        i++;
    }
    archivo.close();
    size_t pos = 0;
    int numero = 1;
    cout<<"\n";
    while ((pos = sub.find(",")) != string::npos) {
        string elemento = sub.substr(0, pos);
        cout <<"  "<< numero << ". " << elemento << endl;
        sub.erase(0, pos + 1);
        numero++;
    }

    // Imprimir el último elemento (si existe)
    if (!sub.empty()) {
        cout <<"  " << numero << ". " << sub << endl;
    }

}

int getIdTienda(string correo){
    ifstream archivo ("./baseDatostiendas/tiendas.txt");
    string texto, sub;
    int posI,posF;
    int contador = 1;
    while(getline(archivo,texto)){
        posI = texto. find("(");posI++;
        posF = texto.find(")",posI);posF--;
        sub = texto.substr(posI,posF-posI+1);
        if(sub == correo){
            break;
        }
        contador++;
    }
    return contador;
}