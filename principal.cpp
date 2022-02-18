#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->btnAgregar, SIGNAL(clicked()),this,SLOT(abrir_dialogo()));
}
void abrir_dialogo(){
    dialogo *dialg = new  dialg(this);

       dialg->setVersion(VERSION);
       // Mostrar la ventana (diálogo) MODAL
       dialg->exec();
       // Obtener datos de la ventana
       qDebug() << dialg->obtener_valores();
}

Principal::~Principal()
{
    delete ui;
}

