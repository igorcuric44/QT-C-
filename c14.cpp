#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include <QCheckBox>
#include<QRadioButton>
#include <QPushButton>
#include <QApplication>

class Click : public QWidget {
    
  public:
    Click(QWidget *parent = 0);

  private slots:
    void onClick(bool,QLabel*);
    

  private:
    QLabel *l1;
    QRadioButton *rb1,*rb2;
    QPushButton *b1;
};

Click::Click(QWidget *parent)
    : QWidget(parent) {
    this->l1=new QLabel();
    this->rb1=new QRadioButton("dogs");
    this->rb2=new QRadioButton("cats");
    this->b1 = new QPushButton("Push me");
    
    QVBoxLayout *layout=new QVBoxLayout();
    layout->addWidget(this->l1);
    layout->addWidget(this->rb1);
    layout->addWidget(this->rb2);
    layout->addWidget(this->b1);
    
    this->setLayout(layout);
    
    connect(b1, &QPushButton::clicked,this,
               [=](){this->onClick(this->rb1->isChecked(),this->l1);});
    
    
    this->setWindowTitle("Radio button");
    this->show();
    }    
    
    
void Click::onClick(bool b,QLabel *l) {
   if(b){
   l->setText("I gues you like dogs");
   }else
   l->setText("I gues you like cats");
    
  
}

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  

  
  return app.exec();
}
