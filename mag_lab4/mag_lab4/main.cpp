#include <QApplication>
#include "mag_lab4.h"
#include <QTranslator>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTranslator translator;//��� �������� ���������� �� ������ ����
    translator.load("Translation_ru_RU.qm");//�������� ����� ������ qm-���� c ���������
    app.installTranslator(&translator);//��������� ������� � ����������

    // ������� ���������� ����������
    FruitInfo provider;

    // ������� ��������� ComboBox
    Interface listener(&provider);
    listener.resize(300, 150);
    listener.show();

    return app.exec();
}
