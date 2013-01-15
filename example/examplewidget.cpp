#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <detailswidget.h>
// DetailsWidget is located in namespace Utils:
using namespace Utils;

#include <infobar.h>
// DetailsWidget is located in namespace Core:
using namespace Core;

#include <QtDebug>
#include <QMessageBox>

struct ExampleWidgetData {
    ExampleWidgetData() : info_id_count(0) {}

    DetailsWidget details_widget;

    InfoBar info_bar;
    InfoBarDisplay info_bar_display;
    int info_id_count;
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

    // -------------------------------
    // Setup the info bar
    // -------------------------------
    if (ui->infoBarHolder->layout())
        delete ui->infoBarHolder->layout();

    QVBoxLayout* info_layout = new QVBoxLayout(ui->infoBarHolder);
    info_layout->setMargin(0);
    info_layout->setSpacing(0);
    d->info_bar_display.setInfoBar(&d->info_bar);
    d->info_bar_display.setTarget(info_layout,0);
}

ExampleWidget::~ExampleWidget()
{
    delete ui;
}

void ExampleWidget::on_btnAddInfoMessage_clicked() {
    InfoBarEntry info_entry(newInfoId(),"Example info bar message");
    d->info_bar.addInfo(info_entry);
}

void ExampleWidget::on_btnAddInfoMessageCancel_clicked() {
    InfoBarEntry info_entry(newInfoId(),"Example info bar message");
    info_entry.setCancelButtonInfo(this,SLOT(handleInfoBarCancelButton()));
    d->info_bar.addInfo(info_entry);
}

void ExampleWidget::on_btnAddInfoMessageCustom_clicked() {
    InfoBarEntry info_entry(newInfoId(),"Example info bar message");
    info_entry.setCustomButtonInfo("Custom Button",this,SLOT(handleInfoBarCustomButton()));
    d->info_bar.addInfo(info_entry);
}

void ExampleWidget::handleInfoBarCancelButton() {
    qDebug() << Q_FUNC_INFO;
}

void ExampleWidget::handleInfoBarCustomButton() {
    qDebug() << Q_FUNC_INFO;
    QMessageBox msgbox;
    msgbox.setText("Custom button pressed");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.exec();
}

QString ExampleWidget::newInfoId() {
    QString new_id = QString("id_%1").arg(d->info_id_count);
    ++d->info_id_count;
    return new_id;
}
