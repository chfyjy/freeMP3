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
    Ui::Widget *ui;
    AudioWidget *audioui;
    DownloadWidget *downloadui;
    MVWidget *mvui;

    //top
    QLabel *titleL;
    QPushButton *minBtn, *closeBtn;
    QTabWidget* mainTab;//mp3 mv 下载


    //for mouse event
    bool		mMoveing;
    QPoint	    mMovePosition;
};

#endif // WIDGET_H
