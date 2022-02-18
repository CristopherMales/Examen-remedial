#include "dialogo.h"
#include "ui_dialogo.h"

Dialogo::Dialogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogo)
{
    ui->setupUi(this);
}

Dialogo::~Dialogo()
{
    delete ui;
}

Tarea* Dialogo::obtener_valores()
{
    QString nombre = ui->lineNombre->text();
    QDate fecha = ui->lineFecha->date();
    QChar prioridad = ui->linePrioridad->text().at(0).toLower();
    QString tipo= ui->lineTipo->text();
    Tarea *d = new Tarea();
    if(nombre.length() == 0 || fecha.isNull()  || prioridad.isNull() || tipo.length() == 0 ){
        QMessageBox::warning(this,tr("Campos Requerido"),
                                     tr("Ingrese datos por favor"));
        return nullptr;
    }
    if(nombre.length()>=80){
        QMessageBox::warning(this,
                                     tr("Datos Incorrectos"),
                                     tr("Tamaño de Nombre maximo 80"));
        return nullptr;
    }
    if(prioridad != "a" && prioridad != "m" && prioridad != "b"){
        QMessageBox::warning(this,
                                     tr("Datos Incorrectos"),
                                     tr("No es una prioridad valida"));
        return nullptr;
    }
    d->setNombre(nombre);
    d->setFecha(fecha);
    d->setPrioridad(prioridad);
    d->setTipo(tipo);
    return d;
}
