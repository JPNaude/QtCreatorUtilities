#include <QApplication>

#include "examplewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExampleWidget example_widget;
    example_widget.show();
    return a.exec();
}
