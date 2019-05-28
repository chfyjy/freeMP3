#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initWidget();
    initControls();
    initStyleSheet();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initWidget()
{
    setObjectName("Widget");
    QRect screenRect = QApplication::desktop()->screenGeometry();
    setFixedWidth(screenRect.width()/10*2);
    setMinimumHeight(screenRect.height()/10*8);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowTitle("JYMusicPlayer");
}

void Widget::initStyleSheet()
{
    QFile file(":/qss/default.qss");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void Widget::initControls()
{
    //top
    titleL= new QLabel(this);
    titleL->setObjectName("titleL");
    minBtn = new QPushButton(this);
    minBtn->setObjectName("minBtn");
    connect(minBtn, SIGNAL(clicked()), SLOT(do_minBtn_clicked()));
    closeBtn = new QPushButton(this);
    closeBtn->setObjectName("closeBtn");
    connect(closeBtn, SIGNAL(clicked()), SLOT(do_closeBtn_clicked()));
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

    audioui = new AudioWidget(this);
    mvui = new MVWidget(this);
    downloadui = new DownloadWidget(this);

    mainTab = new QTabWidget(this);
    mainTab->setObjectName("mainTab");
    mainTab->insertTab(0, audioui,"");
    mainTab->insertTab(1, mvui,"");
    mainTab->insertTab(2, downloadui,"");

    QVBoxLayout *allLayout = new QVBoxLayout;
    allLayout->addLayout(topLayout);
    allLayout->addWidget(mainTab);
    allLayout->setMargin(0);
    setLayout(allLayout);
}

void Widget::do_minBtn_clicked()
{
    if(isMinimized())
        showNormal();
    else
        showMinimized();
}

void Widget::do_closeBtn_clicked()
{
    close();
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
