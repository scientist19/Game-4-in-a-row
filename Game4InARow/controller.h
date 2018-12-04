#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamefield.h"
#include "mainwindow.h"

#include <QWidget>
#include <QMainWindow>


class Controller : public QMainWindow
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = nullptr);

signals:

public slots:
    void onSinglePlayerButton();
    void onTwoPlayersButton();

    void onBackToMenuButton();

private:
    MainWindow* menu = new MainWindow();
    GameField* gameField;

    void initGameField();
};

#endif // CONTROLLER_H
