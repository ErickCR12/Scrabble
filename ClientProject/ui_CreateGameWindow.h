/********************************************************************************
** Form generated from reading UI file 'CreateGameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGAMEWINDOW_H
#define UI_CREATEGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGameWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptCreationButton;
    QPushButton *cancelCreationButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *amountOfPlayersComboBox;

    void setupUi(QDialog *CreateGameWindow)
    {
        if (CreateGameWindow->objectName().isEmpty())
            CreateGameWindow->setObjectName(QStringLiteral("CreateGameWindow"));
        CreateGameWindow->resize(289, 140);
        horizontalLayoutWidget = new QWidget(CreateGameWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 70, 191, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        acceptCreationButton = new QPushButton(horizontalLayoutWidget);
        acceptCreationButton->setObjectName(QStringLiteral("acceptCreationButton"));
        acceptCreationButton->setMinimumSize(QSize(20, 40));

        horizontalLayout->addWidget(acceptCreationButton);

        cancelCreationButton = new QPushButton(horizontalLayoutWidget);
        cancelCreationButton->setObjectName(QStringLiteral("cancelCreationButton"));
        cancelCreationButton->setMinimumSize(QSize(20, 40));

        horizontalLayout->addWidget(cancelCreationButton);

        formLayoutWidget = new QWidget(CreateGameWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 239, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        amountOfPlayersComboBox = new QComboBox(formLayoutWidget);
        amountOfPlayersComboBox->setObjectName(QStringLiteral("amountOfPlayersComboBox"));
        amountOfPlayersComboBox->setMaxVisibleItems(3);

        formLayout->setWidget(0, QFormLayout::FieldRole, amountOfPlayersComboBox);


        retranslateUi(CreateGameWindow);

        amountOfPlayersComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CreateGameWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateGameWindow)
    {
        CreateGameWindow->setWindowTitle(QApplication::translate("CreateGameWindow", "Dialog", Q_NULLPTR));
        acceptCreationButton->setText(QApplication::translate("CreateGameWindow", "Aceptar", Q_NULLPTR));
        cancelCreationButton->setText(QApplication::translate("CreateGameWindow", "Cancelar", Q_NULLPTR));
        label->setText(QApplication::translate("CreateGameWindow", "Cantidad de jugadores :", Q_NULLPTR));
        amountOfPlayersComboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateGameWindow: public Ui_CreateGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGAMEWINDOW_H
