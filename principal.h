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

private slots:
    void abrir_dialogo();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
