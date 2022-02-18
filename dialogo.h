#ifndef DIALOGO_H
#define DIALOGO_H

#include <QDialog>
#include "tarea.h"
#include "controlador.h"

namespace Ui {
class Dialogo;
}

class Dialogo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogo(QWidget *parent = nullptr);
    ~Dialogo();
    Tarea obtener_valores();

private:
    Ui::Dialogo *ui;
};

#endif // DIALOGO_H
