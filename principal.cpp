#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->btnAgregar, SIGNAL(clicked()),this,SLOT(abrir_dialogo()));
    QStringList cabecera = {"Numero","Nombre","Tipo","Fecha"};
    ui->tabla->setColumnCount(4);
    ui->tabla->setHorizontalHeaderLabels(cabecera);
}
void Principal::abrir_dialogo(){
    Dialogo *dialg = new Dialogo(this);
       dialg->exec();
}

Principal::~Principal()
{
    delete ui;
}

