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

Tarea Dialogo::obtener_valores():
{
    Tarea *d = new Tarea();
    d->setNombre(ui->lineNombre);
    d->setFecha(ui->lineFecha);
    d->setPrioridad(ui->linePrioridad);
    d->setTipo(ui->lineTipo);
    return d;
}
