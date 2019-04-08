#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

//!
//! \brief The MainWindow class is the QMainWindow of this QT project.
//! starts the application and its parent of all the rest of the windows.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! \brief MainWindow constructor. Creates the mainWindow with all its widgets.
    //! \param parent: QWidget parent of this window.
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //! \brief on_joinGameButton_clicked slot is signaled when user clicks joinGameButton.
    //! Creates a QDialog for this window.
    void on_joinGameButton_clicked();
    //! \brief on_createGameButton_clicked slot is signaled when user clicks createGameButton.
    //! Creates a QDialog for this window.
    void on_createGameButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
