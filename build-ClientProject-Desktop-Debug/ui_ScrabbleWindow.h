/********************************************************************************
** Form generated from reading UI file 'ScrabbleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRABBLEWINDOW_H
#define UI_SCRABBLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ScrabbleWindow
{
public:

    void setupUi(QDialog *ScrabbleWindow)
    {
        if (ScrabbleWindow->objectName().isEmpty())
            ScrabbleWindow->setObjectName(QStringLiteral("ScrabbleWindow"));
        ScrabbleWindow->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrabbleWindow->sizePolicy().hasHeightForWidth());
        ScrabbleWindow->setSizePolicy(sizePolicy);
        ScrabbleWindow->setMinimumSize(QSize(800, 700));
        ScrabbleWindow->setMaximumSize(QSize(800, 700));

        retranslateUi(ScrabbleWindow);

        QMetaObject::connectSlotsByName(ScrabbleWindow);
    } // setupUi

    void retranslateUi(QDialog *ScrabbleWindow)
    {
        ScrabbleWindow->setWindowTitle(QApplication::translate("ScrabbleWindow", "Scrabble!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScrabbleWindow: public Ui_ScrabbleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRABBLEWINDOW_H
