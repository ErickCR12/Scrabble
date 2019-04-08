/********************************************************************************
** Form generated from reading UI file 'JoinGameWindow.ui'
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoinGameWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertCodeButton;
    QPushButton *cancelCodeButton;
    QLineEdit *codeLineEdit;
    QLabel *joinGameLabel;

    void setupUi(QDialog *JoinGameWindow)
    {
        if (JoinGameWindow->objectName().isEmpty())
            JoinGameWindow->setObjectName(QStringLiteral("JoinGameWindow"));
        JoinGameWindow->resize(300, 200);
        horizontalLayoutWidget = new QWidget(JoinGameWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 120, 191, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        insertCodeButton = new QPushButton(horizontalLayoutWidget);
        insertCodeButton->setObjectName(QStringLiteral("insertCodeButton"));
        insertCodeButton->setMinimumSize(QSize(20, 40));

        horizontalLayout->addWidget(insertCodeButton);

        cancelCodeButton = new QPushButton(horizontalLayoutWidget);
        cancelCodeButton->setObjectName(QStringLiteral("cancelCodeButton"));
        cancelCodeButton->setMinimumSize(QSize(20, 40));

        horizontalLayout->addWidget(cancelCodeButton);

        codeLineEdit = new QLineEdit(JoinGameWindow);
        codeLineEdit->setObjectName(QStringLiteral("codeLineEdit"));
        codeLineEdit->setGeometry(QRect(80, 80, 151, 23));
        joinGameLabel = new QLabel(JoinGameWindow);
        joinGameLabel->setObjectName(QStringLiteral("joinGameLabel"));
        joinGameLabel->setGeometry(QRect(40, 30, 231, 41));
        joinGameLabel->setAlignment(Qt::AlignCenter);
        joinGameLabel->setWordWrap(true);

        retranslateUi(JoinGameWindow);

        QMetaObject::connectSlotsByName(JoinGameWindow);
    } // setupUi

    void retranslateUi(QDialog *JoinGameWindow)
    {
        JoinGameWindow->setWindowTitle(QApplication::translate("JoinGameWindow", "Dialog", Q_NULLPTR));
        insertCodeButton->setText(QApplication::translate("JoinGameWindow", "Aceptar", Q_NULLPTR));
        cancelCodeButton->setText(QApplication::translate("JoinGameWindow", "Cancelar", Q_NULLPTR));
        joinGameLabel->setText(QApplication::translate("JoinGameWindow", "Ingrese el c\303\263digo del juego al que se desea unir: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JoinGameWindow: public Ui_JoinGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINGAMEWINDOW_H
