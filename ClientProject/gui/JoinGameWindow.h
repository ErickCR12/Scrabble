#ifndef JOINGAMEWINDOW_H
#define JOINGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class JoinGameWindow;
}

class JoinGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit JoinGameWindow(QWidget *parent = 0);
    ~JoinGameWindow();

private slots:

    void on_cancelCodeButton_clicked();

    void on_insertCodeButton_clicked();

private:
    Ui::JoinGameWindow *ui;
};

#endif // JOINGAMEWINDOW_H
