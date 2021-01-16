#include<QVBoxLayout>
#include<QTextStream>
#include<QLabel>
#include<QCheckBox>
#include<QPushButton>
#include<QApplication>
#include<QTextEdit>
#include<iostream>
#include<QFile>


class Notepad : public QWidget {
    
  public:
    Notepad(QWidget *parent = 0);

  private slots:
  void onClick1();
   void onClick2(); 

  private:
    QTextEdit *te;
    QPushButton *b1;
    QPushButton *b2;
};

Notepad::Notepad(QWidget *parent)
    : QWidget(parent) {
    this->te=new QTextEdit();
    this->b1 = new QPushButton("Save");
    this->b2 = new QPushButton("Clear");
    
    QVBoxLayout *layout=new QVBoxLayout();

    layout->addWidget(this->te);
    layout->addWidget(this->b1);
    layout->addWidget(this->b2);
    
    this->setLayout(layout);
    
   connect(b1, &QPushButton::clicked,this,
               &Notepad::onClick1);
   
   connect(b2, &QPushButton::clicked,this,
               &Notepad::onClick2);
    
    this->setWindowTitle("Text edit");
    this->show();
    }  
    
    void Notepad::onClick1()
    {
    std::cout<<" stisnio"<<std::endl;
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    QString data=this->te->toPlainText();
    out<<data;
    file.close();
    }
    
    void Notepad::onClick2()
    {
    std::cout<<" stisnio2"<<std::endl;
    this->te->clear();
    }
    
 int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Notepad window;
  

  
  return app.exec();
}   
