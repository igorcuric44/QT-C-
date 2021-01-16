#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w0;
    w0.show();

    QWidget *w = new QWidget(&w0, Qt::Window);
    w->show();
    w->resize(200,200);
    w->raise();

    return  a.exec();
}

