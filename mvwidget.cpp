#include "mvwidget.h"
#include "ui_mvwidget.h"

MVWidget::MVWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MVWidget)
{
    ui->setupUi(this);
}

MVWidget::~MVWidget()
{
    delete ui;
}
