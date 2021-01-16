#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include <QCheckBox>
#include<iostream>
#include <QPushButton>
#include <QApplication>

class Click : public QWidget {
    
  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick(bool,QLabel*);
    

  private:
    QLabel *l1;
    QCheckBox *chb;
    QPushButton *b1;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {
    this->l1=new QLabel();
    this->chb=new QCheckBox();
    this->b1 = new QPushButton("Push me");
    
    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(this->l1);
    layout->addWidget(this->chb);
    layout->addWidget(this->b1);
    
    this->setLayout(layout);
    
    connect(b1, &QPushButton::clicked,this,
               [=](){this->onClick(this->chb->isChecked(),this->l1);});
    
    
    this->setWindowTitle("Disconnect");
    this->show();
    }    
    
    
void Click::onClick(bool b,QLabel *l) {
   if(b){
   l->setText("I gues you like dogs");
   }else
   l->setText("Dog haiter");
    
  
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
    
    
    
    
    
    
