/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *createGameButton;
    QPushButton *joinGameButton;
    QLabel *logoLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        createGameButton = new QPushButton(centralWidget);
        createGameButton->setObjectName(QStringLiteral("createGameButton"));
        createGameButton->setGeometry(QRect(170, 480, 172, 40));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createGameButton->sizePolicy().hasHeightForWidth());
        createGameButton->setSizePolicy(sizePolicy);
        createGameButton->setMinimumSize(QSize(120, 40));
        joinGameButton = new QPushButton(centralWidget);
        joinGameButton->setObjectName(QStringLiteral("joinGameButton"));
        joinGameButton->setGeometry(QRect(430, 480, 171, 41));
        sizePolicy.setHeightForWidth(joinGameButton->sizePolicy().hasHeightForWidth());
        joinGameButton->setSizePolicy(sizePolicy);
        joinGameButton->setMinimumSize(QSize(120, 40));
        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));
        logoLabel->setGeometry(QRect(310, 130, 221, 121));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scrabble!", Q_NULLPTR));
        createGameButton->setText(QApplication::translate("MainWindow", "Crear juego", Q_NULLPTR));
        joinGameButton->setText(QApplication::translate("MainWindow", "Unirse a un juego", Q_NULLPTR));
        logoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
