#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "demo.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;//для перевода приложения на нужный язык
    translator.load("Translation_ru.qm");//пытаемся найти нужный qm-файл c переводом
    app.installTranslator(&translator);//загружаем перевод в приложение

    app.setWindowIcon(QIcon(":/resources/gus.png"));

    Demo window;
    window.setWindowTitle(("Demo"));
    window.resize(300, 200);
    window.show();

    return app.exec();
}
