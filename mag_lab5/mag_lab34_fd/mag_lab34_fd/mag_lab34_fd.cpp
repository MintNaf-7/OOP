#include <stdexcept>
#include "mag_lab34_fd.h"
#include "cmath"

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    // Создаём виджеты
    QWidget* centralWidget = new QWidget(this);
    inputField = new QLineEdit(this);
    convertButton = new QPushButton(tr("Convert a number"), this);
    resultLabel = new QLabel(tr("Reflex code with base 4: "), this);

    // Настройка интерфейса
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(new QLabel(tr("Enter a number:"), this));
    layout->addWidget(inputField);
    layout->addWidget(convertButton);
    layout->addWidget(resultLabel);

    // Устанавливаем центральный виджет
    setCentralWidget(centralWidget);

    // Подключаем сигнал кнопки к слоту
    connect(convertButton, &QPushButton::clicked, this, &MainWindow::convertToGrayCode);
}

MainWindow::~MainWindow() {
    // Освобождение ресурсов (если требуется)
}

void MainWindow::convertToGrayCode() {
    try {
        // Получение числа из текстового поля
        bool ok;
        int number = inputField->text().toInt(&ok);

        if (!ok) {
            throw std::invalid_argument(tr("Enter the correct number.").toStdString());
        }

        if (number < 0) {
            throw std::out_of_range(tr("The number must be non-negative.").toStdString());
        }

        // Преобразование в код
        string Code = toReflectionCode(number);

        // Вывод результата
        resultLabel->setText(tr("Reflex code with base 4: ") + QString::fromStdString(Code));
    }
    catch (const std::invalid_argument& e) {
        resultLabel->setText(tr("Error: ") + QString::fromStdString(e.what()));
    }
    catch (const std::out_of_range& e) {
        resultLabel->setText(tr("Error: ") + QString::fromStdString(e.what()));
    }
    catch (const std::exception& e) {
        // Общий обработчик для других стандартных исключений
        resultLabel->setText(tr("Unexpected error: ") + QString::fromStdString(e.what()));
    }
    catch (...) {
        // Обработка неизвестных ошибок
        resultLabel->setText(tr("Unexpected error: An unknown error occurred."));
    }
}

string MainWindow::toReflectionCode(int number) {

    int base = 4;
    int i;
    int arr[8]{ 0, 1, 2, 3, 3, 2, 1, 0 };
    if (number == 0) return "0";

    string reflectedCode;
    int  a = number, n = 0;
    while (a >= 1) {
        i = number / int(pow(base, n)) % (base * 2);
        reflectedCode = to_string(arr[i]) + reflectedCode;
        n += 1;
        a = a / base;
    }

    return reflectedCode;
}
