#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>



class MyTable:public QTableWidget {
    
  public:
    MyTable(int x,int y,QWidget  *parent = 0);
   
    private slots:
 
   public:
int x,y;
};

MyTable::MyTable(int x,int y,QWidget  *parent)
    : QTableWidget (parent) {
    this->x=x;
    this->y=y;
    
    } 

class Writer:public QMainWindow {
    
  public:
    Writer(QWidget  *parent = 0);
    
   
  
    
    
};


Writer::Writer(QWidget  *parent)
    : QMainWindow (parent) {
    
 
   
    MyTable *form_widget=new MyTable(10,5);
     
    this->setCentralWidget(form_widget);
    
    this->setWindowTitle("Text edit");
    this->show();
    } 






int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
   Writer table;
  

  
  return app.exec();
  
}
