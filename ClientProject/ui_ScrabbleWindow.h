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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScrabbleWindow
{
public:
    QFrame *boardFrame;
    QPushButton *scrabbleButton;
    QPushButton *passButton;
    QFrame *scoresFrame;

    void setupUi(QDialog *ScrabbleWindow)
    {
        if (ScrabbleWindow->objectName().isEmpty())
            ScrabbleWindow->setObjectName(QStringLiteral("ScrabbleWindow"));
        ScrabbleWindow->resize(1067, 600);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScrabbleWindow->sizePolicy().hasHeightForWidth());
        ScrabbleWindow->setSizePolicy(sizePolicy);
        ScrabbleWindow->setMinimumSize(QSize(1067, 600));
        ScrabbleWindow->setMaximumSize(QSize(1067, 600));
        boardFrame = new QFrame(ScrabbleWindow);
        boardFrame->setObjectName(QStringLiteral("boardFrame"));
        boardFrame->setGeometry(QRect(40, 40, 610, 530));
        boardFrame->setMinimumSize(QSize(610, 530));
        boardFrame->setMaximumSize(QSize(610, 530));
        boardFrame->setFrameShape(QFrame::NoFrame);
        boardFrame->setFrameShadow(QFrame::Plain);
        scrabbleButton = new QPushButton(ScrabbleWindow);
        scrabbleButton->setObjectName(QStringLiteral("scrabbleButton"));
        scrabbleButton->setGeometry(QRect(670, 480, 201, 61));
        passButton = new QPushButton(ScrabbleWindow);
        passButton->setObjectName(QStringLiteral("passButton"));
        passButton->setGeometry(QRect(900, 450, 121, 111));
        scoresFrame = new QFrame(ScrabbleWindow);
        scoresFrame->setObjectName(QStringLiteral("scoresFrame"));
        scoresFrame->setGeometry(QRect(690, 60, 311, 361));
        scoresFrame->setFrameShape(QFrame::StyledPanel);
        scoresFrame->setFrameShadow(QFrame::Raised);

        retranslateUi(ScrabbleWindow);

        QMetaObject::connectSlotsByName(ScrabbleWindow);
    } // setupUi

    void retranslateUi(QDialog *ScrabbleWindow)
    {
        ScrabbleWindow->setWindowTitle(QApplication::translate("ScrabbleWindow", "Scrabble!", Q_NULLPTR));
        scrabbleButton->setText(QString());
        passButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScrabbleWindow: public Ui_ScrabbleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRABBLEWINDOW_H
