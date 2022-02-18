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
    QChar prioridad = ui->linePrioridad->text().at(0);
    QString tipo= ui->lineTipo->text();
    Tarea *d = new Tarea();
    d->setNombre(nombre);
    d->setFecha(fecha);
    d->setPrioridad(prioridad);
    d->setTipo(tipo);
    return d;
}
