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

class prozor1;

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);
prozor1 *wdg;
  private slots:
    void onClick();
    

  private:
    QPushButton *b;
    QLabel *l;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {        
        
  b = new QPushButton("Push me");
  l=new QLabel("I have not be clicked");

  QHBoxLayout *h_box = new QHBoxLayout();
  h_box->setSpacing(5);
  
  h_box->addStretch();
  h_box->addWidget(l);
  h_box->addStretch();
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(b);
  v_box->addLayout(h_box);
  
  this->setLayout(v_box);

  connect(b, &QPushButton::clicked, this, &Click::onClick);
 
 this->resize(250, 150);
  this->setWindowTitle("Disconnect");
  this->show();
 
}

class prozor1 : public QWidget {
    
  

  public:
    prozor1(QWidget *parent = 0);
private slots:
   
    

  private:
   

  
    
};

prozor1::prozor1(QWidget *parent)
    : QWidget(parent) { 


resize(250, 150);
 setWindowTitle("Proxor1");
  show();
}


void Click::onClick() {
    
 // QTextStream out(stdout);
  //out << "Button clicked" << endl;

  wdg = new prozor1();
}


int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  //prozor1 w;
  

  
  return app.exec();
}

