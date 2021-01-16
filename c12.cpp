#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QObject>
#include <QString>
#include <QSlider>
#include <Qt>

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick(QPushButton*,QString);
    

  private:
    QPushButton *b1;
    QPushButton *b2;
    QLineEdit *le;
    QSlider *s;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {        
   
  this->le=new QLineEdit();     
  b1 = new QPushButton("Clear");
  b2=new QPushButton("Print");
  s=new QSlider(Qt::Horizontal);
  s->setMinimum(1);
		s->setMaximum(100);
		s->setValue(25);
		s->setTickInterval(10);
		s->setTickPosition(QSlider::TicksBelow);
  
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(this->le);
  v_box->addWidget(b1);
  v_box->addWidget(b2);
  v_box->addWidget(s);
  
  this->setLayout(v_box);

  //connect(b1, &QPushButton::clicked, this, &Click::onClick);
 //connect(b2, &QPushButton::clicked, this, &Click::onClick);
 connect(b1, &QPushButton::clicked,this,
               [=]() { this->onClick(b1,"pas trop mal, et vous?"); });
 connect(b2, &QPushButton::clicked,this,
               [=]() { this->onClick(b2,"hop vous?"); });
 
 this->resize(250, 150);
  this->setWindowTitle("Disconnect");
  this->show();
 
}

void Click::onClick(QPushButton* b,QString text) {
    
  QTextStream out(stdout);
  out << text << endl;
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if(b->text()=="Print")
  	out << this->le->text() << endl;
  else
  	this->le->clear();
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
