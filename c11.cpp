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

class Click : public QWidget {
    
  

  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick();
    

  private:
    QPushButton *b1;
    QPushButton *b2;
    QLineEdit *le;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {        
   
  le=new QLineEdit();     
  b1 = new QPushButton("Clear");
  b2=new QPushButton("Print");
  

  
  
  QVBoxLayout *v_box=new QVBoxLayout();
  
  v_box->addWidget(le);
  v_box->addWidget(b1);
  v_box->addWidget(b2);
  
  this->setLayout(v_box);

  connect(b1, &QPushButton::clicked, this, &Click::onClick);
 connect(b2, &QPushButton::clicked, this, &Click::onClick);
 this->resize(250, 150);
  this->setWindowTitle("Disconnect");
  this->show();
 
}

void Click::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  if(button->text()=="Print")
  	out << this->le->text() << endl;
  else
  	this->le->clear();
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
