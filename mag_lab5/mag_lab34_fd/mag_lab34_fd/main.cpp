#include <QtWidgets/QApplication>
#include <QTranslator>
#include "mag_lab34_fd.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    QTranslator translator;//��� �������� ���������� �� ������ ����
    translator.load("Translation_lab34_ru.qm");//�������� ����� ������ qm-���� c ���������
    app.installTranslator(&translator);//��������� ������� � ����������
    MainWindow window;
    window.show();

    return app.exec();
}
