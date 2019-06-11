#include "audiowidget.h"
#include "ui_audiowidget.h"

AudioWidget::AudioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioWidget)
{
    ui->setupUi(this);
    initControls();
}

AudioWidget::~AudioWidget()
{
    delete ui;
}

void AudioWidget::initControls()
{
    importBtn = new QPushButton(this);
    importBtn->setObjectName("importBtn");

    QVBoxLayout* allLayout = new QVBoxLayout;
    allLayout->addWidget(importBtn);
    connect(importBtn, SIGNAL(clicked()), SLOT(do_importBtn_clicked()));
    setLayout(allLayout);
}


void AudioWidget::do_importBtn_clicked()
{
     QString directory = QFileDialog::getExistingDirectory(this, QObject::tr("选择音频文件所在文件夹"));
     DEBUGOUT(directory);
    //QFileDialog
}
