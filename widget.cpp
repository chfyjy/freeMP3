#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mMoveing = false;
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
    setWindowFlags(Qt::FramelessWindowHint);
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

    //middle
    audioui = new AudioWidget(this);
    mvui = new MVWidget(this);
    downloadui = new DownloadWidget(this);

    mainTab = new QTabWidget(this);
    mainTab->setObjectName("mainTab");
    mainTab->insertTab(0, audioui,"");
    mainTab->insertTab(1, mvui,"");
    mainTab->insertTab(2, downloadui,"");
    mainTab->setCurrentIndex(0);

    //bottom
    curtimeL = new QLabel(this);
    curtimeL->setObjectName("curtimeL");
    alltimeL = new QLabel(this);
    alltimeL->setObjectName("alltimeL");
    playtimePB = new QProgressBar(this);
    playtimePB->setObjectName("playtimePB");
    hideTimeInfo(true);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(curtimeL);
    bottomLayout->addWidget(playtimePB);
    bottomLayout->addWidget(alltimeL);
    bottomLayout->setAlignment(Qt::AlignCenter);

    //footer
    modelCB = new QComboBox(this);
    modelCB->setObjectName("modelCB");
    modelCB->setEditable(false);
    modelCB->showPopup();
    modelCB->addItem(QIcon(":/pic/orderplay.png"),QObject::tr("列表循环"));
    modelCB->addItem(QIcon(":/pic/onecircle.png"),QObject::tr("单曲循环"));
    modelCB->addItem(QIcon(":/pic/randplay.png"), QObject::tr("随机播放"));

    QHBoxLayout *footerLayout1 = new QHBoxLayout;
    prevBtn = new QPushButton(this);
    prevBtn->setObjectName("prevBtn");
    playBtn = new QPushButton(this);
    playBtn->setObjectName("playBtn");
    connect(playBtn, SIGNAL(clicked()), SLOT(do_playBtn_clicked()));
    nextBtn = new QPushButton(this);
    nextBtn->setObjectName("nextBtn");
    pauseBtn = new QPushButton(this);
    pauseBtn->setObjectName("pauseBtn");
    connect(pauseBtn, SIGNAL(clicked()), SLOT(do_pauseBtn_clicked()));
    pauseBtn->setHidden(true);
    footerLayout1->addWidget(prevBtn);
    footerLayout1->addWidget(playBtn);
    footerLayout1->addWidget(pauseBtn);
    footerLayout1->addWidget(nextBtn);


    QHBoxLayout *footerLayout = new QHBoxLayout;
    footerLayout->addWidget(modelCB);
    footerLayout->addLayout(footerLayout1);
    footerLayout->setStretch(0, 4);
    footerLayout->setStretch(1, 7);

    //all
    QVBoxLayout *allLayout = new QVBoxLayout;
    allLayout->addLayout(topLayout);
    allLayout->addWidget(mainTab);
    allLayout->addLayout(bottomLayout);
    allLayout->addLayout(footerLayout);
    allLayout->setMargin(10);
    setLayout(allLayout);
}

void Widget::hideTimeInfo(bool hideflag)
{
    playtimePB->setHidden(hideflag);
    alltimeL->setHidden(hideflag);
    curtimeL->setHidden(hideflag);
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
void Widget::do_pauseBtn_clicked()
{
    pauseBtn->setHidden(true);
    playBtn->setVisible(true);
}

void Widget::do_playBtn_clicked()
{
    playBtn->setHidden(true);
    pauseBtn->setVisible(true);
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
    Q_UNUSED(event);
    mMoveing = false;
}
