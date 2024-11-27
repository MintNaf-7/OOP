#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "demo.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;//��� �������� ���������� �� ������ ����
    translator.load("Translation_ru.qm");//�������� ����� ������ qm-���� c ���������
    app.installTranslator(&translator);//��������� ������� � ����������

    app.setWindowIcon(QIcon(":/resources/gus.png"));

    Demo window;
    window.setWindowTitle(("Demo"));
    window.resize(300, 200);
    window.show();

    return app.exec();
}
