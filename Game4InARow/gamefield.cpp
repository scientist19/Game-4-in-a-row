#include "gamefield.h"
#include "ui_gamefield.h"

#include "field.h"

#include <vector>
#include <QString>
#include <QtGui>

#include <QFileDialog>
#include <QRectF>

#include "circle.h"

GameField::GameField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameField)
{
    ui->setupUi(this);
    show();


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(0, 0, 0, 100)));

//    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/rec/img/background1.png")));
    createField();

    moveTimeTimer = new QTimer();
    connect(moveTimeTimer, SIGNAL(timeout()), this, SLOT(checkForMove()));
    moveTimeTimer->start(1000);

}

void GameField::checkForMove()
{
    if (myRect->isTimeToMove() == 2) myRect->AIMove();
}

void GameField::createField(){

    const double scale = 0.8;

    QImage image(":/rec/img/cell.png");
    int cellSize = image.width()*scale;

    myRect = new Field(scene, cellSize);
    myRect->setRect(QRectF(LEFT_SHIFT, TOP_SHIFT, 7*cellSize, 6*cellSize));
    myRect->setBrush(QBrush(QColor(0,0,0,0)));
    myRect->setCursor(QCursor(Qt::PointingHandCursor));
    scene->addItem(myRect);

    animationTimer = new QTimer(this);
    connect(animationTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    animationTimer->start(1000/90);


    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++){

            QGraphicsPixmapItem* myItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            myItem->setScale(scale);
            myItem->setPos(LEFT_SHIFT + j*cellSize, TOP_SHIFT + i*cellSize);
            myItem->setZValue(1);

            scene->addItem(myItem);
            myRect->setItem(myItem, i, j);
        }
}


GameField::~GameField()
{
    delete ui;
}




