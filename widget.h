#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QProgressBar>
#include <QComboBox>

#include "audiowidget.h"
#include "mvwidget.h"
#include "downloadwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    void initWidget();
    void initControls();
    void initStyleSheet();


private slots:
    void do_minBtn_clicked();
    void do_closeBtn_clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void hideTimeInfo();

private:
    Ui::Widget *ui;

    //top
    QLabel *titleL;
    QPushButton *minBtn, *closeBtn;
    //middle
    QTabWidget* mainTab;//mp3 mv 下载
    AudioWidget *audioui;
    DownloadWidget *downloadui;
    MVWidget *mvui;
    //bottom
    QLabel *curtimeL, *alltimeL;
    QProgressBar *playtimePB;

    //footer
    QComboBox *modelCB;
    QPushButton *prevBtn, *playBtn, *nextBtn, *pauseBtn;


    //for mouse event
    bool		mMoveing;
    QPoint	    mMovePosition;
};

#endif // WIDGET_H
