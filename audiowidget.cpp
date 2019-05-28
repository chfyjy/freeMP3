#include "audiowidget.h"
#include "ui_audiowidget.h"

AudioWidget::AudioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioWidget)
{
    ui->setupUi(this);
}

AudioWidget::~AudioWidget()
{
    delete ui;
}
