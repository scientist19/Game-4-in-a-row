#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamefield.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void play();

public:
    Ui::MainWindow *ui;
 //   GameField* gf = new GameField();
};

#endif // MAINWINDOW_H
