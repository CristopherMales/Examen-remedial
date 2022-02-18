#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <QObject>
#include "tarea.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

class controlador : public QObject
{
public:
     explicit controlador(QObject *parent = nullptr);
    //Tarea *tarea() const;
    bool btnAgregar(Tarea *t1);
    bool escribirDatos();
    bool cargarDatos();
    bool vaciarArchivo();
    QList<Tarea*> lista_tareas;

};



#endif // CONTROLADOR_H
