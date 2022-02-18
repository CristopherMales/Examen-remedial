#include "controlador.h"
#include "tarea.h"

controlador::controlador(QObject *parent) : QObject(parent)
{

}

bool controlador::escribir(){
    QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";

    QFile archivo(nombre_archivo);
    QString line ="";
    foreach (Tarea *t1, lista_tareas) {
        fin = "False";
        if (t1->finalizada()){
            fin = "True";
        }
        line += (lista_tareas.length()+1) +","+t1->nombre()+","+t1->fecha().toString()+","+t1->prioridad()+","+t1->tipo()+","+fin;
    }
    archivo.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&archivo);
    out<<line<<endl;
    archivo.close();
}

bool controlador::btnAgregar(Tarea *t1){

    lista_tareas.append(t1);

    return false;
}



