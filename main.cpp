#include <QApplication>
#include "rhythmdeck.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RhythmDeck mainDeck;
    mainDeck.show();

    return app.exec();
}
