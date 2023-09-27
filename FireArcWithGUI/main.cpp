#include "SearchSwitcher.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SearchSwitcher w;
    w.show();
    return a.exec();
}
