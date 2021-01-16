#include<QVBoxLayout>
#include<QTextStream>
#include<QLabel>
#include<QCheckBox>
#include<QPushButton>
#include<QApplication>
#include<QTextEdit>

class Notepad : public QWidget {
    
  public:
    Notepad(QWidget *parent = 0);

  private slots:
   // void onClick(bool,QLabel*);
    

  private:
    QTextEdit *te;
    QPushButton *b1;
};

Notepad::Notepad(QWidget *parent)
    : QWidget(parent) {
    this->te=new QTextEdit();
    this->b1 = new QPushButton("Push me");
    
    QVBoxLayout *layout=new QVBoxLayout();

    layout->addWidget(this->te);
    layout->addWidget(this->b1);
    
    this->setLayout(layout);
    
   
    
    this->setWindowTitle("Text edit");
    this->show();
    }  
    
 int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Notepad window;
  

  
  return app.exec();
}   
   
