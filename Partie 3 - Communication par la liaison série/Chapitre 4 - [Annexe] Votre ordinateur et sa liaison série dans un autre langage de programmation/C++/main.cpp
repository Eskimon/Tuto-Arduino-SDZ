#include <QtGui/QApplication>
#include "fenetre.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fenetre f;
    f.show();
    
    return a.exec();
}


