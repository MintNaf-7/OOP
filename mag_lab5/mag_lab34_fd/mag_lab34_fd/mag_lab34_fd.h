#ifndef MAG_LAB34_FD
#define MAG_LAB34_FD

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void convertToGrayCode();

private:
    QLineEdit* inputField;
    QLabel* resultLabel;
    QPushButton* convertButton;

    string toReflectionCode(int number);
};

#endif // MAINWINDOW_H
