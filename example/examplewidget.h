#ifndef EXAMPLEWIDGET_H
#define EXAMPLEWIDGET_H

#include <QWidget>

namespace Ui {
class ExampleWidget;
}

struct ExampleWidgetData;

class ExampleWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ExampleWidget(QWidget *parent = 0);
    ~ExampleWidget();
    
private:
    Ui::ExampleWidget *ui;
    ExampleWidgetData* d;
};

#endif // EXAMPLEWIDGET_H
