#ifndef MAG_LAB7_H
#define MAG_LAB7_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class MagLab7 : public QMainWindow {
    Q_OBJECT

public:
    MagLab7(QWidget* parent = nullptr);
    ~MagLab7();

private slots:
    void moveItemRight();
    void moveItemLeft();
    void moveAllRight();
    void moveAllLeft();
    void saveData();
    void resetData();
    void exitApplication();

private:
    void sortList(QListWidget* listWidget); 

    QListWidget* listWidgetLeft;
    QListWidget* listWidgetRight;
    QPushButton* btnMoveRight;
    QPushButton* btnMoveAllRight;
    QPushButton* btnMoveLeft;
    QPushButton* btnMoveAllLeft;
    QPushButton* btnSave;
    QPushButton* btnReset;
    QPushButton* btnExit;
};

#endif // MAG_LAB7_H
