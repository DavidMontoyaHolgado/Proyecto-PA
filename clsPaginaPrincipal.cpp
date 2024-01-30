# include <iostream>
#include <windows.h>
#include "./funciones/user.h"
#include "./LoginCuenta/login.h"
#include "./Buscador/buscador.h"
#include "./claseCompra/clsCompra.h"
#include "./claseCompra/descuentos.h"
#include "./claseCompra/formasPago.h"
#include "./claseCompra/MetodoPago.h"
#include "./claseTienda/clsProducto.h"
#include "./claseUsuario/clsUsuario.h"
#include "./Carrito/carrito.h"
using namespace std;

int main(){
    loginCuenta cuenta;
    int opcion;
    string nombre, apellido, correo, clave;
    int edad, identificacion;
    bool sesionIniciada = false;
	clsBuscador buscador;
    clsProducto producto;
	clsUsuario usuario;
    string busqueda;
    int eleccion, cantidad,eleccionCompra;
	clsMetodoPago metodoPago;
	string lugarEnvio;
	clsDescuentos 	descuentos;
	int estrellas;
	string opinion;	
	float precio;
	int idUsuario;

	int opcion2;
	//Valores para crear Producto
	string nombreProducto, descripcion, marca, modelo;
		do{
			    system("pause");
    			system("cls");
    	     cout << "Menu Principal" << endl;
    	     cout << "1. Registrarse" << endl;
    	     cout << "2. Iniciar Sesion" << endl;
    	     cout << "3. Buscar Producto" << endl;
    	     cout << "4. Ver Carrito" << endl;
    	     cout << "5. Salir" << endl;
			if (sesionIniciada && correo.find("@zofratacna") != string::npos) {
				cout << "6. Agregar Producto (Solo para zofratacna)" << endl;
			}
        cout << "Ingrese una opcion: ";
        cin >> opcion;
		if(cin.fail()){
			cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
			cin.clear();
			cin.ignore(1000,'\n');
			opcion = -1;
			Sleep(200);
			continue;
		}
		// cin.ignore();
        switch(opcion) {//CrearCuenta
            case 1:
				cin.ignore();
				cout << "Ingrese Nombre: ";
                getline(cin,nombre);
                cout << "Ingrese Apellido: ";
				getline(cin,apellido);
                cout << "Ingrese Correo: ";
                cin >> correo;
                cout << "Ingrese Clave: ";
                cin >> clave;
                cout << "Ingrese Edad: ";
                cin >> edad;
                cout << "Ingrese identificacion: ";
                cin >> identificacion;
                cuenta.crearCu(nombre, apellido, correo, clave, edad, identificacion);
				idUsuario = cantRegistros("./baseDatos/usuarios.txt");
				usuario.agregarId(to_string(idUsuario));
				sesionIniciada = true;
                break;
            case 2:{ //IniciarSesion
				cin.ignore();
				cout << "Ingrese Correo: ";
                cin >> correo;
                cout << "Ingrese Clave: ";
                cin >> clave;
                cuenta.iniciarSe(correo, clave);
				idUsuario = cantRegistros("./baseDatos/usuarios.txt");
				usuario.agregarId(to_string(idUsuario));
                sesionIniciada = true;
				break;
				}
				//CERRAR sesion
                // while (sesionIniciada) {
                //     cout << "4. Cerrar sesion" << endl;
                //     cout << "Ingrese una opcion: ";
                //     cin >> opcion;
                //     if (opcion == 4) {
                //         cuenta.cerrarSe();
                //         sesionIniciada = false;
                //     }
                // }
                // break;
            case 3: { // Buscar Producto
				cin.clear();
				cin.get();
                cout << "Ingrese el producto a buscar: ";
	 			getline(cin, busqueda);
				cin.ignore();
	 			int* resultados = buscador.buscarProducto(busqueda);
	 			if (resultados[0] != 0 && resultados[0] < 1000){
					
	 				cout << "Seleccione un producto para mas detalles: ";
	 				cin >> eleccion;
	 				if (eleccion > 0 && eleccion <= 5 && resultados[eleccion-1] != 0 ) {
	 					precio = producto.mostrarProducto(resultados[eleccion -1]);
	 					do {
	 						cout << "Desea comprar (1) o agregar al carrito (2) o salir (3): ";
	 						cin >> eleccionCompra;
							//Verificamos si pone una letra
							if(cin.fail()){
								cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
								cin.clear();
								cin.ignore(1000,'\n');
								opcion = -1;
								Sleep(200);
								continue;
							}
							if(eleccionCompra == 2 && eleccionCompra == 1 && sesionIniciada == false){
								cout<<"Necesita una cuenta para comprar/Guardar"<<endl;
								eleccionCompra = 3;
							}
	 						if (eleccionCompra == 1 && sesionIniciada) {
	 							// Logica para comprar el producto
	 							clsCompra compra2;
	 							cout << "Ingrese unidad(es) del producto que desea comprar: ";
	 							cin >> cantidad;
	 							float total1 = precio * cantidad;
								compra2.llenarDato();
	 							if (compra2.comprarProducto(total1)) {
	 								cout << "\nCompra realizada con exito.\n\n";
	 								//VALORANDO EL PRODUCTO
	 								int deseaValorar;
	 								cout << "¿Desea valorar el producto? 1: Si, 0: No: ";
	 								cin >> deseaValorar;
									if(cin.fail()){
										cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
										cin.clear();
										cin.ignore(1000,'\n');
										Sleep(200);
									}
	 								if (deseaValorar == 1) {
	 									cout << "Ingrese la cantidad de estrellas (1 a 5): ";
	 									cin >> estrellas;
											cout << "¿Desea agregar una opinion? 1: Si, 0: No, 3: Salir: ";
											cin >> deseaValorar;
											if (cin.fail() || (deseaValorar != 0 && deseaValorar != 1 && deseaValorar != 3)) {
												cout << "Opcion invalida. Debe ingresar una opcion valida\n" << endl;
												cin.clear();
												cin.ignore(1000, '\n');
												deseaValorar = -1;
												Sleep(200);
												continue;
											}
											if (deseaValorar == 1) {
												cout << "Ingrese su opinion: ";
												cin.ignore();
												getline(cin, opinion);
												usuario.valorarProducto(resultados[eleccion - 1], true, estrellas, opinion);
											} else if (deseaValorar == 0) {
												usuario.valorarProducto(resultados[eleccion - 1], true, estrellas);
											}
	 								}
	 								}
	 						} else if (eleccionCompra == 2 && sesionIniciada) {
	 							// Logica para agregar al carrito
								clsCarrito carrito(idUsuario);
	 							cout << "Ingrese la cantidad: ";
	 							cin >> cantidad;
	 							float total2 = precio * cantidad;
	 							carrito.anadirCarrito(resultados[eleccion-1], cantidad, total2);
	 							// Logica para agregar al carrito
	 							cout << cantidad << " unidad(es) del producto agregadas al carrito." << endl;
	 						} else if(eleccionCompra == 3){
								eleccionCompra = 2;
							}else {
	 							cout << "opcion no valida." << endl;
	 						}
	 					}while (eleccionCompra != 2 && eleccionCompra !=1);
	 				}else {
	 					cout << "Seleccion no valida." << endl;
	 				}
	 			}else {
	 					cout << "El producto no se ha encontrado." << endl;
	 				}
                break;
				
			}
            case 4:{  // Ver Carrito
                 if (sesionIniciada) {
                     do {
	 					cout << "\n-----------Carrito-----------" << endl;
						clsCarrito carrito(idUsuario);
	 					carrito.mostrarCarrito();
	 					cout << "1. Eliminar Producto del Carrito" << endl;
	 					cout << "2. Comprar Producto del Carrito" << endl;
	 					cout << "3. Salir" << endl;
	 					cout << "Ingrese una opcion: ";
	 					cin >> opcion2;
						if(cin.fail()){
							cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
							cin.clear();
							cin.ignore(1000,'\n');
									}
						clsCompra compra;
						
	 					switch(opcion2) {
	 						case 1: // Eliminar Producto
	 							int posP;
	 							cout << "Ingrese la posicion del producto a eliminar: ";
	 							cin >> posP;
	 							carrito.quitarCarrito(posP);
	 							cout << "Producto eliminado del carrito." << endl;
	 							break;
	 						case 2: // Comprar Producto
	 							cout << "Ingrese la posicion del producto a comprar: ";
	 							cin >> posP;
								compra.llenarDato();
	 							precio = carrito.calculaProducto(posP);
	 							if (compra.comprarProducto(precio)) {
	 								cout << "Producto comprado exitosamente." << endl;
									carrito.quitarCarrito(posP);
	 									// VALORANDO EL PRODUCTO
	 									bool deseaValorar;
										bool deseaOpinar;
	 									cout << "¿Desea valorar el producto? 1: Si, 0: No: ";
	 									cin >> deseaValorar;
										if(cin.fail()){
											cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
											cin.clear();
											cin.ignore(1000,'\n');
											opcion = -1;
											continue;
										}
	 									if (deseaValorar) {
	 										cout << "Ingrese la cantidad de estrellas (1 a 5): ";
	 										cin >> estrellas;
	 										cout << "Desea agregar una opinion? 1: Si, 0: No: ";
	 										cin >> deseaOpinar;
	 										if (deseaOpinar) {
	 											cout << "Ingrese su opinion: ";
	 											cin.ignore();
	 											getline(cin, opinion);
	 											usuario.valorarProducto(carrito.getIdProducto(posP), true, estrellas, opinion);
	 										} else {
	 											usuario.valorarProducto(carrito.getIdProducto(posP), true, estrellas);
	 										}
	 									}
	 							} else {
	 								cout << "No se pudo completar la compra." << endl;
	 							}
	 							break;
	 						case 3:
	 							cout << "Saliendo del menÃº del carrito." << endl;
	 							opcion2 = 4;
								break;
	 						default:
	 							cout << "Opcion no valida." << endl;
	 					}
	 				} while (opcion2 != 4);
                 } else {
                     cout << "Debe iniciar sesion para ver el carrito." << endl;
                 }
                 break;
			}
             case 5:{  // Salir
                 cout << "Gracias por visitar nuestra pagina." << endl;
                 break;}
             case 6:{  // Agregar Producto (Solo para zofratacna)
                 if (sesionIniciada && correo.find("@zofratacna") != string::npos) {
                    int opcion, idCategoria,idSubCategoria;
	 				string nombreProducto, descripcion, marca, modelo;
	 				precio;
	 				int idTienda = getIdTienda(correo);  // Asumiendo un idTienda predeterminado o obtenido de otra manera
	 				clsProducto producto;
	 				cout << "\nMenu para anadir Producto" << endl;
					mostrarCategorias();
	 				cout << "Ingrese la categoria del producto (1-6): ";
	 				cin >> idCategoria;
					cout << "\nIngrese la sub categoria del producto: ";
					mostrarSubCategoria(idCategoria);
					cin>>idSubCategoria;
	 				cin.ignore();  // Para limpiar el buffer despues de ingresar un numero
	 	 			// Datos comunes para todos los productos
	 				cout << "Ingrese nombre del producto: ";
	 				getline(cin, nombreProducto);
	 				cout << "Ingrese precio: ";
	 				cin >> precio;
					cin.ignore();
	 				cout << "Ingrese descripcion: ";
	 				getline(cin, descripcion);
	 				cout << "Ingrese marca: ";
	 				getline(cin, marca);
	 				cout << "Ingrese modelo: ";
	 				getline(cin, modelo);
					//Separado por categoria
	 				 if (idCategoria == 1) {
	 				 	// Categoria Ropa
	 				 	string colores[7];
						int n = 0;int m = 0;
						char veri = 's';
						cout<<"Ingrese los/el color(es) de su producto: \n";
						while(n < 7 && (veri  == 'S' || veri == 's') ){
							cout<<"Color "<<n+1<<": ";
							cin>>colores[n];
							n++;
							cout<<"¿Desea agregar otro color?(S/N)";cin>>veri;
							if(cin.fail()){
							cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
							cin.clear();
							cin.ignore(1000,'\n');
							n--;
							continue;
							}
						}
						veri = 's';
	 				 	string tallas[5];
						cout<<"\nIngrese la(s) talla(s) de la ropa: \n";
						while(m < 5 && (veri  == 'S' || veri == 's')){
							cout<<"Talla: "<<m+1<<": ";
							cin>>tallas[m];
							m++;
							cout<<"¿Desea agregar otra talla?(S/N)";
							cin>>veri;
							if(cin.fail()){
							cout<<"Opcion invalido. Debe ingresar una opcion valida\n"<<endl;
							cin.clear();
							cin.ignore(1000,'\n');
							m--;
							continue;
							}

						}
	 				 	int** stock = new int*[n];

	 				 	for (int s = 0; s < n; ++s) {
	 				 		stock[s] = new int[m];
	 				 	}
						    for (int t = 0; t < n; ++t) {
								for (int y = 0; y < m; ++y) {
									cout << "Ingrese la cantidad de productos para el color " << t + 1 << " y talla " << y + 1 << ": ";
									cin >> stock[t][y];
								}
							}
							cout<<"Error aqui";
							clsProducto producto1(idTienda, nombreProducto, precio, descripcion, marca, modelo, idCategoria,idSubCategoria, colores, stock,tallas);
							// Logica para aÃ±adir el producto
						} else {}
				}
			 }
	 	// 				// Otras Categoria
	 	// 				// AÃ±adir Logica para obtener colores y stock
	 	// 				string colores[] = {/* colores disponibles */};
	 	// 				int stock[] = {/* stock por color */};

	 	// 				clsProducto producto2(idTienda, nombreProducto, precio, descripcion, marca, modelo, idCategoria,idSubCategoria, colores, stock);
	 	// 				// Logica para aÃ±adir el producto
    	// 			 }
        //          } else {
        //              cout << "Opcion no disponible." << endl;
        //          }
        //          break;
        //      default:
        //          cout << "Opcion no valida." << endl;
					// break;
        //  }
     	} 
		}while (opcion != 6);
	return 0;
}
