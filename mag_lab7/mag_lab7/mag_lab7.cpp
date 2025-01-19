#include "mag_lab7.h"

MagLab7::MagLab7(QWidget* parent)
    : QMainWindow(parent) {
    // центральный виджет
    QWidget* centralWidget = new QWidget(this);

    // Списки
    listWidgetLeft = new QListWidget();
    listWidgetRight = new QListWidget();

    QStringList players = {
        "A", "B", "C", "D",
        "E", "F", "G",
        "H", "I", "J", "K"
    };
    listWidgetLeft->addItems(players);

    // Сортировка
    sortList(listWidgetLeft);

    // Кнопки
    btnMoveRight = new QPushButton(">");
    btnMoveAllRight = new QPushButton(">>");
    btnMoveLeft = new QPushButton("<");
    btnMoveAllLeft = new QPushButton("<<");
    btnSave = new QPushButton("Save");
    btnReset = new QPushButton("Reset");
    btnExit = new QPushButton("Exit");

    QVBoxLayout* buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(btnMoveRight);
    buttonLayout->addWidget(btnMoveAllRight);
    buttonLayout->addWidget(btnMoveLeft);
    buttonLayout->addWidget(btnMoveAllLeft);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addWidget(listWidgetLeft);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(listWidgetRight);

    QHBoxLayout* topLayout = new QHBoxLayout();
    topLayout->addWidget(btnSave);
    topLayout->addWidget(btnReset);
    topLayout->addWidget(btnExit);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addLayout(topLayout);
    layout->addLayout(mainLayout);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(btnMoveRight, &QPushButton::clicked, this, &MagLab7::moveItemRight);
    connect(btnMoveAllRight, &QPushButton::clicked, this, &MagLab7::moveAllRight);
    connect(btnMoveLeft, &QPushButton::clicked, this, &MagLab7::moveItemLeft);
    connect(btnMoveAllLeft, &QPushButton::clicked, this, &MagLab7::moveAllLeft);
    connect(btnSave, &QPushButton::clicked, this, &MagLab7::saveData);
    connect(btnReset, &QPushButton::clicked, this, &MagLab7::resetData);
    connect(btnExit, &QPushButton::clicked, this, &MagLab7::exitApplication);
}

MagLab7::~MagLab7() {}

void MagLab7::moveItemRight() {
    QListWidgetItem* item = listWidgetLeft->takeItem(listWidgetLeft->currentRow());
    if (item) {
        listWidgetRight->addItem(item);
        sortList(listWidgetRight); 
    }
}

void MagLab7::moveItemLeft() {
    QListWidgetItem* item = listWidgetRight->takeItem(listWidgetRight->currentRow());
    if (item) {
        listWidgetLeft->addItem(item);
        sortList(listWidgetLeft);
    }
}

void MagLab7::moveAllRight() {
    while (listWidgetLeft->count() > 0) {
        QListWidgetItem* item = listWidgetLeft->takeItem(0);
        listWidgetRight->addItem(item);
    }
    sortList(listWidgetRight); 
}

void MagLab7::moveAllLeft() {
    while (listWidgetRight->count() > 0) {
        QListWidgetItem* item = listWidgetRight->takeItem(0);
        listWidgetLeft->addItem(item);
    }
    sortList(listWidgetLeft); 
}

void MagLab7::saveData() {
    QStringList rightListData;
    for (int i = 0; i < listWidgetRight->count(); ++i) {
        rightListData << listWidgetRight->item(i)->text();
    }
    QMessageBox::information(this, "Saved items", rightListData.join("\n"));
}

void MagLab7::resetData() {
    moveAllLeft();
}

void MagLab7::exitApplication() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        close();
    }
}

void MagLab7::sortList(QListWidget* listWidget) {
    QStringList items;
    for (int i = 0; i < listWidget->count(); ++i) {
        items << listWidget->item(i)->text();
    }
    items.sort(Qt::CaseInsensitive); // Сортировка по алфавиту
    listWidget->clear();
    listWidget->addItems(items);
}
