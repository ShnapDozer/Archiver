#include <QApplication>

#include "include/choose.h"
#include "include/encoding.h"
#include "include/decoding.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Choose w;
    w.show();

    return a.exec();
}
