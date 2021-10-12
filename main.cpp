#include "my_kaiser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_kaiser w;
    w.show();

    return a.exec();
}
