/********************************************************************************
** Form generated from reading UI file 'joinGameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINGAMEWINDOW_H
#define UI_JOINGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_joinGameWindow
{
public:
    QLabel *label;
    QLineEdit *codeLineEdit;
    QPushButton *acceptCodeButton;
    QPushButton *cancelCodeButton;

    void setupUi(QDialog *joinGameWindow)
    {
        if (joinGameWindow->objectName().isEmpty())
            joinGameWindow->setObjectName(QStringLiteral("joinGameWindow"));
        joinGameWindow->resize(278, 170);
        label = new QLabel(joinGameWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 181, 16));
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        codeLineEdit = new QLineEdit(joinGameWindow);
        codeLineEdit->setObjectName(QStringLiteral("codeLineEdit"));
        codeLineEdit->setGeometry(QRect(90, 40, 113, 23));
        acceptCodeButton = new QPushButton(joinGameWindow);
        acceptCodeButton->setObjectName(QStringLiteral("acceptCodeButton"));
        acceptCodeButton->setGeometry(QRect(40, 110, 91, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(acceptCodeButton->sizePolicy().hasHeightForWidth());
        acceptCodeButton->setSizePolicy(sizePolicy);
        acceptCodeButton->setAutoDefault(false);
        cancelCodeButton = new QPushButton(joinGameWindow);
        cancelCodeButton->setObjectName(QStringLiteral("cancelCodeButton"));
        cancelCodeButton->setGeometry(QRect(140, 110, 91, 41));
        sizePolicy.setHeightForWidth(cancelCodeButton->sizePolicy().hasHeightForWidth());
        cancelCodeButton->setSizePolicy(sizePolicy);

        retranslateUi(joinGameWindow);

        QMetaObject::connectSlotsByName(joinGameWindow);
    } // setupUi

    void retranslateUi(QDialog *joinGameWindow)
    {
        joinGameWindow->setWindowTitle(QApplication::translate("joinGameWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("joinGameWindow", "Ingrese el c\303\263digo del juego:", Q_NULLPTR));
        acceptCodeButton->setText(QApplication::translate("joinGameWindow", "Aceptar", Q_NULLPTR));
        cancelCodeButton->setText(QApplication::translate("joinGameWindow", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class joinGameWindow: public Ui_joinGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINGAMEWINDOW_H
