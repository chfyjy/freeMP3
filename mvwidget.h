#ifndef MVWIDGET_H
#define MVWIDGET_H

#include <QWidget>

namespace Ui {
class MVWidget;
}

class MVWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MVWidget(QWidget *parent = nullptr);
    ~MVWidget();

private:
    Ui::MVWidget *ui;
};

#endif // MVWIDGET_H
