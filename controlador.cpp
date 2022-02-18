#include "controlador.h"
#include "tarea.h"

controlador::controlador(QObject *parent) : QObject(parent)
{

}

bool controlador::btnAgregar(Tarea *t1){
    lista_tareas.append(t1);

    return false;
}
