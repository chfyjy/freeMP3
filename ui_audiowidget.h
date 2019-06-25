/********************************************************************************
** Form generated from reading UI file 'audiowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOWIDGET_H
#define UI_AUDIOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioWidget
{
public:

    void setupUi(QWidget *AudioWidget)
    {
        if (AudioWidget->objectName().isEmpty())
            AudioWidget->setObjectName(QString::fromUtf8("AudioWidget"));
        AudioWidget->resize(400, 300);

        retranslateUi(AudioWidget);

        QMetaObject::connectSlotsByName(AudioWidget);
    } // setupUi

    void retranslateUi(QWidget *AudioWidget)
    {
        AudioWidget->setWindowTitle(QApplication::translate("AudioWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioWidget: public Ui_AudioWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOWIDGET_H
