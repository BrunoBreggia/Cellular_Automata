#include <QApplication>
#include "automataunicelular.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    cout << "Choose Rule: ";
    unsigned option;
    cin >> option;
    AutomataUnicelular colonia(option, 100);

    cout << "First seed: ";
    cin >> option;
    colonia.switchState(option);

    while(true) {

    for (auto i=0; i<colonia.getSize(); ++i)
        cout << (colonia.getState(i)? "1" : " ");
    cout << endl;
    colonia.nextEpoch();

    }

    return app.exec();
}
