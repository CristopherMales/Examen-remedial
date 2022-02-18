#ifndef TAREA_H
#define TAREA_H
#include <QDateTime>
#include <QObject>
class Tarea : public QObject
{
private:
    int dato_numero;
    QString dato_nombre;
    QDate dato_fecha;
    QChar dato_prioridad;
    QString dato_tipo;
    bool dato_finalizada;

public:
    int numero();
    void setNumero(int numero);
    QString nombre();
    void setNombre(QString nombre);

    QDate fecha();

    void setFecha(QDate fecha);

    QChar prioridad();

    void setPrioridad(QChar prioridad);

    QString tipo();

    void setTipo(QString tipo);

    bool finalizada();

    void setFinalizada(bool finalizada);

    explicit Tarea(QObject *parent = nullptr);

    Tarea(int numero, QString nombre, QDate fecha, QChar prioridad, QString tipo, bool finalizada);
};

#endif // TAREA_H
