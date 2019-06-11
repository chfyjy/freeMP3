#ifndef COMMON_H
#define COMMON_H


#include <QWidget>
#include <QLayout>
#include <QMouseEvent>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QProgressBar>
#include <QComboBox>

#define NOWISDEBUG 1
#if NOWISDEBUG
#include <QDebug>
#define DEBUGOUT(outstr)  qDebug() << (outstr)
#else
#define DEBUGOUT(outstr)
#endif

#endif // COMMON_H
