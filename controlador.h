#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "tarea.h"
class controlador
{
public:
     explicit controlador(QObject *parent = nullptr);
    //Tarea *tarea() const;

private:
    QList<Tarea*> lista_tareas;

};



#endif // CONTROLADOR_H
