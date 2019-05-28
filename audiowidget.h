#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>

namespace Ui {
class AudioWidget;
}

class AudioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AudioWidget(QWidget *parent = nullptr);
    ~AudioWidget();

private:
    Ui::AudioWidget *ui;
};

#endif // AUDIOWIDGET_H
