#include <QApplication>
#include "mag_lab4.h"
#include <QTranslator>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTranslator translator;//для перевода приложения на нужный язык
    translator.load("Translation_ru_RU.qm");//пытаемся найти нужный qm-файл c переводом
    app.installTranslator(&translator);//загружаем перевод в приложение

    // Создаем поставщика информации
    FruitInfo provider;

    // Создаем слушатель ComboBox
    Interface listener(&provider);
    listener.resize(300, 150);
    listener.show();

    return app.exec();
}
