#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>



int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget *window=new QWidget;
window->setWindowTitle("example title");
    window->resize(350, 250);
   
   QHBoxLayout *h_box=new QHBoxLayout;
    
    QPushButton *button=new QPushButton;
    

     QLabel *label=new QLabel;
    button->setText("stisni");
    label->setText("pritisni");
  
h_box->addStretch();
    h_box->addWidget(label);
 h_box->addStretch();
QVBoxLayout *v_box=new QVBoxLayout;
 
    v_box->addWidget(button);
    v_box->addLayout(h_box);
    window->setLayout(v_box);
    window->show();

    return app.exec();
}
