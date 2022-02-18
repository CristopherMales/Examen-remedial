#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDebug>
#include "dialogo.h"
#include "tarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    controlador *c;

private slots:
    void abrir_dialogo();
    void on_finalizada_tabla(int row,int column);

private:
    Ui::Principal *ui;
    void llenarTabla();
};
#endif // PRINCIPAL_H
