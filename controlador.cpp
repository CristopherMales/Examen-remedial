#include "controlador.h"
#include "tarea.h"

controlador::controlador(QObject *parent) : QObject(parent)
{

}

bool controlador::cargarDatos(){
    QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";
     lista_tareas.clear();
    QFile archivo(nombre_archivo);

    if(archivo.open(QFile::ReadOnly | QIODevice::Text)){
        QTextStream in(&archivo);
        while(!in.atEnd()){
            QStringList line= in.readLine().split(",");

                lista_tareas.append(new Tarea(line.at(0).toInt(),(QString)line.at(1),QDate::fromString(line.at(2)),(QChar)line.at(3).at(0),(QString)line.at(4),QVariant(line.at(5)).toBool()));

        }
         archivo.close();
         return true;
    }
    archivo.close();
    return false;
}


bool controlador::escribirDatos(){
    QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";

    QFile archivo(nombre_archivo);

    archivo.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&archivo);
    foreach (Tarea *t1, lista_tareas) {
        QString line = QString::number(t1->numero())+","+t1->nombre()+","+t1->fecha().toString()+","+t1->prioridad()+","+t1->tipo()+","+QVariant(t1->finalizada()).toString();
        out<<line<<endl;
    }



    archivo.close();
    return true;
}

bool controlador::vaciarArchivo(){
    QString nombre_archivo = QDir::home().absolutePath()+"/registro_datos.txt";

    QFile archivo(nombre_archivo);
    if(archivo.exists())
        QFile::remove(nombre_archivo);

     return true;
}


bool controlador::btnAgregar(Tarea *t1){
    if (lista_tareas.length() == 0)
        t1->setNumero(1);
    else
        t1->setNumero(lista_tareas.at(lista_tareas.length()-1)->numero()+1);
    lista_tareas.append(t1);
    vaciarArchivo();
    if(escribirDatos()){
        return true;
    }
    return false;
}



