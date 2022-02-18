#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    c = new controlador();
    c->cargarDatos();

    ui->setupUi(this);
    connect(ui->btnAgregar, SIGNAL(clicked()),this,SLOT(abrir_dialogo()));
    connect(ui->tabla,SIGNAL(cellPressed(int,int)),this,SLOT(on_finalizada_tabla(int,int)));
    QStringList cabecera = {tr("Numero"),tr("Nombre"),tr("Tipo"),tr("Fecha")};
    ui->tabla->setColumnCount(4);
    ui->tabla->setHorizontalHeaderLabels(cabecera);
    llenarTabla();
}
void Principal::abrir_dialogo(){
    Dialogo *dialg = new Dialogo(this);
       dialg->exec();

         Tarea* t1 =  dialg->obtener_valores();
         if (t1!=nullptr){
             ui->tabla->setRowCount(0);
             c->btnAgregar(t1);
             llenarTabla();
         }

}
void Principal::on_finalizada_tabla(int row, int column){
    QMessageBox::StandardButton respuesta = QMessageBox::question(
            this,
            tr("Cambio a finalizado"),
            tr("¿Quieres cambiar esta tarea a finalizado?") ,
            QMessageBox::Yes | QMessageBox::No
        );

        if(respuesta == QMessageBox::Yes){
            int index = ui->tabla->item(row,0)->text().toInt()-1;
            c->lista_tareas.at(index)->setFinalizada(true);
            ui->tabla->setRowCount(0);
            c->vaciarArchivo();
            c->escribirDatos();
            c->cargarDatos();
            llenarTabla();
        }
}

void Principal::llenarTabla(){

    foreach (Tarea *t1, c->lista_tareas) {
        if (t1->finalizada() == false){
        int fila = ui->tabla->rowCount();
            ui->tabla->insertRow(fila);
            ui->tabla->setItem(fila, 0, new QTableWidgetItem(QString::number(t1->numero())));
            ui->tabla->setItem(fila, 1, new QTableWidgetItem(t1->nombre()));
            ui->tabla->setItem(fila, 2, new QTableWidgetItem(t1->tipo()));
            ui->tabla->setItem(fila, 3, new QTableWidgetItem(t1->fecha().toString()));
            if (t1->prioridad() == 'a'){
                ui->tabla->item(fila,0)->setTextColor("red");
                ui->tabla->item(fila,1)->setTextColor("red");
                ui->tabla->item(fila,2)->setTextColor("red");
                ui->tabla->item(fila,3)->setTextColor("red");
            }else if (t1->prioridad() == 'm'){
                ui->tabla->item(fila,0)->setTextColor("orange");
                ui->tabla->item(fila,1)->setTextColor("orange");
                ui->tabla->item(fila,2)->setTextColor("orange");
                ui->tabla->item(fila,3)->setTextColor("orange");
            }else if (t1->prioridad() == 'b'){
                ui->tabla->item(fila,0)->setTextColor("yellow");
                ui->tabla->item(fila,1)->setTextColor("yellow");
                ui->tabla->item(fila,2)->setTextColor("yellow");
                ui->tabla->item(fila,3)->setTextColor("yellow");
            }
        }
       }

}


Principal::~Principal()
{
    delete ui;
}



void Principal::on_actionSalir_2_triggered()
{
    close();
}

