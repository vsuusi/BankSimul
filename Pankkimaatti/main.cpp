#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // style sheet hommat, alla oleva polkua pitää muokata itselle oikeaksi!

    QFile styleSheetTiedosto("C:/Projektit/SovellusprojektiPankki/group20/Pankkimaatti/build/debug/Adaptic.qss");
    styleSheetTiedosto.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetTiedosto.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}
