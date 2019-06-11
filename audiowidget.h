#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include "common.h"

namespace Ui {
class AudioWidget;
}

class AudioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioWidget(QWidget *parent = nullptr);
    ~AudioWidget();

private slots:
    void do_importBtn_clicked();

private:
    void initControls();

private:
    Ui::AudioWidget *ui;
    QPushButton *importBtn;

};

#endif // AUDIOWIDGET_H
