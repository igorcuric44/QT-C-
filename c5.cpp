#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>
#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QtGui>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>

class Disconnect : public QWidget {
    
  

  public:
    Disconnect(QWidget *parent = 0);

  private slots:
    void onClick();
    

  private:
    QPushButton *clickBtn;
};

Disconnect::Disconnect(QWidget *parent)
    : QWidget(parent) {
        
  QHBoxLayout *hbox = new QHBoxLayout(this);
  hbox->setSpacing(5);        
        
  clickBtn = new QPushButton("Click", this);
  hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

 

  connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
 
}

void Disconnect::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Disconnect window;
  
  window.resize(250, 150);
  window.setWindowTitle("Disconnect");
  window.show();
  
  return app.exec();
}

