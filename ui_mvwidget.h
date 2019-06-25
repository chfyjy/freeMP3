/********************************************************************************
** Form generated from reading UI file 'mvwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MVWIDGET_H
#define UI_MVWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MVWidget
{
public:

    void setupUi(QWidget *MVWidget)
    {
        if (MVWidget->objectName().isEmpty())
            MVWidget->setObjectName(QString::fromUtf8("MVWidget"));
        MVWidget->resize(400, 300);

        retranslateUi(MVWidget);

        QMetaObject::connectSlotsByName(MVWidget);
    } // setupUi

    void retranslateUi(QWidget *MVWidget)
    {
        MVWidget->setWindowTitle(QApplication::translate("MVWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MVWidget: public Ui_MVWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MVWIDGET_H
