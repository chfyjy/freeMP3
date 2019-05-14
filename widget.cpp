#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedWidth(390);
    setMinimumHeight(800);
    resize(390,860);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowTitle("JYMusicPlayer");
    //
    initControls();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::initControls()
{
    //top
    titleL= new QLabel(this);
    titleL->setFixedHeight(32);
    titleL->setPixmap(QPixmap(":/pic/shitvip.png"));
    minBtn = new QPushButton(this);
    minBtn->setIcon(QIcon(QPixmap(":/pic/min.png")));
    minBtn->setFixedHeight(32);
    minBtn->setFlat(true);
    closeBtn = new QPushButton(this);
    closeBtn->setIcon(QIcon(QPixmap(":/pic/close.png")));
    closeBtn->setFixedHeight(32);
    closeBtn->setFlat(true);
    QHBoxLayout *topleftLayout = new QHBoxLayout;
    topleftLayout->addWidget(titleL);
    topleftLayout->setAlignment(Qt::AlignLeft);
    QHBoxLayout *toprightLayout = new QHBoxLayout;
    toprightLayout->addWidget(minBtn);
    toprightLayout->addWidget(closeBtn);
    toprightLayout->setAlignment(Qt::AlignRight);
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addLayout(topleftLayout);
    topLayout->addLayout(toprightLayout);

    QVBoxLayout *allLayout = new QVBoxLayout;
    allLayout->addLayout(topLayout);
    setLayout(allLayout);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    mMovePosition = event->globalPos() - pos();
    return QWidget::mousePressEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
            && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
        {
            move(event->globalPos()-mMovePosition);
            mMovePosition = event->globalPos() - pos();
        }
        return QWidget::mouseMoveEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}
