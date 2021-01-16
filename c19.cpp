#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTextStream>
#include<QLabel>
#include<QCheckBox>
#include<QPushButton>
#include<QApplication>
#include<QTextEdit>
#include<iostream>
#include<QFile>
#include<QFileDialog>
#include<QDebug>
#include<QByteArray>

class Notepad : public QWidget {
    
  public:
    Notepad(QWidget *parent = 0);

  private slots:
  void onClick1();
   void onClick2(); 
   void onClick3();

  private:
    QTextEdit *te;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
};

Notepad::Notepad(QWidget *parent)
    : QWidget(parent) {
    this->te=new QTextEdit();
    this->b1 = new QPushButton("Clear");
    this->b2 = new QPushButton("Save");
    this->b3 = new QPushButton("Open");
    
    QVBoxLayout *v_layout=new QVBoxLayout();
    QHBoxLayout *h_layout=new QHBoxLayout();

    v_layout->addWidget(this->te);
    h_layout->addWidget(this->b1);
    h_layout->addWidget(this->b2);
    h_layout->addWidget(this->b3);
    v_layout->addLayout(h_layout);
    
    this->setLayout(v_layout);
    
   connect(b2, &QPushButton::clicked,this,
               &Notepad::onClick1);
   
   connect(b1, &QPushButton::clicked,this,
               &Notepad::onClick2);
               
    connect(b3, &QPushButton::clicked,this,
               &Notepad::onClick3);
    
    this->setWindowTitle("Text edit");
    this->show();
    }  
    
    void Notepad::onClick1()
    {
    std::cout<<" stisnio"<<std::endl;
    QString str=QFileDialog::getSaveFileName(0,"Save file",QDir::currentPath());
    QFile file(str);
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
  
  void Notepad::onClick3()
    {
    std::cout<<" stisnio3"<<std::endl;
    QString filename =  QFileDialog::getOpenFileName(
          this,"Open Document",QDir::currentPath());
    qDebug()<<filename.toUtf8();
    QTextStream out(stdout);
    out<<filename.toUtf8()<<endl;
    QFile file(filename);
    file.open(QIODevice::ReadOnly );
	
QTextStream stream(&file);
QString line;


    line=stream.readAll();

this->te->setText(line);
file.close();

    
    }
  
    
 int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Notepad window;
  

  
  return app.exec();
}   
