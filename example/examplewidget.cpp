#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <detailswidget.h>
// DetailsWidget is located in namespace Utils:
using namespace Utils;

struct ExampleWidgetData {
    ExampleWidgetData() {}

    DetailsWidget details_widget;
};


ExampleWidget::ExampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExampleWidget)
{
    ui->setupUi(this);
    setWindowTitle("Qt Creator Utilities Example");
    d = new ExampleWidgetData;

    // --------------------------------
    // Show the details widget:
    // --------------------------------
    if (ui->widgetDetailsWidgetHolder->layout())
        delete ui->widgetDetailsWidgetHolder->layout();

    QHBoxLayout* layout = new QHBoxLayout(ui->widgetDetailsWidgetHolder);
    layout->addWidget(&d->details_widget);
    layout->setMargin(0);

    d->details_widget.setWidget(ui->widgetDetailsWidgetContents);
    d->details_widget.setSummaryText("Details Widget Example");
    d->details_widget.setSummaryFontBold(true);
    d->details_widget.setState(DetailsWidget::Expanded);
}

ExampleWidget::~ExampleWidget()
{
    delete ui;
}
