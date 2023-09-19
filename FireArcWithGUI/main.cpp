#include "FireArcWithGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireArcWithGUI w;
    w.show();
    return a.exec();
}
