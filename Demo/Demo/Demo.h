#ifndef DEMO_H
#define DEMO_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>

class Demo : public QWidget
{
    Q_OBJECT

public:
    Demo(QWidget* parent = nullptr);

private slots:
    void onLoadButtonClicked();
    void onExecuteButtonClicked();

private:
    void executeAction(int x, int y, int width, int height, const QString& path);

    QLineEdit* xLineEdit;
    QLineEdit* yLineEdit;
    QLineEdit* widthLineEdit;
    QLineEdit* heightLineEdit;
    QLineEdit* pathLineEdit;
    QPushButton* loadButton;
    QPushButton* executeButton;
    QLabel* resultLabel;
};

#endif // DEMO_H
