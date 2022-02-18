#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <QObject>
#include "tarea.h"


class controlador : public QObject
{
public:
     explicit controlador(QObject *parent = nullptr);
    //Tarea *tarea() const;
    bool btnAgregar(Tarea *t1);

private:
    QList<Tarea*> lista_tareas;

};



#endif // CONTROLADOR_H
