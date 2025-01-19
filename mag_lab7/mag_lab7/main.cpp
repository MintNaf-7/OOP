#include <QApplication>
#include "mag_lab7.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MagLab7 magLab7;
    magLab7.show();

    return app.exec();
}
