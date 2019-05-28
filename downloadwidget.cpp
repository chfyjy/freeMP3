#include "downloadwidget.h"
#include "ui_downloadwidget.h"

DownloadWidget::DownloadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadWidget)
{
    ui->setupUi(this);
}

DownloadWidget::~DownloadWidget()
{
    delete ui;
}
