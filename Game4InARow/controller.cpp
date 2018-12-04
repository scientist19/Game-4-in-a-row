#include "controller.h"

#include <ui_gamefield.h>
#include <ui_mainwindow.h>

Controller::Controller(QWidget *parent) : QMainWindow(parent)
{
    connect(menu->ui->singlePlayerButton, SIGNAL(clicked()), this, SLOT(onSinglePlayerButton()) );
    connect(menu->ui->twoPlayersButton, SIGNAL(clicked()), this, SLOT(onTwoPlayersButton()) );

}

void Controller::onSinglePlayerButton()
{
    menu->hide();
    gameField = new GameField(true);

    initGameField();
}

void Controller::onTwoPlayersButton()
{
    menu->hide();
    gameField = new GameField(false);

    initGameField();
}

void Controller::onBackToMenuButton()
{
    gameField->~GameField();
    menu->show();
}

void Controller::initGameField()
{
      connect(gameField->ui->backToMenuButton, SIGNAL(clicked()), this, SLOT(onBackToMenuButton()));
}
