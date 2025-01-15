#include <QtWidgets/QApplication>
#include <QTranslator>
#include "mag_lab34_fd.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    QTranslator translator;//для перевода приложения на нужный язык
    translator.load("Translation_lab34_ru.qm");//пытаемся найти нужный qm-файл c переводом
    app.installTranslator(&translator);//загружаем перевод в приложение
    MainWindow window;
    window.show();

    return app.exec();
}
