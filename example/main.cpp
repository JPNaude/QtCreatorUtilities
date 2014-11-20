#include <QApplication>

#include "examplewidget.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ExampleWidget example_widget;
    example_widget.show();
    return a.exec();
}
