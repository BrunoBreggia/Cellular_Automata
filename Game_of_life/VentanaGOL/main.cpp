#include "golwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GOLwindow w;
    w.show();

    return a.exec();
}
