#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    c = new controlador();
    ui->setupUi(this);
    connect(ui->btnAgregar, SIGNAL(clicked()),this,SLOT(abrir_dialogo()));
    QStringList cabecera = {"Numero","Nombre","Tipo","Fecha"};
    ui->tabla->setColumnCount(4);
    ui->tabla->setHorizontalHeaderLabels(cabecera);
}
void Principal::abrir_dialogo(){
    Dialogo *dialg = new Dialogo(this);
       dialg->exec();

         Tarea* t1 =  dialg->obtener_valores();
         c->btnAgregar(t1);
         llenarTabla();

}

void Principal::llenarTabla(){

    foreach (Tarea *t1, c->lista_tareas) {
        int fila = ui->tabla->rowCount();
            ui->tabla->insertRow(fila);
            ui->tabla->setItem(fila, 0, new QTableWidgetItem(QString::number(1)));
            ui->tabla->setItem(fila, 1, new QTableWidgetItem(t1->nombre()));
            ui->tabla->setItem(fila, 2, new QTableWidgetItem(t1->tipo()));
            ui->tabla->setItem(fila, 3, new QTableWidgetItem(t1->fecha().toString()));
    }

}


Principal::~Principal()
{
    delete ui;
}

