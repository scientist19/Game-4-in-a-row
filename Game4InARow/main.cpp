#include "controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   MainWindow w;
 //   w.show();
    Controller* contoller = new Controller();

    return a.exec();
}
