#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QWidget>
#include <QStringList>
#include <QCheckBox>
#include <QLineEdit>
#include <QObject>

// ����� ����������
class FruitInfo : public QObject {
    Q_OBJECT
public:
    QStringList getFullNames() const {
        return QStringList{
            tr("Apple"),
            tr("Pear"),
            tr("Orange")
        };
    }

    QStringList getAbbreviations() const {
        return QStringList{
            tr("Multi-seeded juicy non-opening fruit"),
            tr("A genus of fruit and ornamental trees and shrubs of the Rose family"),
            tr("A multi-nesting berry, covered with a rough orange peel")
        };
    }
};

// ��������� ������� ��� ComboBox
class ComboBoxListener : public QObject {
    Q_OBJECT

private:
    QLabel* label;
    QCheckBox* checkBox;
    FruitInfo* info;

public:
    explicit ComboBoxListener(FruitInfo* provider, QLabel* label, QCheckBox* checkBox, QObject* parent = nullptr)
        : QObject(parent), info(provider), label(label), checkBox(checkBox) {}

public slots:
    void onComboBoxIndexChanged(int index) {
        // ���� ������ ����������, ������ �� �������
        if (checkBox->isChecked()) {
            label->clear();
            return;
        }
        // ���� ������ �������, ������� ��������������� ����������
        if (index >= 0) {
            QString selectedFullName = info->getFullNames().at(index);
            QString selectedAbbreviation = info->getAbbreviations().at(index);
            label->setText(tr("Selected: %1 - %2").arg(selectedFullName, selectedAbbreviation));
        }
    }
};

// ��������� ������� ��� QCheckBox
class CheckBoxListener : public QObject {
    Q_OBJECT
private:
    QLabel* label;
public:
    explicit CheckBoxListener(QLabel* label, QObject* parent = nullptr)
        : QObject(parent), label(label) {}

public slots:
    void onCheckBoxStateChanged(int state) {
        if (state == Qt::Checked) {
            // ������� ����� QLabel
            label->clear();
        }
        else {
            // ��������������� ��������� ��������� QLabel
            label->setText(tr("Selected: "));
        }
    }
};

// ��������� ������� ��� QLineEdit
class LineEditListener : public QObject {
    Q_OBJECT

private:
    QLabel* outputLabel;

public:
    explicit LineEditListener(QLabel* outputLabel, QObject* parent = nullptr)
        : QObject(parent), outputLabel(outputLabel) {}

public slots:
    void onTextChanged(const QString& text) {
        // ���������� ������
        outputLabel->setText(text + tr(" - And that's great!"));
    }
};

// ����� ����������
class Interface : public QWidget {
    Q_OBJECT

private:
    QComboBox* comboBox;
    QLabel* label;
    QCheckBox* clearCheckBox;
    QLineEdit* lineEdit;
    QLabel* lineEditOutputLabel;
    QVBoxLayout* layout;
    ComboBoxListener* comboBoxListener;
    CheckBoxListener* checkBoxListener;
    LineEditListener* lineEditListener;

public:
    explicit Interface(FruitInfo* provider, QWidget* parent = nullptr)
        : QWidget(parent) {
        // ������� ComboBox, �����, CheckBox, ��������� ���� � ����� ��� ������
        comboBox = new QComboBox(this);
        label = new QLabel(tr("Selected: "), this);
        clearCheckBox = new QCheckBox(tr("Clear label"), this);
        lineEdit = new QLineEdit(this);
        lineEditOutputLabel = new QLabel(tr(""), this);

        // ��������� ���-� � comboBox
        QStringList items = provider->getFullNames();
        comboBox->addItems(items);

        // ������ ��������� ��� ComboBox � ���������� ������
        comboBoxListener = new ComboBoxListener(provider, label, clearCheckBox, this);
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            comboBoxListener, &ComboBoxListener::onComboBoxIndexChanged);

        // ������ ��������� ��� CheckBox � ���������� ������
        checkBoxListener = new CheckBoxListener(label, this);
        connect(clearCheckBox, &QCheckBox::stateChanged,
            checkBoxListener, &CheckBoxListener::onCheckBoxStateChanged);

        // ������ ��������� ��� QLineEdit � ���������� ������
        lineEditListener = new LineEditListener(lineEditOutputLabel, this);
        connect(lineEdit, &QLineEdit::textChanged,
            lineEditListener, &LineEditListener::onTextChanged);

        // ������������� ����������
        layout = new QVBoxLayout(this);
        QSpacerItem* topSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
        layout->addSpacerItem(topSpacer);
        layout->addWidget(label);
        QSpacerItem* middleSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
        layout->addSpacerItem(middleSpacer);
        layout->addWidget(comboBox);
        middleSpacer = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);
        layout->addSpacerItem(middleSpacer);
        layout->addWidget(clearCheckBox);
        middleSpacer = new QSpacerItem(0, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);
        layout->addSpacerItem(middleSpacer);
        layout->addWidget(lineEdit);
        layout->addWidget(lineEditOutputLabel);

        setLayout(layout);

        setWindowTitle("mag_lab4");
    }
};
