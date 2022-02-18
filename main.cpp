#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
        // Solicitando al usuario que seleccione un idioma
        QStringList lista_idiomas;
        lista_idiomas << "Ingles" << "Español";
        QString idioma_seleccionado= QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   lista_idiomas);

        if (idioma_seleccionado == "Ingles"){
            traducion.load(":/Remedial_en.qm");
            a.installTranslator(&traducion);
        }
    Principal w;
    w.show();
    return a.exec();
}
