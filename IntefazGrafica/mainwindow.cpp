#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QGridLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    cargarUsuarios();
    loadProducts();
    menuCategoriasOriginal = ui->toolButtonCATEGORIAS->menu();


    connect(ui->pushButtonINICIARSESION_LOG, &QPushButton::clicked, this, &MainWindow::on_pushButtonINICIARSESION_clicked);
    connect(ui->pushButtonCREARCUENTA_LOG, &QPushButton::clicked, this, &MainWindow::on_pushButtonCREARCUENTA_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonYOBO_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonYOBO_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButtonCATEGORIAS_clicked()
{
    // Crea un QMenu
    QMenu *menuCategorias = new QMenu(this);

    // Crea las acciones para CATEGORIAS y agrégalas al menú
    accionCategoria1 = menuCategorias->addAction("Ropa");
    accionCategoria2 = menuCategorias->addAction("Tecnología");

    //Prueba de demas categorias
    accionCategoria3 = menuCategorias->addAction("Electrodomesticos");
    accionCategoria4 = menuCategorias->addAction("Belleza y cuidados personales");
    accionCategoria5 = menuCategorias->addAction("Instrumentos personales");
    accionCategoria6 = menuCategorias->addAction("Joyas");


    // Crea menús desplegables adicionales para las categorías
    QMenu *menuCategoria1 = new QMenu("Opciones Categoria 1", this);
    QMenu *menuCategoria2 = new QMenu("Opciones Categoria 2", this);

    //Prueba de demas categorias
    QMenu *menuCategoria3 = new QMenu("Opciones Categoria 3", this);
    QMenu *menuCategoria4 = new QMenu("Opciones Categoria 4", this);
    QMenu *menuCategoria5 = new QMenu("Opciones Categoria 5", this);
    QMenu *menuCategoria6 = new QMenu("Opciones Categoria 6", this);

    // Agrega acciones al menú desplegable de Categoria 1
    QAction *accionCat1Opcion1 = menuCategoria1->addAction("Pantalón");
    QAction *accionCat1Opcion2 = menuCategoria1->addAction("Camisa");
    //Agregadas prueba de ropa
    QAction *accionCat1Opcion3 = menuCategoria1->addAction("short");
    QAction *accionCat1Opcion4 = menuCategoria1->addAction("Polo");
    QAction *accionCat1Opcion5 = menuCategoria1->addAction("Polera");
    QAction *accionCat1Opcion6 = menuCategoria1->addAction("Chompa");

    // Agrega acciones al menú desplegable de Categoria 2
    QAction *accionCat2Opcion1 = menuCategoria2->addAction("Laptop");
    QAction *accionCat2Opcion2 = menuCategoria2->addAction("Celular");
    //Agregadas prueba de tecnologia
    QAction *accionCat2Opcion3 = menuCategoria2->addAction("Pantallas");
    QAction *accionCat2Opcion4 = menuCategoria2->addAction("Accesorios");
    QAction *accionCat2Opcion5 = menuCategoria2->addAction("Consolas");
    QAction *accionCat2Opcion6 = menuCategoria2->addAction("Videojuegos");


    //Prueba de las demas categorias
    // Agrega acciones al menú desplegable de Categoria 3
    QAction *accionCat3Opcion1 = menuCategoria3->addAction("Refrigeradora");
    QAction *accionCat3Opcion2 = menuCategoria3->addAction("Licuadora");
    //Agregadas prueba de ropa
    QAction *accionCat3Opcion3 = menuCategoria3->addAction("Cocina Electrica");
    QAction *accionCat3Opcion4 = menuCategoria3->addAction("Horno");
    QAction *accionCat3Opcion5 = menuCategoria3->addAction("Olla arrocera");
    QAction *accionCat3Opcion6 = menuCategoria3->addAction("Cafetera");

    // Agrega acciones al menú desplegable de Categoria 4
    QAction *accionCat4Opcion1 = menuCategoria4->addAction("Higiene personal");
    QAction *accionCat4Opcion2 = menuCategoria4->addAction("Maquillaje");
    //Agregadas prueba de ropa
    QAction *accionCat4Opcion3 = menuCategoria4->addAction("Perfumeria");
    QAction *accionCat4Opcion4 = menuCategoria4->addAction("Accesorios");


    // Agrega acciones al menú desplegable de Categoria 5
    QAction *accionCat5Opcion1 = menuCategoria5->addAction("Microfonos");
    QAction *accionCat5Opcion2 = menuCategoria5->addAction("De cuerda");
    //Agregadas prueba de ropa
    QAction *accionCat5Opcion3 = menuCategoria5->addAction("De viento");
    QAction *accionCat5Opcion4 = menuCategoria5->addAction("De percusión");
    QAction *accionCat5Opcion5 = menuCategoria5->addAction("Accesorios");


    // Agrega acciones al menú desplegable de Categoria 6
    QAction *accionCat6Opcion1 = menuCategoria6->addAction("Relojes");
    QAction *accionCat6Opcion2 = menuCategoria6->addAction("Joyas");
    //Agregadas prueba de ropa
    QAction *accionCat6Opcion3 = menuCategoria6->addAction("Otros");

    // Conecta las acciones a los slots correspondientes
    connect(accionCategoria1, &QAction::triggered, this, &MainWindow::categoria1Seleccionada);
    connect(accionCategoria2, &QAction::triggered, this, &MainWindow::categoria2Seleccionada);

    //PRueba de las demas categorias
    connect(accionCategoria3, &QAction::triggered, this, &MainWindow::categoria3Seleccionada);
    connect(accionCategoria4, &QAction::triggered, this, &MainWindow::categoria4Seleccionada);
    connect(accionCategoria5, &QAction::triggered, this, &MainWindow::categoria5Seleccionada);
    connect(accionCategoria6, &QAction::triggered, this, &MainWindow::categoria6Seleccionada);


    //conexiones independientes
    connect(accionCat1Opcion1, &QAction::triggered, this, &MainWindow::categoria1Opcion1Seleccionada);
    connect(accionCat1Opcion2, &QAction::triggered, this, &MainWindow::categoria1Opcion2Seleccionada);
    //Agregadas prueba de ropa
    connect(accionCat1Opcion3, &QAction::triggered, this, &MainWindow::categoria1Opcion3Seleccionada);
    connect(accionCat1Opcion4, &QAction::triggered, this, &MainWindow::categoria1Opcion4Seleccionada);
    connect(accionCat1Opcion5, &QAction::triggered, this, &MainWindow::categoria1Opcion5Seleccionada);
    connect(accionCat1Opcion6, &QAction::triggered, this, &MainWindow::categoria1Opcion6Seleccionada);


    connect(accionCat2Opcion1, &QAction::triggered, this, &MainWindow::categoria2Opcion1Seleccionada);
    connect(accionCat2Opcion2, &QAction::triggered, this, &MainWindow::categoria2Opcion2Seleccionada);
    //Agregadas prueba tecnologia
    connect(accionCat2Opcion3, &QAction::triggered, this, &MainWindow::categoria2Opcion3Seleccionada);
    connect(accionCat2Opcion4, &QAction::triggered, this, &MainWindow::categoria2Opcion4Seleccionada);
    connect(accionCat2Opcion5, &QAction::triggered, this, &MainWindow::categoria2Opcion5Seleccionada);
    connect(accionCat2Opcion6, &QAction::triggered, this, &MainWindow::categoria2Opcion6Seleccionada);


    //prueba de las demas categorias
    connect(accionCat3Opcion1, &QAction::triggered, this, &MainWindow::categoria3Opcion1Seleccionada);
    connect(accionCat3Opcion2, &QAction::triggered, this, &MainWindow::categoria3Opcion2Seleccionada);
    connect(accionCat3Opcion3, &QAction::triggered, this, &MainWindow::categoria3Opcion3Seleccionada);
    connect(accionCat3Opcion4, &QAction::triggered, this, &MainWindow::categoria3Opcion4Seleccionada);
    connect(accionCat3Opcion5, &QAction::triggered, this, &MainWindow::categoria3Opcion5Seleccionada);
    connect(accionCat3Opcion6, &QAction::triggered, this, &MainWindow::categoria3Opcion6Seleccionada);

    connect(accionCat4Opcion1, &QAction::triggered, this, &MainWindow::categoria4Opcion1Seleccionada);
    connect(accionCat4Opcion2, &QAction::triggered, this, &MainWindow::categoria4Opcion2Seleccionada);
    connect(accionCat4Opcion3, &QAction::triggered, this, &MainWindow::categoria4Opcion3Seleccionada);
    connect(accionCat4Opcion4, &QAction::triggered, this, &MainWindow::categoria4Opcion4Seleccionada);


    connect(accionCat5Opcion1, &QAction::triggered, this, &MainWindow::categoria5Opcion1Seleccionada);
    connect(accionCat5Opcion2, &QAction::triggered, this, &MainWindow::categoria5Opcion2Seleccionada);
    connect(accionCat5Opcion3, &QAction::triggered, this, &MainWindow::categoria5Opcion3Seleccionada);
    connect(accionCat5Opcion4, &QAction::triggered, this, &MainWindow::categoria5Opcion4Seleccionada);
    connect(accionCat5Opcion5, &QAction::triggered, this, &MainWindow::categoria5Opcion5Seleccionada);


    connect(accionCat6Opcion1, &QAction::triggered, this, &MainWindow::categoria6Opcion1Seleccionada);
    connect(accionCat6Opcion2, &QAction::triggered, this, &MainWindow::categoria6Opcion2Seleccionada);
    connect(accionCat6Opcion3, &QAction::triggered, this, &MainWindow::categoria6Opcion3Seleccionada);





    // Configura los menús desplegables para las categorías
    accionCategoria1->setMenu(menuCategoria1);
    accionCategoria2->setMenu(menuCategoria2);

    //prueba delas demas clases
    accionCategoria3->setMenu(menuCategoria3);
    accionCategoria4->setMenu(menuCategoria4);
    accionCategoria5->setMenu(menuCategoria5);
    accionCategoria6->setMenu(menuCategoria6);


    // Configura el QToolButton para mostrar el menú principal de CATEGORIAS
    ui->toolButtonCATEGORIAS->setMenu(menuCategorias);
    ui->toolButtonCATEGORIAS->setPopupMode(QToolButton::InstantPopup);


    // Agrega acciones al menú
    //QAction *accionCategoria1 = menuCategorias->addAction("Categoria 1");
    //QAction *accionCategoria2 = menuCategorias->addAction("Categoria 2");

    // Agrega más acciones según sea necesario

    // Conecta las acciones a slots si es necesario
    connect(accionCategoria1, &QAction::triggered, this, &MainWindow::categoria1Seleccionada);
    connect(accionCategoria2, &QAction::triggered, this, &MainWindow::categoria2Seleccionada);

    //prueba de las demas
    connect(accionCategoria3, &QAction::triggered, this, &MainWindow::categoria3Seleccionada);
    connect(accionCategoria4, &QAction::triggered, this, &MainWindow::categoria4Seleccionada);
    connect(accionCategoria5, &QAction::triggered, this, &MainWindow::categoria5Seleccionada);
    connect(accionCategoria6, &QAction::triggered, this, &MainWindow::categoria6Seleccionada);




    // Conecta más acciones según sea necesario

    // Muestra el menú en la posición del botón
    menuCategorias->exec(ui->toolButtonCATEGORIAS->mapToGlobal(QPoint(0, ui->toolButtonCATEGORIAS->height())));

}





void MainWindow::categoria1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 1
}

void MainWindow::categoria2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 2
}

//prueba de las demas

void MainWindow::categoria3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 1
}

void MainWindow::categoria4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 2
}

void MainWindow::categoria5Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 1
}

void MainWindow::categoria6Seleccionada()
{
    // Código a ejecutar cuando se selecciona la categoría 2
}


void MainWindow::on_pushButtonBUSCAR_clicked()
{

}


void MainWindow::categoria1Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 1
}

void MainWindow::categoria1Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 1
}

//prueba de ropa
void MainWindow::categoria1Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 1
}

void MainWindow::categoria1Opcion4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 4 de Categoria 1
}
void MainWindow::categoria1Opcion5Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 5 de Categoria 1
}

void MainWindow::categoria1Opcion6Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 6 de Categoria 1
}




void MainWindow::categoria2Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 2
}

void MainWindow::categoria2Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 2
}

//prueba tecnologia
void MainWindow::categoria2Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 2
}

void MainWindow::categoria2Opcion4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 4 de Categoria 2
}
void MainWindow::categoria2Opcion5Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 5 de Categoria 2
}

void MainWindow::categoria2Opcion6Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 6 de Categoria 2
}


//Prueba de las demas categorias
//Electrodomesticos

void MainWindow::categoria3Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 3
}

void MainWindow::categoria3Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 3
}

void MainWindow::categoria3Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 3
}

void MainWindow::categoria3Opcion4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 4 de Categoria 3
}
void MainWindow::categoria3Opcion5Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 5 de Categoria 3
}

void MainWindow::categoria3Opcion6Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 6 de Categoria 3
}

//Belleza
void MainWindow::categoria4Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 4
}

void MainWindow::categoria4Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 4
}

//prueba tecnologia
void MainWindow::categoria4Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 4
}

void MainWindow::categoria4Opcion4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 4 de Categoria 4
}


//Instrumentos musicales
void MainWindow::categoria5Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 5
}

void MainWindow::categoria5Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 5
}

void MainWindow::categoria5Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 5
}

void MainWindow::categoria5Opcion4Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 4 de Categoria 5
}
void MainWindow::categoria5Opcion5Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 5 de Categoria 5
}



//Joyas
void MainWindow::categoria6Opcion1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 1 de Categoria 6
}

void MainWindow::categoria6Opcion2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 2 de Categoria 6
}

void MainWindow::categoria6Opcion3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la Opción 3 de Categoria 6
}



void MainWindow::on_toolButtonREGISTRAR_clicked()
{

    // Crea un QMenu
    QMenu *menuRegistrar = new QMenu(this);

    // Crea las acciones para CATEGORIAS y agrégalas al menú
    accionRegistrar1 = menuRegistrar->addAction("Iniciar Sesion");
    accionRegistrar2 = menuRegistrar->addAction("Registrarse");
    accionRegistrar3 = menuRegistrar->addAction("Iniciar sesión como Vendedor");

    // Configura el QToolButton para mostrar el menú principal de REGISTRAR
    ui->toolButtonREGISTRAR->setMenu(menuRegistrar);
    ui->toolButtonREGISTRAR->setPopupMode(QToolButton::InstantPopup);

    // Conecta las acciones a slots si es necesario
    connect(accionRegistrar1, &QAction::triggered, this, &MainWindow::registrar1Seleccionada);
    connect(accionRegistrar2, &QAction::triggered, this, &MainWindow::registrar2Seleccionada);
    connect(accionRegistrar3, &QAction::triggered, this, &MainWindow::registrar3Seleccionada);
    menuRegistrar->exec(ui->toolButtonREGISTRAR->mapToGlobal(QPoint(0, ui->toolButtonREGISTRAR->height())));
}

void MainWindow::registrar1Seleccionada()
{
    // Código a ejecutar cuando se selecciona la registrar iniciar sesion

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::registrar2Seleccionada()
{
    // Código a ejecutar cuando se selecciona la registrar
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::registrar3Seleccionada()
{
    // Código a ejecutar cuando se selecciona la registrar como vendedor
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::duplicarBotones()
{
    // Duplica el botón CATEGORIAS
    QToolButton *toolButtonCATEGORIAS_Duplicado = new QToolButton(this);
    toolButtonCATEGORIAS_Duplicado->setMenu(menuCategoriasOriginal);
    toolButtonCATEGORIAS_Duplicado->setPopupMode(QToolButton::InstantPopup);
    toolButtonCATEGORIAS_Duplicado->setText("Boton Duplicado"); // Puedes ajustar el texto según sea necesario
    ui->verticalLayout->addWidget(toolButtonCATEGORIAS_Duplicado);

    // Ajusta la posición del menú desplegable
    QPoint globalPosCATEGORIAS = ui->toolButtonCATEGORIAS->mapToGlobal(QPoint(0, ui->toolButtonCATEGORIAS->height()));
    menuCategoriasOriginal->exec(globalPosCATEGORIAS);
}

void MainWindow::on_duplicarBotonesButton_clicked()
{
    duplicarBotones();
}


void MainWindow::cargarUsuarios() {
    QFile file("usuarios.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 2) {
                usuariosRegistrados.insert(parts[0], parts[1]);
            }
        }
    }
}
void MainWindow::registrarUsuario(const QString &usuario, const QString &contrasena) {
    // Implementa la lógica de registro aquí
    guardarUsuario(usuario, contrasena);
}

void MainWindow::guardarUsuario(const QString &usuario, const QString &contrasena) {
    usuariosRegistrados.insert(usuario, contrasena);
    QFile file("usuarios.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << usuario << "," << contrasena << "\n";
    }
}

bool MainWindow::verificarUsuario(const QString &usuario, const QString &contrasena) {
    return usuariosRegistrados.contains(usuario) && usuariosRegistrados[usuario] == contrasena;
}

void MainWindow::on_pushButtonINICIARSESION_clicked() {
    QString usuario = ui->lineEditRECIBIRCORREO->text();
    QString contrasena = ui->lineEditRECIBIRCONTRA->text();
    if (verificarUsuario(usuario, contrasena)) {
        // Redirige al menú principal
        ui->stackedWidget->setCurrentIndex(0); // Asumiendo que el índice 0 es tu menú principal
    } else {
        QMessageBox::warning(this, "Error de inicio de sesión", "Contraseña incorrecta, vuelve a intentar.");
    }
}

void MainWindow::on_pushButtonCREARCUENTA_clicked() {
    QString usuario = ui->lineEditRECIBIRCORREO_USER->text();
    QString contrasena = ui->lineEditRECIBIRCONTRA_USER->text();
    guardarUsuario(usuario, contrasena);
    // Puede agregar una confirmación de que la cuenta fue creada
}


void MainWindow::loadProducts() {
    QFile file(":/new/prefix1/productos.txt"); // Asegúrate de que la ruta sea correcta

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList productDetails;
        int lastIndex = 0;
        bool insideParenthesis = false;

        // Dividir la línea en partes, manejando los paréntesis
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '(') insideParenthesis = true;
            else if (line[i] == ')') insideParenthesis = false;
            else if (line[i] == ' ' && !insideParenthesis) {
                productDetails.append(line.mid(lastIndex, i - lastIndex).trimmed());
                lastIndex = i + 1;
            }
        }
        productDetails.append(line.mid(lastIndex).trimmed()); // Añade la última parte

        if (productDetails.size() >= 6) {
            QString productName = productDetails[1].mid(1, productDetails[1].length() - 2);
            QString productDescription = productDetails[0];
            QString imagePath = productDetails[5];

            QString productPrice = productDetails[2];
            // Esta línea debe ir después de haber declarado y asignado valores a productName e imagePath
            productImageMap[productName] = imagePath;

            QLabel *labelName = new QLabel(productName);
            QLabel *labelDescription = new QLabel(productDescription);
            QLabel *labelImage = new QLabel();
            QPixmap pix(imagePath);
            labelImage->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

            QPushButton *buttonAddToCart = new QPushButton("Ver Producto");
            QSpinBox *spinBoxCantidad = new QSpinBox();
            spinBoxCantidad->setRange(1, 99); // Establece el rango de la cantidad
            spinBoxCantidad->setValue(1); // Valor inicial del spinBox

            // Guardar la asociación en el mapa
            buttonToSpinBoxMap[buttonAddToCart] = spinBoxCantidad;
            QLabel *labelPrice = new QLabel("Precio unitario: " + productPrice);

            productPriceMap[productName] = productPrice.toInt();

            // Almacenar el nombre del producto en el botón para su uso posterior
            buttonAddToCart->setProperty("productID", productDetails[0]);

            // Conectar el botón a su slot
            connect(buttonAddToCart, &QPushButton::clicked, this, &MainWindow::on_pushButtonAgregarCarrito_clicked);

            QGridLayout *layout = qobject_cast<QGridLayout*>(ui->gridLayoutListaProductos);
            if (layout) {
                layout->addWidget(labelName, row, 0);
                layout->addWidget(labelDescription, row, 1);
                layout->addWidget(labelImage, row, 2);
                //layout->addWidget(spinBoxCantidad, row, 3); // Añadir el QSpinBox al layout
                layout->addWidget(buttonAddToCart, row, 3);
                //layout->addWidget(labelPrice, row, 5);                // Asegúrate de que la columna sea la correcta
            }
            row++;
        }
    }
    file.close();
}

QString MainWindow::buscarInformacionProducto(const QString &productID) {
    QStringList files = {
        //":/new/prefix1/productos.txt",
        ":/new/prefix1/BellezayCuidados.txt",
        ":/new/prefix1/InstrumentosMusicales.txt",
        ":/new/prefix1/inventarioGlobal.txt",
        ":/new/prefix1/Joyas.txt",

        ":/new/prefix1/Ropa.txt"
        ":/new/prefix1/Tecnologia.txt",

    };

    QString detallesProducto;
    for (const QString &fileName : files) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            continue;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            // Extraer el ID del producto al principio de cada línea, asumiendo que el ID es seguido por un espacio
            QString currentID = line.section(' ',1,1);
            if (currentID == productID) {
                detallesProducto = line; // Aquí tienes toda la línea con la información del producto
                break;
            }
        }
        file.close();

        if (!detallesProducto.isEmpty())
            break;
    }

    return detallesProducto;
}


void MainWindow::cargarInformacionProducto(const QString &productDetails) {
    QStringList details = productDetails.split(QRegularExpression("\\s+|(?<=\\))|(?=\\()"));

    if (details.size() < 12) return;

    QString nombreProducto = details[3];  // Ajusta los índices según sea necesario
    QString descripcion = details[11];
    QString precio = details[6];
    QString imagenPath = ":/imagenes";

    // Actualizar interfaz de usuario
    ui->labelNombreProducto_2->setText(nombreProducto);
    ui->labelDescripcionPROD->setText(descripcion);
    ui->labelPrice->setText("Precio: " + precio);

    QPixmap pix(imagenPath);
    if (!pix.isNull()) {
        ui->labelIMGPRODC->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } // Asumiendo una ruta de imagen, ajustar según sea necesario

    // Actualizar la interfaz de usuario


    // Manejar las tallas y el stock si están presentes (en el quinto elemento, por ejemplo)
    /*if (details.size() > 8) {
        QString tallaStock = details.at(9);
        tallaStock = tallaStock.mid(1, tallaStock.length() - 2); // Remueve los paréntesis
        QStringList tallas = tallaStock.split(',');
        // Aquí puedes procesar las tallas y el stock según sea necesario
        // Por ejemplo, mostrarlas en la interfaz o realizar alguna otra operación
    }*/
}

void MainWindow::on_pushButtonAgregarCarrito_clicked() {

    QPushButton *boton = qobject_cast<QPushButton*>(sender());
    if (boton) {
        QVariant productIDVariant = boton->property("productID");
        if (productIDVariant.isValid() && !productIDVariant.toString().isEmpty()) {
            QString productID = productIDVariant.toString();
            QString informacionProducto = buscarInformacionProducto(productID);
            if (!informacionProducto.isEmpty()) {
                cargarInformacionProducto(informacionProducto);
            } else {
                // Manejar el caso en que no se encontró el producto
                qDebug() << "Producto no encontrado con ID:" << productID;
            }
        } else {
            qDebug() << "El botón no tiene un 'productID' válido asociado.";
        }
    }
    ui->stackedWidget->setCurrentIndex(4);
}