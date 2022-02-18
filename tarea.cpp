#include "tarea.h"

int Tarea::numero(){
 return dato_numero;
}
void Tarea::setNumero(int numero){
 dato_numero = numero;
}

QString Tarea::nombre(){
 return dato_nombre;
}
void Tarea::setNombre(QString nombre){
 dato_nombre= nombre;
}

QDate Tarea::fecha(){
    return dato_fecha;
}

void Tarea::setFecha(QDate fecha){
    dato_fecha = fecha;
}

QChar Tarea::prioridad(){
    return dato_prioridad;
}

void Tarea::setPrioridad(QChar prioridad){
    dato_prioridad= prioridad;
}

QString Tarea::tipo(){
    return dato_tipo;
}

void Tarea::setTipo(QString tipo){
    dato_tipo= tipo;
}

bool Tarea::finalizada(){
    return dato_finalizada;
}

void Tarea::setFinalizada(bool finalizada){
    dato_finalizada = finalizada;
}

Tarea::Tarea(QObject *parent) : QObject(parent)
{
    dato_numero = -1;
    dato_nombre = "";
    dato_fecha = QDate::currentDate();
    dato_prioridad = '';
    dato_tipo = "";
    dato_finalizada = false;
}

Tarea::Tarea(int numero, QString nombre, QDate fecha, QChar prioridad, QString tipo, bool finalizada)
{
    dato_numero = numero;
    dato_nombre = nombre;
    dato_fecha = fecha;
    dato_prioridad = prioridad;
    dato_tipo = tipo;
    dato_finalizada = finalizada;
}
