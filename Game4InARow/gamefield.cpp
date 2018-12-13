#include "gamefield.h"
#include "ui_gamefield.h"

#include "singleplayerfield.h"
#include "twoplayersfield.h"
#include "circle.h"

#include <vector>
#include <QString>
#include <QtGui>

#include <QRectF>


GameField::GameField(bool isSingleGame, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameField)
{
    ui->setupUi(this);
    show();

    world = new b2World(b2Vec2(0.00f, 10.00f));
    scene = new Scene(0, 0, 850, 700, world);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(0, 0, 0, 100)));

    createField(isSingleGame);

    moveTimeTimer = new QTimer();
    connect(moveTimeTimer, SIGNAL(timeout()), this, SLOT(checkForMove()));
    moveTimeTimer->start(1000/1);

}

void GameField::checkForMove()
{
    myField->changePlayer();
}

void GameField::createField(bool isSingleGame){

    const double scale = 0.8;

    QImage image(":/rec/img/cellGray.png");
    double cellSize = image.width()*scale;

    if (isSingleGame) myField = new SinglePlayerField(scene, cellSize);
    else myField = new TwoPlayersField(scene, cellSize);

    myField->setGameField(this);

    myField->setRect(QRectF(LEFT_SHIFT, TOP_SHIFT, 7*cellSize, 6*cellSize));
    myField->setBrush(QBrush(QColor(0,0,0,0)));
    myField->setCursor(QCursor(Qt::PointingHandCursor));
    scene->addItem(myField);

    animationTimer = new QTimer(this);
    connect(animationTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    animationTimer->start(1000/110);


    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++){

            QGraphicsPixmapItem* myItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            myItem->setScale(scale);
            myItem->setPos(LEFT_SHIFT + j*cellSize, TOP_SHIFT + i*cellSize);
            myItem->setZValue(1);

            scene->addItem(myItem);
            myField->setItem(myItem, i, j);
        }

    /*
    QGraphicsRectItem* rectItem = new QGraphicsRectItem(0, TOP_SHIFT + 6*cellSize, scene->sceneRect().width(), 0.2*SCALE);
    rectItem->setBrush(QBrush(Qt::gray));
    scene->addItem(rectItem);
    */

    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;

    float32 h = 0.2f;
    float32 w = scene->sceneRect().width()/SCALE;
    float32 posx = (scene->sceneRect().width()/2)/SCALE;
    float32 posy = (TOP_SHIFT + 6*cellSize)/SCALE + h/2;
    bodyDef.position.Set(posx, posy);

    b2Body* body = world->CreateBody(&bodyDef);

    b2PolygonShape shape;
    shape.SetAsBox(w/2, h/2);

    body->CreateFixture(&shape, 0.0f);

}

void GameField::resizeWinnerLabel()
{
    QFont font = ui->winnerLabel->font();
    font.setPixelSize(50);
    ui->winnerLabel->setFont(font);
}


GameField::~GameField()
{
    delete ui;
}

void GameField::playerWin()
{
    resizeWinnerLabel();
    ui->winnerLabel->setText("WIN!!!");
}

void GameField::playerWin(int player)
{
    resizeWinnerLabel();
    ui->winnerLabel->setText("Player #" + QString::number(player) + " win!");
}

void GameField::AIWin()
{
    resizeWinnerLabel();
    ui->winnerLabel->setText("LOSE!!!");
}




