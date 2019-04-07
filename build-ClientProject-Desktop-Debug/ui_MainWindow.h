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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1067, 600);
        MainWindow->setMinimumSize(QSize(1067, 600));
        MainWindow->setMaximumSize(QSize(1067, 600));
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        createGameButton = new QPushButton(centralWidget);
        createGameButton->setObjectName(QStringLiteral("createGameButton"));
        createGameButton->setGeometry(QRect(570, 390, 251, 141));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createGameButton->sizePolicy().hasHeightForWidth());
        createGameButton->setSizePolicy(sizePolicy);
        createGameButton->setMinimumSize(QSize(175, 67));
        createGameButton->setMaximumSize(QSize(3232, 3223));
        createGameButton->setAutoFillBackground(false);
        createGameButton->setFlat(false);
        joinGameButton = new QPushButton(centralWidget);
        joinGameButton->setObjectName(QStringLiteral("joinGameButton"));
        joinGameButton->setGeometry(QRect(230, 410, 251, 101));
        sizePolicy.setHeightForWidth(joinGameButton->sizePolicy().hasHeightForWidth());
        joinGameButton->setSizePolicy(sizePolicy);
        joinGameButton->setMinimumSize(QSize(180, 67));
        joinGameButton->setMaximumSize(QSize(44444, 213123));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scrabble!", Q_NULLPTR));
        createGameButton->setText(QString());
        joinGameButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
