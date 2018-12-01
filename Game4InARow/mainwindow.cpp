#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamefield0.h"

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::play(){

    /*
    int pos = ui->spinBox->value();
    if (!gf->->canAddToColumn(pos)) return;

    qDebug() << "User move: ";
    gf->addToColumn(pos, 1);
    gf->print();

    if (gf->endOfGame() == 1) qDebug() << "WINNER PLAYER # 1 !!!!!!!";

    qDebug() << "AI move: ";
    auto bm = gf->bestMove(8, 2);
    gf->addToColumn(bm.first, 2);
    gf->print();

    if (gf->endOfGame() == 2) qDebug() << "WINNER PLAYER # 2 (AI) !!!!!!!";
    */
}
