#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonYOBO_clicked();

    void on_pushButtonBUSCAR_clicked();

    void on_pushButtonCARRITO_clicked();

    void on_pushButtonLOGIN_clicked();

    void on_pushButtonYOBO_2_clicked();

    void on_pushButtonYOBO_3_clicked();

    void on_pushButtonYOBO_4_clicked();

    void on_pushButtonINICIARSESION_clicked();

    void on_pushButtonCREARCUENTA_clicked();

    void on_pushButtonYOBO_5_clicked();

    void on_toolButtonCATEGORIAS_clicked();
    void categoria1Seleccionada();//ropa
    void categoria2Seleccionada();//tecnologia

    //prueba de las demas categorias
    void categoria3Seleccionada();//Electrodomesticos
    void categoria4Seleccionada();//Belleza y cuidados personal
    void categoria5Seleccionada();//Instrumentos musicales
    void categoria6Seleccionada();//Joyas



    //clase ropa derivada de categoria 1
    void categoria1Opcion1Seleccionada();
    void categoria1Opcion2Seleccionada();
    void categoria1Opcion3Seleccionada();
    void categoria1Opcion4Seleccionada();
    void categoria1Opcion5Seleccionada();
    void categoria1Opcion6Seleccionada();

    //categoria Tecnologia derivada de categoria 2
    void categoria2Opcion1Seleccionada();
    void categoria2Opcion2Seleccionada();
    void categoria2Opcion3Seleccionada();
    void categoria2Opcion4Seleccionada();
    void categoria2Opcion5Seleccionada();
    void categoria2Opcion6Seleccionada();


    //categoria Tecnologia derivada de categoria 3
    void categoria3Opcion1Seleccionada();
    void categoria3Opcion2Seleccionada();
    void categoria3Opcion3Seleccionada();
    void categoria3Opcion4Seleccionada();
    void categoria3Opcion5Seleccionada();
    void categoria3Opcion6Seleccionada();


    //categoria Tecnologia derivada de categoria 4
    void categoria4Opcion1Seleccionada();
    void categoria4Opcion2Seleccionada();
    void categoria4Opcion3Seleccionada();
    void categoria4Opcion4Seleccionada();



    //categoria Tecnologia derivada de categoria 5
    void categoria5Opcion1Seleccionada();
    void categoria5Opcion2Seleccionada();
    void categoria5Opcion3Seleccionada();
    void categoria5Opcion4Seleccionada();
    void categoria5Opcion5Seleccionada();



    //categoria Tecnologia derivada de categoria 6
    void categoria6Opcion1Seleccionada();
    void categoria6Opcion2Seleccionada();
    void categoria6Opcion3Seleccionada();


    //Creacion de boton de registrar (con menu)
    void on_toolButtonREGISTRAR_clicked();
    void registrar1Seleccionada();//INICIAR SESION
    void registrar2Seleccionada();//REGISTRARSE
    void registrar3Seleccionada();//VENDEDOR

    void on_duplicarBotonesButton_clicked();

    void on_pushButtonYOBO_6_clicked();

private:
    Ui::MainWindow *ui;
    QAction *accionCategoria1;
    QAction *accionCategoria2;

    //prueba de demas categorias
    QAction *accionCategoria3;
    QAction *accionCategoria4;
    QAction *accionCategoria5;
    QAction *accionCategoria6;

    //Creacion del boton Registrar
    QAction *accionRegistrar1;
    QAction *accionRegistrar2;
    QAction *accionRegistrar3;

    QMenu *menuCategoriasOriginal;
    void duplicarBotones();

};
#endif // MAINWINDOW_H
